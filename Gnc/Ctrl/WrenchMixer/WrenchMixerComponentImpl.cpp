// ======================================================================
// \title  WrenchMixerImpl.cpp
// \author mereweth
// \brief  cpp file for WrenchMixer component implementation class
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


#include <Gnc/Ctrl/WrenchMixer/WrenchMixerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

#include <stdio.h>

#ifdef BUILD_DSPAL
#include <HAP_farf.h>
#define DEBUG_PRINT(x,...) FARF(ALWAYS,x,##__VA_ARGS__);
#else
#include <stdio.h>
#define DEBUG_PRINT(x,...) printf(x,##__VA_ARGS__); fflush(stdout)
#endif

//#undef DEBUG_PRINT
//#define DEBUG_PRINT(x,...)

namespace Gnc {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  WrenchMixerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    WrenchMixerComponentImpl(
        const char *const compName
    ) :
      WrenchMixerComponentBase(compName),
#else
    WrenchMixerImpl(void) :
      WrenchMixerImpl(void),
#endif
      wrenchMixer(),
      paramsInited(false),
      numRotors(0u),
      angVelTlm()
  {

  }

  void WrenchMixerComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    WrenchMixerComponentBase::init(instance);
  }

  WrenchMixerComponentImpl ::
    ~WrenchMixerComponentImpl(void)
  {

  }

  void WrenchMixerComponentImpl ::
    parameterUpdated(FwPrmIdType id)
  {
#ifndef BUILD_TIR5
    printf("prm %d updated\n", id);
#endif
  }

  void WrenchMixerComponentImpl ::
    parametersLoaded()
  {
      this->paramsInited = false;
      Fw::ParamValid valid[6];
      this->numRotors = paramGet_numRotors(valid[0]);
      if (Fw::PARAM_VALID != valid[0]) {  return;  }
      if (this->numRotors > quest_gnc::multirotor::kWrenchMixerMaxActuators) {  return;  }
      quest_gnc::multirotor::WrenchMixer::MixMatrix mixer;

      // TODO(mereweth) - macro-ize the param get calls?
      for (U32 i = 0; i < this->numRotors; i++) {
          switch (i) {
              case 0:
                  mixer.col(i) << paramGet_t_x__1(valid[0]),
                                  paramGet_t_y__1(valid[1]),
                                  paramGet_t_z__1(valid[2]),
                                  paramGet_m_x__1(valid[3]),
                                  paramGet_m_y__1(valid[4]),
                                  paramGet_m_z__1(valid[5]);
                  break;
              case 1:
                  mixer.col(i) << paramGet_t_x__2(valid[0]),
                                  paramGet_t_y__2(valid[1]),
                                  paramGet_t_z__2(valid[2]),
                                  paramGet_m_x__2(valid[3]),
                                  paramGet_m_y__2(valid[4]),
                                  paramGet_m_z__2(valid[5]);
                  break;
              case 2:
                  mixer.col(i) << paramGet_t_x__3(valid[0]),
                                  paramGet_t_y__3(valid[1]),
                                  paramGet_t_z__3(valid[2]),
                                  paramGet_m_x__3(valid[3]),
                                  paramGet_m_y__3(valid[4]),
                                  paramGet_m_z__3(valid[5]);
                  break;
              case 3:
                  mixer.col(i) << paramGet_t_x__4(valid[0]),
                                  paramGet_t_y__4(valid[1]),
                                  paramGet_t_z__4(valid[2]),
                                  paramGet_m_x__4(valid[3]),
                                  paramGet_m_y__4(valid[4]),
                                  paramGet_m_z__4(valid[5]);
                  break;
              case 4:
                  mixer.col(i) << paramGet_t_x__5(valid[0]),
                                  paramGet_t_y__5(valid[1]),
                                  paramGet_t_z__5(valid[2]),
                                  paramGet_m_x__5(valid[3]),
                                  paramGet_m_y__5(valid[4]),
                                  paramGet_m_z__5(valid[5]);
                  break;
              case 5:
                  mixer.col(i) << paramGet_t_x__6(valid[0]),
                                  paramGet_t_y__6(valid[1]),
                                  paramGet_t_z__6(valid[2]),
                                  paramGet_m_x__6(valid[3]),
                                  paramGet_m_y__6(valid[4]),
                                  paramGet_m_z__6(valid[5]);
                  break;
              case 6:
                  mixer.col(i) << paramGet_t_x__7(valid[0]),
                                  paramGet_t_y__7(valid[1]),
                                  paramGet_t_z__7(valid[2]),
                                  paramGet_m_x__7(valid[3]),
                                  paramGet_m_y__7(valid[4]),
                                  paramGet_m_z__7(valid[5]);
                  break;
              case 7:
                  mixer.col(i) << paramGet_t_x__8(valid[0]),
                                  paramGet_t_y__8(valid[1]),
                                  paramGet_t_z__8(valid[2]),
                                  paramGet_m_x__8(valid[3]),
                                  paramGet_m_y__8(valid[4]),
                                  paramGet_m_z__8(valid[5]);
                  break;
              default:
                  FW_ASSERT(0, i);
          }

          for (U32 j = 0; j < 5; j++) {
              if (Fw::PARAM_VALID != valid[j]) {  return;  }
          }
      }

      (void) wrenchMixer.SetMixer(mixer, this->numRotors);

      this->paramsInited = true;
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void WrenchMixerComponentImpl ::
    prmTrigger_handler(
        const NATIVE_INT_TYPE portNum,
        FwPrmIdType dummy
    )
  {
      this->loadParameters();
  }

  void WrenchMixerComponentImpl ::
    controls_handler(
        const NATIVE_INT_TYPE portNum,
        ROS::geometry_msgs::WrenchStamped &WrenchStamped
    )
  {
      if (!paramsInited) {
          return;
      }

      using ROS::geometry_msgs::Vector3;

      Vector3 moment_b = WrenchStamped.getwrench().gettorque();
      Vector3 force_b = WrenchStamped.getwrench().getforce();

      this->wrenchMixer.SetWrenchDes(Eigen::Vector3d(
                                            force_b.getx(),
                                            force_b.gety(),
                                            force_b.getz()),
                                     Eigen::Vector3d(
                                            moment_b.getx(),
                                            moment_b.gety(),
                                            moment_b.getz()));
      quest_gnc::multirotor::WrenchMixer::MixOutput rotorVel;
      this->wrenchMixer.GetRotorVelCommand(&rotorVel);

      FW_ASSERT(quest_gnc::multirotor::kWrenchMixerMaxActuators >= this->numRotors, this->numRotors);
      F64 angVel[quest_gnc::multirotor::kWrenchMixerMaxActuators] = { 0.0 };
      F64 angles[0], normalized[0];
      for (U32 i = 0; i < this->numRotors; i ++) {
          angVel[i] = rotorVel(i);
          angVelTlm[i] = rotorVel(i);
      }

      ROS::std_msgs::Header h = WrenchStamped.getheader();
      ROS::mav_msgs::Actuators rotorVel__comm(h,
                                              angles, 0, 0,
                                              angVel, quest_gnc::multirotor::kWrenchMixerMaxActuators, this->numRotors,
                                              normalized, 0, 0);
      if (this->isConnected_motor_OutputPort(0)) {
          this->motor_out(0, rotorVel__comm);
      }
  }

  void WrenchMixerComponentImpl ::
    sched_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
      COMPILE_TIME_ASSERT(quest_gnc::multirotor::kWrenchMixerMaxActuators >= 8, BM_MAX_ACT_VS_TLM);
      this->tlmWrite_WMIX_Rot0(angVelTlm[0]);
      this->tlmWrite_WMIX_Rot1(angVelTlm[1]);
      this->tlmWrite_WMIX_Rot2(angVelTlm[2]);
      this->tlmWrite_WMIX_Rot3(angVelTlm[3]);
      this->tlmWrite_WMIX_Rot4(angVelTlm[4]);
      this->tlmWrite_WMIX_Rot5(angVelTlm[5]);
      this->tlmWrite_WMIX_Rot6(angVelTlm[6]);
      this->tlmWrite_WMIX_Rot7(angVelTlm[7]);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void WrenchMixerComponentImpl ::
    WMIX_InitParams_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
      this->parametersLoaded();
      if (this->paramsInited) {
          this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
      }
      else {
          this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_EXECUTION_ERROR);
      }
  }


} // end namespace Gnc
