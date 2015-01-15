// This file has been generated by Py++.

#include "boost/python.hpp"
#include "bindings/app.h"
#include "AppBaseGeometric.pypp.hpp"

namespace bp = boost::python;

struct AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper : ompl::app::AppBase< (ompl::app::AppType)0 >, bp::wrapper< ompl::app::AppBase< (ompl::app::AppType)0 > > {

    AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper(::boost::shared_ptr< ompl::base::StateSpace > const & space, ::ompl::app::MotionModel model )
    : ompl::app::AppBase<(ompl::app::AppType)0>( space, model )
      , bp::wrapper< ompl::app::AppBase< (ompl::app::AppType)0 > >(){
        // constructor
    
    }

    virtual ::ompl::base::ScopedState< ompl::base::StateSpace > getDefaultStartState(  ) const {
        bp::override func_getDefaultStartState = this->get_override( "getDefaultStartState" );
        return func_getDefaultStartState(  );
    }

    virtual ::ompl::base::ScopedState< ompl::base::StateSpace > getFullStateFromGeometricComponent( ::ompl::base::ScopedState< ompl::base::StateSpace > const & state ) const {
        bp::override func_getFullStateFromGeometricComponent = this->get_override( "getFullStateFromGeometricComponent" );
        return func_getFullStateFromGeometricComponent( boost::ref(state) );
    }

    virtual ::ompl::base::ScopedState< ompl::base::StateSpace > getGeometricComponentState( ::ompl::base::ScopedState< ompl::base::StateSpace > const & state, unsigned int index ) const  {
        if( bp::override func_getGeometricComponentState = this->get_override( "getGeometricComponentState" ) )
            return func_getGeometricComponentState( boost::ref(state), index );
        else{
            return this->ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentState( boost::ref(state), index );
        }
    }
    
    ::ompl::base::ScopedState< ompl::base::StateSpace > default_getGeometricComponentState( ::ompl::base::ScopedState< ompl::base::StateSpace > const & state, unsigned int index ) const  {
        return ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentState( boost::ref(state), index );
    }

    virtual ::ompl::base::State const * getGeometricComponentStateInternal( ::ompl::base::State const * state, unsigned int index ) const {
        bp::override func_getGeometricComponentStateInternal = this->get_override( "getGeometricComponentStateInternal" );
        return func_getGeometricComponentStateInternal( boost::python::ptr(state), index );
    }

    virtual ::boost::shared_ptr< ompl::base::StateSpace > const & getGeometricComponentStateSpace(  ) const {
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
    }

    virtual unsigned int getRobotCount(  ) const {
        bp::override func_getRobotCount = this->get_override( "getRobotCount" );
        return func_getRobotCount(  );
    }

    virtual void inferEnvironmentBounds(  ) {
        if( bp::override func_inferEnvironmentBounds = this->get_override( "inferEnvironmentBounds" ) )
            func_inferEnvironmentBounds(  );
        else{
            this->ompl::app::AppBase< (ompl::app::AppType)0 >::inferEnvironmentBounds(  );
        }
    }
    
    void default_inferEnvironmentBounds(  ) {
        ompl::app::AppBase< (ompl::app::AppType)0 >::inferEnvironmentBounds( );
    }

    virtual void inferProblemDefinitionBounds(  ) {
        if( bp::override func_inferProblemDefinitionBounds = this->get_override( "inferProblemDefinitionBounds" ) )
            func_inferProblemDefinitionBounds(  );
        else{
            this->ompl::app::AppBase< (ompl::app::AppType)0 >::inferProblemDefinitionBounds(  );
        }
    }
    
    void default_inferProblemDefinitionBounds(  ) {
        ompl::app::AppBase< (ompl::app::AppType)0 >::inferProblemDefinitionBounds( );
    }

    virtual bool isSelfCollisionEnabled(  ) const {
        bp::override func_isSelfCollisionEnabled = this->get_override( "isSelfCollisionEnabled" );
        return func_isSelfCollisionEnabled(  );
    }

    virtual void setup(  ) {
        if( bp::override func_setup = this->get_override( "setup" ) )
            func_setup(  );
        else{
            this->ompl::app::AppBase< (ompl::app::AppType)0 >::setup(  );
        }
    }
    
    void default_setup(  ) {
        ompl::app::AppBase< (ompl::app::AppType)0 >::setup( );
    }

