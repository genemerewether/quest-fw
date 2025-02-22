// ======================================================================
// \title  LeeCtrlImpl.hpp
// \author mereweth
// \brief  hpp file for LeeCtrl component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================

#ifndef LeeCtrl_HPP
#define LeeCtrl_HPP

#include "Gnc/Ctrl/LeeCtrl/LeeCtrlComponentAc.hpp"
#include <Gnc/Ctrl/LeeCtrl/LeeCtrlComponentImplCfg.hpp>

#include "quest_gnc/ctrl/lee_control.h"
#include "quest_gnc/utils/multirotor_model.h"
#include "quest_gnc/utils/world_params.h"

namespace Gnc {

  class LeeCtrlComponentImpl :
    public LeeCtrlComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object LeeCtrl
      //!
      LeeCtrlComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object LeeCtrl
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object LeeCtrl
      //!
      ~LeeCtrlComponentImpl(void);

      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    PRIVATE:
      void parameterUpdated(FwPrmIdType id /*!< The parameter ID*/);
    
      void parametersLoaded();

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for prmTrigger
      //!
      void prmTrigger_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwPrmIdType dummy 
      );

      //! Handler implementation for odometry
      //!
      void odometry_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          ROS::nav_msgs::OdometryAccel &Odometry
      );

      //! Handler implementation for flatOutput
      //!
      void flatOutput_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          ROS::mav_msgs::FlatOutput &FlatOutput
      );

      //! Handler implementation for attThrust
      //!
      void attRateThrust_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          ROS::mav_msgs::AttitudeRateThrust &AttitudeRateThrust
      );

      //! Handler implementation for sched
      //!
      void sched_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );
    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for LCTRL_SetCtrlMode command handler
      //! Set controller mode
      void LCTRL_SetCtrlMode_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          CtrlMode mode 
      );

      //! Implementation for LCTRL_FlatOutputSetpoint command handler
      //! 
      void LCTRL_FlatOutputSetpoint_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F64 x_w__x, 
          F64 x_w__y, 
          F64 x_w__z, 
          F64 v_w__x, 
          F64 v_w__y, 
          F64 v_w__z, 
          F64 yaw 
      );

      //! Implementation for LCTRL_AttThrustSetpoint command handler
      //! 
      void LCTRL_AttThrustSetpoint_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F64 thrust,
          F64 w_q_b__x, 
          F64 w_q_b__y, 
          F64 w_q_b__z,
          F64 w_q_b__w
      );
    
      //! Implementation for LCTRL_InitParams command handler
      //! 
      void LCTRL_InitParams_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      // ----------------------------------------------------------------------
      // Private member variables
      // ----------------------------------------------------------------------

      U32 seq;

      F32 u_tlm[4];

      F32 thrust_x_tlm;
      F32 thrust_y_tlm;

      double mass;

      Eigen::Matrix3d J_b;

      ROS::geometry_msgs::Point x_w;

      ROS::geometry_msgs::Point x_w__des;

      ROS::geometry_msgs::Quaternion w_q_b;

      ROS::geometry_msgs::Quaternion w_q_b__des;

      ROS::geometry_msgs::Vector3 v_b;

      ROS::geometry_msgs::Vector3 v_w__des;

      ROS::geometry_msgs::Vector3 omega_b;

      ROS::geometry_msgs::Vector3 omega_b__des;
    
      ROS::geometry_msgs::Vector3 a_b;
    
      ROS::geometry_msgs::Vector3 a_w__comm;

      ROS::geometry_msgs::Vector3 a_w__des;
    
      ROS::geometry_msgs::Vector3 j_w__des;
    
      ROS::geometry_msgs::Vector3 s_w__des;

      ROS::geometry_msgs::Vector3 thrust_b__des;

      F64 yaw__des;
    
      F64 yawdot__des;

      quest_gnc::multirotor::LeeControl leeControl;

      CtrlMode ctrlMode;

      bool paramsInited;
    };

} // end namespace Gnc

#endif
