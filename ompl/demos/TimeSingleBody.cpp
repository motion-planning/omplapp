/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2010, Rice University
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Rice University nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Elizabeth Fudge */

#include <ompl/base/goals/GoalState.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/base/spaces/DiscreteStateSpace.h>
#include <ompl/base/spaces/TimeStateSpace.h>
#include <ompl/control/spaces/RealVectorControlSpace.h>
#include <ompl/control/SimpleSetup.h>
#include <ompl/config.h>
#include <iostream>
#include <limits>
#include <boost/math/constants/constants.hpp>

namespace ob = ompl::base;
namespace oc = ompl::control;
using namespace std;

void propagate(const oc::SpaceInformation *si, const ob::State *state,
    const oc::Control* control, const double duration, ob::State *result)
{
    static double timeStep = .01;
    int nsteps = ceil(duration / timeStep);
    double dt = duration / nsteps;
    const double *u = control->as<oc::RealVectorControlSpace::ControlType>()->values;

    ob::CompoundStateSpace::StateType& s = *result->as<ob::CompoundStateSpace::StateType>();
    ob::SE2StateSpace::StateType& se2 = *s.as<ob::SE2StateSpace::StateType>(0);
    ob::RealVectorStateSpace::StateType& velocity = *s.as<ob::RealVectorStateSpace::StateType>(1);
    // ob::DiscreteStateSpace::StateType& gear = *s.as<ob::DiscreteStateSpace::StateType>(2);
    ob::TimeStateSpace::StateType& timeSpace = *s.as<ob::TimeStateSpace::StateType>(2);

    si->getStateSpace()->copyState(result, state);
    for(int i = 0; i < nsteps; i++)
    {
        se2.setX(se2.getX() + dt * velocity.values[0] * cos(se2.getYaw()));
        se2.setY(se2.getY() + dt * velocity.values[0] * sin(se2.getYaw()));
        se2.setYaw(se2.getYaw() + dt * u[0]);
        // velocity.values[0] = velocity.values[0] + dt * (u[1]*gear.value);
        velocity.values[0] = velocity.values[0] + dt * u[1];
        timeSpace.position = timeSpace.position + duration;

        // 'guards' - conditions to change gears
        // if (gear.value > 0)
        // {
        //     if (gear.value < 3 && velocity.values[0] > 10*(gear.value + 1))
        //         gear.value++;
        //     else if (gear.value > 1 && velocity.values[0] < 10*gear.value)
        //         gear.value--;
        // }

        if (!si->satisfiesBounds(result))
            return;
    }
}

bool canPropagateBackward ()
{
    return false;
}

// The free space consists of two narrow corridors connected at right angle.
// To make the turn, the car will have to downshift.
bool isStateValid(const oc::SpaceInformation *si, const ob::State *state)
{
    const ob::SE2StateSpace::StateType *se2 = state->as<ob::CompoundState>()->as<ob::SE2StateSpace::StateType>(0);
    const ob::TimeStateSpace::StateType *timeSpace = state->as<ob::CompoundState>()->as<ob::TimeStateSpace::StateType>(2);

    // check that time isnt used in the first x seconds
    // return si->satisfiesBounds(state) && (se2->getX() < -80. || se2->getY() > 80.);

    // check if bounds are satisfied
    if (si->satisfiesBounds(state)) {
        // is it in an occupied time?
        if (timeSpace->position > 30 && timeSpace->position < 70) {
            // check against larger borders
            if ((se2->getX() > -85. && se2->getX() < -15 && se2->getY() > -85. && se2->getY() < -15) ||
                (se2->getX() > -85. && se2->getX() < -15 && se2->getY() > 15. && se2->getY() < 85) ||
                (se2->getX() > 15. && se2->getX() < 85 && se2->getY() > 15. && se2->getY() < 85)) {
                    return false;
            } else {
                return true;
            }
        // not in occupied time
        } else {
            // check against regular borders
            if ((se2->getX() > -80. && se2->getX() < -20 && se2->getY() > -80. && se2->getY() < -20) ||
                (se2->getX() > -80. && se2->getX() < -20 && se2->getY() > 20. && se2->getY() < 80) ||
                (se2->getX() > 20. && se2->getX() < 80 && se2->getY() > 20. && se2->getY() < 80)) {
                return false;
            } else {
                return true;
            }
        } 
    } else {    
        return false;
    }    
}


