// ======================================================================
// \title  TimeSyncOffsetComponentImpl.hpp
// \author kedelson
// \brief  hpp file for TimeSyncOffset component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TimeSyncOffset_HPP
#define TimeSyncOffset_HPP

#include "Svc/TimeSyncOffset/TimeSyncOffsetComponentAc.hpp"

namespace Svc {

  class TimeSyncOffsetComponentImpl :
    public TimeSyncOffsetComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object TimeSyncOffset
      //!
      TimeSyncOffsetComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object TimeSyncOffset
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object TimeSyncOffset
      //!
      ~TimeSyncOffsetComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      //! Handler implementation for LLTime
      //!
      void LLTime_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

    // hold on to trigger time
    Fw::Time HLTime;
    
    // num of sched calls timeout to reset GPIO pin if we never recieve LLTime
    U8 sched_timeout = 2;
    U8 num_sched_calls = 0;

    };

} // end namespace Svc

#endif