    virtual void clear(  ) {
        if( bp::override func_clear = this->get_override( "clear" ) )
            func_clear(  );
        else{
            this->ompl::geometric::SimpleSetup::clear(  );
        }
    }
    
    void default_clear(  ) {
        ompl::geometric::SimpleSetup::clear( );
    }

    void computeGeometrySpecification(  ){
        ompl::app::RigidBodyGeometry::computeGeometrySpecification(  );
    }

    virtual ::ompl::base::PlannerStatus solve( double time=1.0e+0 ) {
        if( bp::override func_solve = this->get_override( "solve" ) )
            return func_solve( time );
        else{
            return this->ompl::geometric::SimpleSetup::solve( time );
        }
    }
    
    ::ompl::base::PlannerStatus default_solve( double time=1.0e+0 ) {
        return ompl::geometric::SimpleSetup::solve( time );
    }

    virtual ::ompl::base::PlannerStatus solve( ::ompl::base::PlannerTerminationCondition const & ptc ) {
        if( bp::override func_solve = this->get_override( "solve" ) )
            return func_solve( boost::ref(ptc) );
        else{
            return this->ompl::geometric::SimpleSetup::solve( boost::ref(ptc) );
        }
    }
    
    ::ompl::base::PlannerStatus default_solve( ::ompl::base::PlannerTerminationCondition const & ptc ) {
        return ompl::geometric::SimpleSetup::solve( boost::ref(ptc) );
    }

};

