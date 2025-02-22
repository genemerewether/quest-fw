// ====================================================================== 
// \title  ImuProcImpl.hpp
// \author mereweth
// \brief  hpp file for ImuProc component implementation class
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

#ifndef ImuProc_HPP
#define ImuProc_HPP

#include "Gnc/Utils/ImuProc/ImuProcComponentAc.hpp"

#include "quest_gnc/utils/filter.h"

namespace Gnc {

  class ImuProcComponentImpl :
    public ImuProcComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ImuProc
      //!
      ImuProcComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ImuProc
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ImuProc
      //!
      ~ImuProcComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for prmTrigger
      //!
      void prmTrigger_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwPrmIdType dummy 
      );

      //! Handler implementation for HighRateImu
      //!
      void HighRateImu_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          ROS::sensor_msgs::ImuNoCov &ImuNoCov 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for IMUPROC_InitParams command handler
      //! 
      void IMUPROC_InitParams_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------
    
      ROS::mav_msgs::BatchImu m_batchImu;

      ROS::sensor_msgs::ImuNoCov m_imuArray[100];

      NATIVE_INT_TYPE batchImuMax;

    };

} // end namespace Gnc

#endif
