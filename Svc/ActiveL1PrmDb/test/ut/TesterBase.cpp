// ======================================================================
// \title  ActiveL1PrmDb/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for ActiveL1PrmDb component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
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

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ActiveL1PrmDbTesterBase ::
    ActiveL1PrmDbTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_PrmIdNotFound =
      new History<EventEntry_PrmIdNotFound>(maxHistorySize);
    this->eventHistory_PrmIdUpdated =
      new History<EventEntry_PrmIdUpdated>(maxHistorySize);
    this->eventHistory_PrmDbFull =
      new History<EventEntry_PrmDbFull>(maxHistorySize);
    this->eventHistory_PrmIdAdded =
      new History<EventEntry_PrmIdAdded>(maxHistorySize);
    this->eventHistory_PrmFileWriteError =
      new History<EventEntry_PrmFileWriteError>(maxHistorySize);
    this->eventHistory_PrmFileSaveComplete =
      new History<EventEntry_PrmFileSaveComplete>(maxHistorySize);
    this->eventHistory_PrmFileReadError =
      new History<EventEntry_PrmFileReadError>(maxHistorySize);
    this->eventHistory_PrmFileLoadComplete =
      new History<EventEntry_PrmFileLoadComplete>(maxHistorySize);
    this->eventHistory_PrmSendTooLarge =
      new History<EventEntry_PrmSendTooLarge>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_sendPrm =
      new History<FromPortEntry_sendPrm>(maxHistorySize);
    this->fromPortHistory_recvPrmReady =
      new History<FromPortEntry_recvPrmReady>(maxHistorySize);
    this->fromPortHistory_pingOut =
      new History<FromPortEntry_pingOut>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  ActiveL1PrmDbTesterBase ::
    ~ActiveL1PrmDbTesterBase(void) 
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_PrmIdNotFound;
    delete this->eventHistory_PrmIdUpdated;
    delete this->eventHistory_PrmDbFull;
    delete this->eventHistory_PrmIdAdded;
    delete this->eventHistory_PrmFileWriteError;
    delete this->eventHistory_PrmFileSaveComplete;
    delete this->eventHistory_PrmFileReadError;
    delete this->eventHistory_PrmFileLoadComplete;
    delete this->eventHistory_PrmSendTooLarge;
  }

  void ActiveL1PrmDbTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port sendPrm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_sendPrm();
        ++_port
    ) {

      this->m_from_sendPrm[_port].init();
      this->m_from_sendPrm[_port].addCallComp(
          this,
          from_sendPrm_static
      );
      this->m_from_sendPrm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_sendPrm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_sendPrm[_port].setObjName(_portName);
#endif

    }

    // Attach input port recvPrmReady

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_recvPrmReady();
        ++_port
    ) {

      this->m_from_recvPrmReady[_port].init();
      this->m_from_recvPrmReady[_port].addCallComp(
          this,
          from_recvPrmReady_static
      );
      this->m_from_recvPrmReady[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_recvPrmReady[%d]",
          this->m_objName,
          _port
      );
      this->m_from_recvPrmReady[_port].setObjName(_portName);
#endif

    }

    // Attach input port pingOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_pingOut();
        ++_port
    ) {

      this->m_from_pingOut[_port].init();
      this->m_from_pingOut[_port].addCallComp(
          this,
          from_pingOut_static
      );
      this->m_from_pingOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_pingOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_pingOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdStatus();
        ++_port
    ) {

      this->m_from_CmdStatus[_port].init();
      this->m_from_CmdStatus[_port].addCallComp(
          this,
          from_CmdStatus_static
      );
      this->m_from_CmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdReg();
        ++_port
    ) {

      this->m_from_CmdReg[_port].init();
      this->m_from_CmdReg[_port].addCallComp(
          this,
          from_CmdReg_static
      );
      this->m_from_CmdReg[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdReg[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port sendPrmReady

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_sendPrmReady();
        ++_port
    ) {
      this->m_to_sendPrmReady[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_sendPrmReady[%d]",
          this->m_objName,
          _port
      );
      this->m_to_sendPrmReady[_port].setObjName(_portName);
#endif

    }

    // Initialize output port setPrm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_setPrm();
        ++_port
    ) {
      this->m_to_setPrm[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_setPrm[%d]",
          this->m_objName,
          _port
      );
      this->m_to_setPrm[_port].setObjName(_portName);
#endif

    }

    // Initialize output port recvPrm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_recvPrm();
        ++_port
    ) {
      this->m_to_recvPrm[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_recvPrm[%d]",
          this->m_objName,
          _port
      );
      this->m_to_recvPrm[_port].setObjName(_portName);
#endif

    }

    // Initialize output port pingIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_pingIn();
        ++_port
    ) {
      this->m_to_pingIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_pingIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_pingIn[_port].setObjName(_portName);
#endif

    }

    // Initialize output port getPrm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_getPrm();
        ++_port
    ) {
      this->m_to_getPrm[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_getPrm[%d]",
          this->m_objName,
          _port
      );
      this->m_to_getPrm[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_sendPrm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_sendPrm);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_recvPrmReady(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_recvPrmReady);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_sendPrmReady(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_sendPrmReady);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_setPrm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_setPrm);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_recvPrm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_recvPrm);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_pingIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_pingIn);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_pingOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_pingOut);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_getPrm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_getPrm);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_to_CmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_CmdDisp);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_CmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdStatus);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_CmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdReg);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ActiveL1PrmDbTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    connect_to_sendPrmReady(
        const NATIVE_INT_TYPE portNum,
        Fw::InputPrmListReadyPort *const sendPrmReady
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_sendPrmReady(),static_cast<AssertArg>(portNum));
    this->m_to_sendPrmReady[portNum].addCallPort(sendPrmReady);
  }

  void ActiveL1PrmDbTesterBase ::
    connect_to_setPrm(
        const NATIVE_INT_TYPE portNum,
        Fw::InputPrmSetPort *const setPrm
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_setPrm(),static_cast<AssertArg>(portNum));
    this->m_to_setPrm[portNum].addCallPort(setPrm);
  }

  void ActiveL1PrmDbTesterBase ::
    connect_to_recvPrm(
        const NATIVE_INT_TYPE portNum,
        Fw::InputPrmListPort *const recvPrm
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_recvPrm(),static_cast<AssertArg>(portNum));
    this->m_to_recvPrm[portNum].addCallPort(recvPrm);
  }

  void ActiveL1PrmDbTesterBase ::
    connect_to_pingIn(
        const NATIVE_INT_TYPE portNum,
        Svc::InputPingPort *const pingIn
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_pingIn(),static_cast<AssertArg>(portNum));
    this->m_to_pingIn[portNum].addCallPort(pingIn);
  }

  void ActiveL1PrmDbTesterBase ::
    connect_to_getPrm(
        const NATIVE_INT_TYPE portNum,
        Fw::InputPrmGetPort *const getPrm
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_getPrm(),static_cast<AssertArg>(portNum));
    this->m_to_getPrm[portNum].addCallPort(getPrm);
  }

  void ActiveL1PrmDbTesterBase ::
    connect_to_CmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const CmdDisp
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_CmdDisp[portNum].addCallPort(CmdDisp);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    invoke_to_sendPrmReady(
        const NATIVE_INT_TYPE portNum,
        U32 maxSize,
        bool reload
    )
  {
    FW_ASSERT(portNum < this->getNum_to_sendPrmReady(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_sendPrmReady(),static_cast<AssertArg>(portNum));
    this->m_to_sendPrmReady[portNum].invoke(
        maxSize, reload
    );
  }

  void ActiveL1PrmDbTesterBase ::
    invoke_to_setPrm(
        const NATIVE_INT_TYPE portNum,
        FwPrmIdType id,
        Fw::ParamBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_to_setPrm(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_setPrm(),static_cast<AssertArg>(portNum));
    this->m_to_setPrm[portNum].invoke(
        id, val
    );
  }

  void ActiveL1PrmDbTesterBase ::
    invoke_to_recvPrm(
        const NATIVE_INT_TYPE portNum,
        bool morePrms,
        Fw::ParamList val
    )
  {
    FW_ASSERT(portNum < this->getNum_to_recvPrm(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_recvPrm(),static_cast<AssertArg>(portNum));
    this->m_to_recvPrm[portNum].invoke(
        morePrms, val
    );
  }

  void ActiveL1PrmDbTesterBase ::
    invoke_to_pingIn(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_to_pingIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_pingIn(),static_cast<AssertArg>(portNum));
    this->m_to_pingIn[portNum].invoke(
        key
    );
  }

  Fw::ParamValid ActiveL1PrmDbTesterBase ::
    invoke_to_getPrm(
        const NATIVE_INT_TYPE portNum,
        FwPrmIdType id,
        Fw::ParamBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_to_getPrm(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_getPrm(),static_cast<AssertArg>(portNum));
    return this->m_to_getPrm[portNum].invoke(
        id, val
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_sendPrmReady(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_sendPrmReady(), static_cast<AssertArg>(portNum));
    return this->m_to_sendPrmReady[portNum].isConnected();
  }

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_setPrm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_setPrm(), static_cast<AssertArg>(portNum));
    return this->m_to_setPrm[portNum].isConnected();
  }

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_recvPrm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_recvPrm(), static_cast<AssertArg>(portNum));
    return this->m_to_recvPrm[portNum].isConnected();
  }

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_pingIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_pingIn(), static_cast<AssertArg>(portNum));
    return this->m_to_pingIn[portNum].isConnected();
  }

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_getPrm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_getPrm(), static_cast<AssertArg>(portNum));
    return this->m_to_getPrm[portNum].isConnected();
  }

  bool ActiveL1PrmDbTesterBase ::
    isConnected_to_CmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_CmdDisp[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------
 
  Fw::InputPrmListPort *ActiveL1PrmDbTesterBase ::
    get_from_sendPrm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_sendPrm(),static_cast<AssertArg>(portNum));
    return &this->m_from_sendPrm[portNum];
  }

  Fw::InputPrmListReadyPort *ActiveL1PrmDbTesterBase ::
    get_from_recvPrmReady(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_recvPrmReady(),static_cast<AssertArg>(portNum));
    return &this->m_from_recvPrmReady[portNum];
  }

  Svc::InputPingPort *ActiveL1PrmDbTesterBase ::
    get_from_pingOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_pingOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_pingOut[portNum];
  }

  Fw::InputCmdResponsePort *ActiveL1PrmDbTesterBase ::
    get_from_CmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdStatus[portNum];
  }

  Fw::InputCmdRegPort *ActiveL1PrmDbTesterBase ::
    get_from_CmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdReg(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdReg[portNum];
  }

  Fw::InputTimePort *ActiveL1PrmDbTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *ActiveL1PrmDbTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *ActiveL1PrmDbTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    from_sendPrm_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        bool morePrms,
        Fw::ParamList val
    )
  {
    FW_ASSERT(callComp);
    ActiveL1PrmDbTesterBase* _testerBase = 
      static_cast<ActiveL1PrmDbTesterBase*>(callComp);
    _testerBase->from_sendPrm_handlerBase(
        portNum,
        morePrms, val
    );
  }

  void ActiveL1PrmDbTesterBase ::
    from_recvPrmReady_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        U32 maxSize,
        bool reload
    )
  {
    FW_ASSERT(callComp);
    ActiveL1PrmDbTesterBase* _testerBase = 
      static_cast<ActiveL1PrmDbTesterBase*>(callComp);
    _testerBase->from_recvPrmReady_handlerBase(
        portNum,
        maxSize, reload
    );
  }

  void ActiveL1PrmDbTesterBase ::
    from_pingOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(callComp);
    ActiveL1PrmDbTesterBase* _testerBase = 
      static_cast<ActiveL1PrmDbTesterBase*>(callComp);
    _testerBase->from_pingOut_handlerBase(
        portNum,
        key
    );
  }

  void ActiveL1PrmDbTesterBase ::
    from_CmdStatus_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    ActiveL1PrmDbTesterBase* _testerBase =
      static_cast<ActiveL1PrmDbTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void ActiveL1PrmDbTesterBase ::
    from_CmdReg_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void ActiveL1PrmDbTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    ActiveL1PrmDbTesterBase* _testerBase =
      static_cast<ActiveL1PrmDbTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ActiveL1PrmDbTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    ActiveL1PrmDbTesterBase* _testerBase =
      static_cast<ActiveL1PrmDbTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void ActiveL1PrmDbTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    ActiveL1PrmDbTesterBase* _testerBase =
      static_cast<ActiveL1PrmDbTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_sendPrm->clear();
    this->fromPortHistory_recvPrmReady->clear();
    this->fromPortHistory_pingOut->clear();
  }

  // ---------------------------------------------------------------------- 
  // From port: sendPrm
  // ---------------------------------------------------------------------- 

  void ActiveL1PrmDbTesterBase ::
    pushFromPortEntry_sendPrm(
        bool morePrms,
        Fw::ParamList val
    )
  {
    FromPortEntry_sendPrm _e = {
      morePrms, val
    };
    this->fromPortHistory_sendPrm->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: recvPrmReady
  // ---------------------------------------------------------------------- 

  void ActiveL1PrmDbTesterBase ::
    pushFromPortEntry_recvPrmReady(
        U32 maxSize,
        bool reload
    )
  {
    FromPortEntry_recvPrmReady _e = {
      maxSize, reload
    };
    this->fromPortHistory_recvPrmReady->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: pingOut
  // ---------------------------------------------------------------------- 

  void ActiveL1PrmDbTesterBase ::
    pushFromPortEntry_pingOut(
        U32 key
    )
  {
    FromPortEntry_pingOut _e = {
      key
    };
    this->fromPortHistory_pingOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    from_sendPrm_handlerBase(
        const NATIVE_INT_TYPE portNum,
        bool morePrms,
        Fw::ParamList val
    )
  {
    FW_ASSERT(portNum < this->getNum_from_sendPrm(),static_cast<AssertArg>(portNum));
    this->from_sendPrm_handler(
        portNum,
        morePrms, val
    );
  }

  void ActiveL1PrmDbTesterBase ::
    from_recvPrmReady_handlerBase(
        const NATIVE_INT_TYPE portNum,
        U32 maxSize,
        bool reload
    )
  {
    FW_ASSERT(portNum < this->getNum_from_recvPrmReady(),static_cast<AssertArg>(portNum));
    this->from_recvPrmReady_handler(
        portNum,
        maxSize, reload
    );
  }

  void ActiveL1PrmDbTesterBase ::
    from_pingOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    FW_ASSERT(portNum < this->getNum_from_pingOut(),static_cast<AssertArg>(portNum));
    this->from_pingOut_handler(
        portNum,
        key
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CommandResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ---------------------------------------------------------------------- 
  // Command: PRM_SAVE_FILE
  // ---------------------------------------------------------------------- 

  void ActiveL1PrmDbTesterBase ::
    sendCmd_PRM_SAVE_FILE(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = ActiveL1PrmDbComponentBase::OPCODE_PRM_SAVE_FILE + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  
  void ActiveL1PrmDbTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {
       
    const U32 idBase = this->getIdBase();   
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }
        
  }
  
  // ----------------------------------------------------------------------
  // History 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case ActiveL1PrmDbComponentBase::EVENTID_PRMIDNOTFOUND: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Id;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Id);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_PrmIdNotFound(Id);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMIDUPDATED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Id;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Id);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_PrmIdUpdated(Id);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMDBFULL: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1+1,_numArgs,1+1);
        // For FATAL, there is a stack size of 4 and a dummy entry.
        U8 stackArgLen;
        _status = args.deserialize(stackArgLen);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );
        FW_ASSERT(4 == stackArgLen,stackArgLen);
		U32 dummyStackArg;        
        _status = args.deserialize(dummyStackArg);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );
        FW_ASSERT(0 == dummyStackArg,dummyStackArg);
        
#endif    
        U32 Id;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Id);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_FATAL_PrmDbFull(Id);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMIDADDED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Id;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Id);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_PrmIdAdded(Id);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMFILEWRITEERROR: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(FwEnumStoreType),_argSize,sizeof(FwEnumStoreType));
        }