void register_AppBaseGeometric_class(){

    { //::ompl::app::AppBase< (ompl::app::AppType)0 >
        typedef bp::class_< AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper, bp::bases< ::ompl::geometric::SimpleSetup, ompl::app::RigidBodyGeometry >, boost::noncopyable > AppBaseGeometric_exposer_t;
        AppBaseGeometric_exposer_t AppBaseGeometric_exposer = AppBaseGeometric_exposer_t( "AppBaseGeometric", bp::init< boost::shared_ptr< ompl::base::StateSpace > const &, ompl::app::MotionModel >(( bp::arg("space"), bp::arg("model") )) );
        bp::scope AppBaseGeometric_scope( AppBaseGeometric_exposer );
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::allocDecomposition
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::boost::shared_ptr< ompl::control::Decomposition > ( exported_class_t::*allocDecomposition_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "allocDecomposition"
                , allocDecomposition_function_type( &::ompl::app::AppBase< (ompl::app::AppType)0 >::allocDecomposition ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getAppType
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::ompl::app::AppType ( exported_class_t::*getAppType_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "getAppType"
                , getAppType_function_type( &::ompl::app::AppBase< (ompl::app::AppType)0 >::getAppType ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getDefaultStartState
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::ompl::base::ScopedState<ompl::base::StateSpace> ( exported_class_t::*getDefaultStartState_function_type)(  ) const;
            
            AppBaseGeometric_exposer.def( 
                "getDefaultStartState"
                , bp::pure_virtual( getDefaultStartState_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::getDefaultStartState) ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getFullStateFromGeometricComponent
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::ompl::base::ScopedState<ompl::base::StateSpace> ( exported_class_t::*getFullStateFromGeometricComponent_function_type)( ::ompl::base::ScopedState<ompl::base::StateSpace> const & ) const;
            
            AppBaseGeometric_exposer.def( 
                "getFullStateFromGeometricComponent"
                , bp::pure_virtual( getFullStateFromGeometricComponent_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::getFullStateFromGeometricComponent) )
                , ( bp::arg("state") ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentState
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::ompl::base::ScopedState< ompl::base::StateSpace > ( exported_class_t::*getGeometricComponentState_function_type)( ::ompl::base::ScopedState< ompl::base::StateSpace > const &,unsigned int ) const;
            typedef ::ompl::base::ScopedState< ompl::base::StateSpace > ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*default_getGeometricComponentState_function_type)( ::ompl::base::ScopedState< ompl::base::StateSpace > const &,unsigned int ) const;
            
            AppBaseGeometric_exposer.def( 
                "getGeometricComponentState"
                , getGeometricComponentState_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentState)
                , default_getGeometricComponentState_function_type(&AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::default_getGeometricComponentState)
                , ( bp::arg("state"), bp::arg("index") ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentStateInternal
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::ompl::base::State const * ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*getGeometricComponentStateInternal_function_type)( ::ompl::base::State const *,unsigned int ) const;
            
            AppBaseGeometric_exposer.def( 
                "getGeometricComponentStateInternal"
                , getGeometricComponentStateInternal_function_type( &AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::getGeometricComponentStateInternal )
                , ( bp::arg("state"), bp::arg("index") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentStateSpace
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::boost::shared_ptr<ompl::base::StateSpace> const & ( exported_class_t::*getGeometricComponentStateSpace_function_type)(  ) const;
            
            AppBaseGeometric_exposer.def( 
                "getGeometricComponentStateSpace"
                , bp::pure_virtual( getGeometricComponentStateSpace_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricComponentStateSpace) )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricStateExtractor
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::boost::function< ompl::base::State const* (ompl::base::State const*, unsigned int) > ( exported_class_t::*getGeometricStateExtractor_function_type)(  ) const;
            
            AppBaseGeometric_exposer.def( 
                "getGeometricStateExtractor"
                , getGeometricStateExtractor_function_type( &::ompl::app::AppBase< (ompl::app::AppType)0 >::getGeometricStateExtractor ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getName
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef ::std::string const & ( exported_class_t::*getName_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "getName"
                , getName_function_type( &::ompl::app::AppBase< (ompl::app::AppType)0 >::getName )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::getRobotCount
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef unsigned int ( exported_class_t::*getRobotCount_function_type)(  ) const;
            
            AppBaseGeometric_exposer.def( 
                "getRobotCount"
                , bp::pure_virtual( getRobotCount_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::getRobotCount) ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::inferEnvironmentBounds
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef void ( exported_class_t::*inferEnvironmentBounds_function_type)(  ) ;
            typedef void ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*default_inferEnvironmentBounds_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "inferEnvironmentBounds"
                , inferEnvironmentBounds_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::inferEnvironmentBounds)
                , default_inferEnvironmentBounds_function_type(&AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::default_inferEnvironmentBounds) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::inferProblemDefinitionBounds
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef void ( exported_class_t::*inferProblemDefinitionBounds_function_type)(  ) ;
            typedef void ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*default_inferProblemDefinitionBounds_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "inferProblemDefinitionBounds"
                , inferProblemDefinitionBounds_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::inferProblemDefinitionBounds)
                , default_inferProblemDefinitionBounds_function_type(&AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::default_inferProblemDefinitionBounds) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::isSelfCollisionEnabled
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef bool ( exported_class_t::*isSelfCollisionEnabled_function_type)(  ) const;
            
            AppBaseGeometric_exposer.def( 
                "isSelfCollisionEnabled"
                , bp::pure_virtual( isSelfCollisionEnabled_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::isSelfCollisionEnabled) ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::setOptimizationObjectiveAndThreshold
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef void ( exported_class_t::*setOptimizationObjectiveAndThreshold_function_type)( ::std::string const &,double ) ;
            
            AppBaseGeometric_exposer.def( 
                "setOptimizationObjectiveAndThreshold"
                , setOptimizationObjectiveAndThreshold_function_type( &::ompl::app::AppBase< (ompl::app::AppType)0 >::setOptimizationObjectiveAndThreshold )
                , ( bp::arg("objective"), bp::arg("threshold") ) );
        
        }
        { //::ompl::app::AppBase< (ompl::app::AppType)0 >::setup
        
            typedef ompl::app::AppBase< (ompl::app::AppType)0 > exported_class_t;
            typedef void ( exported_class_t::*setup_function_type)(  ) ;
            typedef void ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*default_setup_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "setup"
                , setup_function_type(&::ompl::app::AppBase< (ompl::app::AppType)0 >::setup)
                , default_setup_function_type(&AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::default_setup) );
        
        }
        { //::ompl::app::RigidBodyGeometry::computeGeometrySpecification
        
            typedef void ( AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::*computeGeometrySpecification_function_type)(  ) ;
            
            AppBaseGeometric_exposer.def( 
                "computeGeometrySpecification"
                , computeGeometrySpecification_function_type( &AppBase_less___obrace_ompl_scope_app_scope_AppType_cbrace_0__greater__wrapper::computeGeometrySpecification ) );
        
        }
    }

}