int main(int, char**)
{
    // plan for hybrid car in SE(2) with discrete gears
    ob::StateSpacePtr SE2(new ob::SE2StateSpace());
    ob::StateSpacePtr velocity(new ob::RealVectorStateSpace(1));
    ob::StateSpacePtr timeSpace(new ob::TimeStateSpace());
    // set the range for gears: [-1,3] inclusive
    // ob::StateSpacePtr gear(new ob::DiscreteStateSpace(-1,3));
    // ob::StateSpacePtr stateSpace = SE2 + velocity + gear;
    ob::StateSpacePtr stateSpace = SE2 + velocity + timeSpace;

    // set the bounds for the R^2 part of SE(2)
    ob::RealVectorBounds bounds(2);
    bounds.setLow(-100);
    bounds.setHigh(100);
    SE2->as<ob::SE2StateSpace>()->setBounds(bounds);

    // set the bounds for the velocity
    ob::RealVectorBounds velocityBound(1);
    velocityBound.setLow(0);
    velocityBound.setHigh(60);
    velocity->as<ob::RealVectorStateSpace>()->setBounds(velocityBound);

    // set the bounds for the time
    // currently not setting bounds, time can go forever
    timeSpace->as<ob::TimeStateSpace>()->setBounds(0., 100.);

    // create start and goal states
    ob::ScopedState<> start(stateSpace);
    ob::ScopedState<> goal(stateSpace);

    // Both start and goal are states with high velocity with the car in third gear.
    // However, to make the turn, the car cannot stay in third gear and will have to
    // shift to first gear.
    start[0] = start[1] = -90.; // position
    start[2] = boost::math::constants::pi<double>() / 2; // orientation
    start[3] = 40.; // velocity
    // start[4] = 0.; // time
    // start->as<ob::CompoundState>()->as<ob::DiscreteStateSpace::StateType>(2)->value = 3; // gear

    goal[0] = goal[1] = 90.; // position
    goal[2] = 0.; // orientation
    goal[3] = 40.; // velocity
    // goal[4] = 5.; // time
    // goal->as<ob::CompoundState>()->as<ob::DiscreteStateSpace::StateType>(2)->value = 3; // gear

    oc::ControlSpacePtr cmanifold(new oc::RealVectorControlSpace(stateSpace, 2));

    // set the bounds for the control manifold
    ob::RealVectorBounds cbounds(2);
    // bounds for steering input
    cbounds.setLow(0, -1.);
    cbounds.setHigh(0, 1.);
    // bounds for brake/gas input
    cbounds.setLow(1, -20.);
    cbounds.setHigh(1, 20.);
    cmanifold->as<oc::RealVectorControlSpace>()->setBounds(cbounds);

    oc::SimpleSetup setup(cmanifold);
    setup.setStartAndGoalStates(start, goal, 5.);
    setup.setStateValidityChecker(boost::bind(&isStateValid, setup.getSpaceInformation().get(), _1));
    setup.setStatePropagator(boost::bind(&propagate, setup.getSpaceInformation().get(), _1, _2, _3, _4));
    setup.getSpaceInformation()->setPropagationStepSize(.1);
    setup.getSpaceInformation()->setMinMaxControlDuration(2, 3);

    // try to solve the problem
    if (setup.solve(30))
    {
        // print the (approximate) solution path: print states along the path
        // and controls required to get from one state to the next
        oc::PathControl& path(setup.getSolutionPath());

        // print out full state on solution path
        // (format: x, y, theta, v, u0, u1, dt)
        cout << "X\tY\tA\tT\tV\tU0\tU1\n";
        for(unsigned int i = 0; i < path.getStateCount(); ++i)
        {
            const ob::State* state = path.getState(i);
            const ob::SE2StateSpace::StateType *se2 = state->as<ob::CompoundState>()->as<ob::SE2StateSpace::StateType>(0);
            const ob::RealVectorStateSpace::StateType *velocity = state->as<ob::CompoundState>()->as<ob::RealVectorStateSpace::StateType>(1);
            // const ob::DiscreteStateSpace::StateType *gear = state->as<ob::CompoundState>()->as<ob::DiscreteStateSpace::StateType>(2);
            const ob::TimeStateSpace::StateType *timeSpace = state->as<ob::CompoundState>()->as<ob::TimeStateSpace::StateType>(2);
            // cout << se2->getX() << ' ' << se2->getY() << ' ' << se2->getYaw() << ' ' << velocity->values[0] << ' ' << gear->value << ' ';
            // cout << se2->getX() << ' ' << se2->getY() << ' ' << se2->getYaw() << ' ' << velocity->values[0] << ' ' << timeSpace->position << ' ';            
            cout << setprecision(2) << se2->getX() << '\t' << se2->getY() << '\t' << se2->getYaw() << '\t' << timeSpace->position << '\t' << velocity->values[0];

            if (i == 0)
                // null controls applied for zero seconds to get to start state
                cout << "0 0 0";
            else
            {
                // print controls and control duration needed to get from state i-1 to state i
                const double* u = path.getControl(i - 1)->as<oc::RealVectorControlSpace::ControlType>()->values;
                cout << u[0] << ' ' << u[1] << ' ' << path.getControlDuration(i - 1);
            }

            cout << endl;
        }

        if (!setup.haveExactSolutionPath())
        {
            cout << "Solution is approximate. Distance to actual goal is " << setup.getProblemDefinition()->getSolutionDifference() << endl;
        }
    }

    return 0;
}