#endif      
        FwEnumStoreType stageInt;
        _status = args.deserialize(stageInt);
        ActiveL1PrmDbComponentBase::PrmWriteError stage = static_cast<ActiveL1PrmDbComponentBase::PrmWriteError>(stageInt);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 record;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(record);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 error;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(error);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_PrmFileWriteError(stage, record, error);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMFILESAVECOMPLETE: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 records;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(records);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_PrmFileSaveComplete(records);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMFILEREADERROR: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(FwEnumStoreType),_argSize,sizeof(FwEnumStoreType));
        }
#endif      
        FwEnumStoreType stageInt;
        _status = args.deserialize(stageInt);
        ActiveL1PrmDbComponentBase::PrmReadError stage = static_cast<ActiveL1PrmDbComponentBase::PrmReadError>(stageInt);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 record;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(record);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 error;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(error);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_PrmFileReadError(stage, record, error);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMFILELOADCOMPLETE: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 records;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(records);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_PrmFileLoadComplete(records);

        break;

      }

      case ActiveL1PrmDbComponentBase::EVENTID_PRMSENDTOOLARGE: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
        U32 prmId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(prmId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U32 prmSize;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(prmSize);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 portNum;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(portNum);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_PrmSendTooLarge(prmId, prmSize, portNum);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void ActiveL1PrmDbTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_PrmIdNotFound->clear();
    this->eventHistory_PrmIdUpdated->clear();
    this->eventHistory_PrmDbFull->clear();
    this->eventHistory_PrmIdAdded->clear();
    this->eventHistory_PrmFileWriteError->clear();
    this->eventHistory_PrmFileSaveComplete->clear();
    this->eventHistory_PrmFileReadError->clear();
    this->eventHistory_PrmFileLoadComplete->clear();
    this->eventHistory_PrmSendTooLarge->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void ActiveL1PrmDbTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void ActiveL1PrmDbTesterBase ::
    printTextLogHistory(FILE *file) 
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i), 
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: PrmIdNotFound 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_WARNING_LO_PrmIdNotFound(
        U32 Id
    )
  {
    EventEntry_PrmIdNotFound e = {
      Id
    };
    eventHistory_PrmIdNotFound->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmIdUpdated 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_ACTIVITY_HI_PrmIdUpdated(
        U32 Id
    )
  {
    EventEntry_PrmIdUpdated e = {
      Id
    };
    eventHistory_PrmIdUpdated->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmDbFull 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_FATAL_PrmDbFull(
        U32 Id
    )
  {
    EventEntry_PrmDbFull e = {
      Id
    };
    eventHistory_PrmDbFull->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmIdAdded 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_ACTIVITY_HI_PrmIdAdded(
        U32 Id
    )
  {
    EventEntry_PrmIdAdded e = {
      Id
    };
    eventHistory_PrmIdAdded->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmFileWriteError 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_WARNING_HI_PrmFileWriteError(
        ActiveL1PrmDbComponentBase::PrmWriteError stage,
        I32 record,
        I32 error
    )
  {
    EventEntry_PrmFileWriteError e = {
      stage, record, error
    };
    eventHistory_PrmFileWriteError->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmFileSaveComplete 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_ACTIVITY_HI_PrmFileSaveComplete(
        U32 records
    )
  {
    EventEntry_PrmFileSaveComplete e = {
      records
    };
    eventHistory_PrmFileSaveComplete->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmFileReadError 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_WARNING_HI_PrmFileReadError(
        ActiveL1PrmDbComponentBase::PrmReadError stage,
        I32 record,
        I32 error
    )
  {
    EventEntry_PrmFileReadError e = {
      stage, record, error
    };
    eventHistory_PrmFileReadError->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmFileLoadComplete 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_ACTIVITY_HI_PrmFileLoadComplete(
        U32 records
    )
  {
    EventEntry_PrmFileLoadComplete e = {
      records
    };
    eventHistory_PrmFileLoadComplete->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: PrmSendTooLarge 
  // ----------------------------------------------------------------------

  void ActiveL1PrmDbTesterBase ::
    logIn_WARNING_HI_PrmSendTooLarge(
        U32 prmId,
        U32 prmSize,
        I32 portNum
    )
  {
    EventEntry_PrmSendTooLarge e = {
      prmId, prmSize, portNum
    };
    eventHistory_PrmSendTooLarge->push_back(e);
    ++this->eventsSize;
  }

} // end namespace Svc
