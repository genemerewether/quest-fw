// ======================================================================
// \title  HexRouter/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for HexRouter component test harness base class
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

#ifndef HexRouter_TESTER_BASE_HPP
#define HexRouter_TESTER_BASE_HPP

#include <SnapdragonFlight/HexRouter/HexRouterComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace SnapdragonFlight {

  //! \class HexRouterTesterBase
  //! \brief Auto-generated base class for HexRouter component test harness
  //!
  class HexRouterTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object HexRouterTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect KraitPortsIn to to_KraitPortsIn[portNum]
      //!
      void connect_to_KraitPortsIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputSerializePort *const KraitPortsIn /*!< The port*/
      );

      //! Connect readBufferRecv to to_readBufferRecv[portNum]
      //!
      void connect_to_readBufferRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputBufferSendPort *const readBufferRecv /*!< The port*/
      );

      //! Connect Sched to to_Sched[portNum]
      //!
      void connect_to_Sched(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const Sched /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from HexPortsOut
      //!
      //! \return from_HexPortsOut[portNum]
      //!
      Fw::InputSerializePort* get_from_HexPortsOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from readBufferSend
      //!
      //! \return from_readBufferSend[portNum]
      //!
      Fw::InputBufferSendPort* get_from_readBufferSend(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Tlm
      //!
      //! \return from_Tlm[portNum]
      //!
      Fw::InputTlmPort* get_from_Tlm(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Log
      //!
      //! \return from_Log[portNum]
      //!
      Fw::InputLogPort* get_from_Log(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from LogText
      //!
      //! \return from_LogText[portNum]
      //!
      Fw::InputLogTextPort* get_from_LogText(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object HexRouterTesterBase
      //!
      HexRouterTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object HexRouterTesterBase
      //!
      virtual ~HexRouterTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) : 
              numEntries(0), 
              maxSize(maxSize) 
          { 
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_readBufferSend
      //!
      virtual void from_readBufferSend_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer fwBuffer 
      ) = 0;

      //! Handler base function for from_readBufferSend
      //!
      void from_readBufferSend_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer fwBuffer 
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_readBufferSend
      void pushFromPortEntry_readBufferSend(
          Fw::Buffer fwBuffer 
      );

      //! A history entry for from_readBufferSend
      //!
      typedef struct {
        Fw::Buffer fwBuffer;
      } FromPortEntry_readBufferSend;

      //! The history for from_readBufferSend
      //!
      History<FromPortEntry_readBufferSend> 
        *fromPortHistory_readBufferSend;

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for serial from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_HexPortsOut
      //!
      virtual void from_HexPortsOut_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
      ) = 0;

      //! Handler base class function prototype for from_HexPortsOut
      //!
      void from_HexPortsOut_handlerBase (
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
      );


    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to KraitPortsIn
      //!
      void invoke_to_KraitPortsIn(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::SerializeBufferBase& Buffer
      );

      //! Invoke the to port connected to readBufferRecv
      //!
      void invoke_to_readBufferRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer fwBuffer 
      );

      //! Invoke the to port connected to Sched
      //!
      void invoke_to_Sched(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_KraitPortsIn ports
      //!
      //! \return The number of to_KraitPortsIn ports
      //!
      NATIVE_INT_TYPE getNum_to_KraitPortsIn(void) const;

      //! Get the number of from_HexPortsOut ports
      //!
      //! \return The number of from_HexPortsOut ports
      //!
      NATIVE_INT_TYPE getNum_from_HexPortsOut(void) const;

      //! Get the number of from_readBufferSend ports
      //!
      //! \return The number of from_readBufferSend ports
      //!
      NATIVE_INT_TYPE getNum_from_readBufferSend(void) const;

      //! Get the number of to_readBufferRecv ports
      //!
      //! \return The number of to_readBufferRecv ports
      //!
      NATIVE_INT_TYPE getNum_to_readBufferRecv(void) const;

      //! Get the number of to_Sched ports
      //!
      //! \return The number of to_Sched ports
      //!
      NATIVE_INT_TYPE getNum_to_Sched(void) const;

      //! Get the number of from_Tlm ports
      //!
      //! \return The number of from_Tlm ports
      //!
      NATIVE_INT_TYPE getNum_from_Tlm(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

      //! Get the number of from_Log ports
      //!
      //! \return The number of from_Log ports
      //!
      NATIVE_INT_TYPE getNum_from_Log(void) const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_LogText ports
      //!
      //! \return The number of from_LogText ports
      //!
      NATIVE_INT_TYPE getNum_from_LogText(void) const;
#endif

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_KraitPortsIn[portNum] is connected
      //!
      bool isConnected_to_KraitPortsIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_readBufferRecv[portNum] is connected
      //!
      bool isConnected_to_readBufferRecv(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_Sched[portNum] is connected
      //!
      bool isConnected_to_Sched(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Event dispatch
      // ----------------------------------------------------------------------

      //! Dispatch an event
      //!
      void dispatchEvents(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          Fw::LogBuffer& args /*!< The serialized arguments*/
      );

      //! Clear event history
      //!
      void clearEvents(void);

      //! The total number of events seen
      //!
      U32 eventsSize;

#if FW_ENABLE_TEXT_LOGGING

    protected:

      // ----------------------------------------------------------------------
      // Text events
      // ----------------------------------------------------------------------

      //! Handle a text event
      //!
      virtual void textLogIn(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::TextLogSeverity severity, /*!< The severity*/
          const Fw::TextLogString& text /*!< The event string*/
      );

      //! A history entry for the text log
      //!
      typedef struct {
        U32 id;
        Fw::Time timeTag;
        Fw::TextLogSeverity severity;
        Fw::TextLogString text;
      } TextLogEntry;

      //! The history of text log events
      //!
      History<TextLogEntry> *textLogHistory;

      //! Print a text log history entry
      //!
      static void printTextLogHistoryEntry(
          const TextLogEntry& e,
          FILE* file
      );

      //! Print the text log history
      //!
      void printTextLogHistory(FILE *const file);

#endif

    protected:

      // ----------------------------------------------------------------------
      // Event: HR_DataReceiveError
      // ----------------------------------------------------------------------

      //! Handle event HR_DataReceiveError
      //!
      virtual void logIn_WARNING_HI_HR_DataReceiveError(
          HexRouterComponentBase::HR_ReceiveError error, /*!< The receive error code*/
          I32 stat /*!< Status code - depends on error type*/
      );

      //! A history entry for event HR_DataReceiveError
      //!
      typedef struct {
        HexRouterComponentBase::HR_ReceiveError error;
        I32 stat;
      } EventEntry_HR_DataReceiveError;

      //! The history of HR_DataReceiveError events
      //!
      History<EventEntry_HR_DataReceiveError> 
        *eventHistory_HR_DataReceiveError;

    protected:

      // ----------------------------------------------------------------------
      // Event: HR_InvalidPortNum
      // ----------------------------------------------------------------------

      //! Handle event HR_InvalidPortNum
      //!
      virtual void logIn_WARNING_HI_HR_InvalidPortNum(
          HexRouterComponentBase::HR_PortType PortType, /*!< Type of port that was not connected*/
          U8 portNum 
      );

      //! A history entry for event HR_InvalidPortNum
      //!
      typedef struct {
        HexRouterComponentBase::HR_PortType PortType;
        U8 portNum;
      } EventEntry_HR_InvalidPortNum;

      //! The history of HR_InvalidPortNum events
      //!
      History<EventEntry_HR_InvalidPortNum> 
        *eventHistory_HR_InvalidPortNum;

    protected:

      // ----------------------------------------------------------------------
      // Event: HR_BadSerialPortCall
      // ----------------------------------------------------------------------

      //! Handle event HR_BadSerialPortCall
      //!
      virtual void logIn_WARNING_HI_HR_BadSerialPortCall(
          I32 status, 
          U8 portNum 
      );

      //! A history entry for event HR_BadSerialPortCall
      //!
      typedef struct {
        I32 status;
        U8 portNum;
      } EventEntry_HR_BadSerialPortCall;

      //! The history of HR_BadSerialPortCall events
      //!
      History<EventEntry_HR_BadSerialPortCall> 
        *eventHistory_HR_BadSerialPortCall;

    protected:

      // ----------------------------------------------------------------------
      // Event: HR_MemoryError
      // ----------------------------------------------------------------------

      //! Handle event HR_MemoryError
      //!
      virtual void logIn_WARNING_HI_HR_MemoryError(
          HexRouterComponentBase::HR_MemoryError error /*!< Type of memory operation that failed*/
      );

      //! A history entry for event HR_MemoryError
      //!
      typedef struct {
        HexRouterComponentBase::HR_MemoryError error;
      } EventEntry_HR_MemoryError;

      //! The history of HR_MemoryError events
      //!
      History<EventEntry_HR_MemoryError> 
        *eventHistory_HR_MemoryError;

    protected:

      // ----------------------------------------------------------------------
      // Event: HR_WriteError
      // ----------------------------------------------------------------------

      //! Handle event HR_WriteError
      //!
      virtual void logIn_WARNING_HI_HR_WriteError(
          I32 error /*!< The error code*/
      );

      //! A history entry for event HR_WriteError
      //!
      typedef struct {
        I32 error;
      } EventEntry_HR_WriteError;

      //! The history of HR_WriteError events
      //!
      History<EventEntry_HR_WriteError> 
        *eventHistory_HR_WriteError;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry dispatch
      // ----------------------------------------------------------------------

      //! Dispatch telemetry
      //!
      void dispatchTlm(
          const FwChanIdType id, /*!< The channel ID*/
          const Fw::Time& timeTag, /*!< The time*/
          Fw::TlmBuffer& val /*!< The channel value*/
      );

      //! Clear telemetry history
      //!
      void clearTlm(void);

      //! The total number of telemetry inputs seen
      //!
      U32 tlmSize;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_ResyncErrors
      // ----------------------------------------------------------------------

      //! Handle channel HR_ResyncErrors
      //!
      virtual void tlmInput_HR_ResyncErrors(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_ResyncErrors
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_ResyncErrors;

      //! The history of HR_ResyncErrors values
      //!
      History<TlmEntry_HR_ResyncErrors> 
        *tlmHistory_HR_ResyncErrors;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumPackets
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumPackets
      //!
      virtual void tlmInput_HR_NumPackets(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumPackets
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumPackets;

      //! The history of HR_NumPackets values
      //!
      History<TlmEntry_HR_NumPackets> 
        *tlmHistory_HR_NumPackets;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumDecodeErrors
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumDecodeErrors
      //!
      virtual void tlmInput_HR_NumDecodeErrors(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumDecodeErrors
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumDecodeErrors;

      //! The history of HR_NumDecodeErrors values
      //!
      History<TlmEntry_HR_NumDecodeErrors> 
        *tlmHistory_HR_NumDecodeErrors;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumInvalidPorts
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumInvalidPorts
      //!
      virtual void tlmInput_HR_NumInvalidPorts(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumInvalidPorts
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumInvalidPorts;

      //! The history of HR_NumInvalidPorts values
      //!
      History<TlmEntry_HR_NumInvalidPorts> 
        *tlmHistory_HR_NumInvalidPorts;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumBadSerialPortCalls
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumBadSerialPortCalls
      //!
      virtual void tlmInput_HR_NumBadSerialPortCalls(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumBadSerialPortCalls
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumBadSerialPortCalls;

      //! The history of HR_NumBadSerialPortCalls values
      //!
      History<TlmEntry_HR_NumBadSerialPortCalls> 
        *tlmHistory_HR_NumBadSerialPortCalls;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumOutputBufferOverflows
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumOutputBufferOverflows
      //!
      virtual void tlmInput_HR_NumOutputBufferOverflows(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumOutputBufferOverflows
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumOutputBufferOverflows;

      //! The history of HR_NumOutputBufferOverflows values
      //!
      History<TlmEntry_HR_NumOutputBufferOverflows> 
        *tlmHistory_HR_NumOutputBufferOverflows;

    protected:

      // ----------------------------------------------------------------------
      // Channel: HR_NumZeroPktSize
      // ----------------------------------------------------------------------

      //! Handle channel HR_NumZeroPktSize
      //!
      virtual void tlmInput_HR_NumZeroPktSize(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel HR_NumZeroPktSize
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_HR_NumZeroPktSize;

      //! The history of HR_NumZeroPktSize values
      //!
      History<TlmEntry_HR_NumZeroPktSize> 
        *tlmHistory_HR_NumZeroPktSize;

    protected:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Set the test time for events and telemetry
      //!
      void setTestTime(
          const Fw::Time& timeTag /*!< The time*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to KraitPortsIn
      //!
      Fw::OutputSerializePort m_to_KraitPortsIn[25];

      //! To port connected to readBufferRecv
      //!
      Fw::OutputBufferSendPort m_to_readBufferRecv[5];

      //! To port connected to Sched
      //!
      Svc::OutputSchedPort m_to_Sched[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to HexPortsOut
      //!
      Fw::InputSerializePort m_from_HexPortsOut[25];

      //! From port connected to readBufferSend
      //!
      Fw::InputBufferSendPort m_from_readBufferSend[5];

      //! From port connected to Tlm
      //!
      Fw::InputTlmPort m_from_Tlm[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

      //! From port connected to Log
      //!
      Fw::InputLogPort m_from_Log[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to LogText
      //!
      Fw::InputLogTextPort m_from_LogText[1];
#endif

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_HexPortsOut
      //!
      static void from_HexPortsOut_static(
          Fw::PassiveComponentBase *const callComp, //!< The component instance
          const NATIVE_INT_TYPE portNum, //!< The port number
          Fw::SerializeBufferBase& Buffer //!< serialized data buffer
      );

      //! Static function for port from_readBufferSend
      //!
      static void from_readBufferSend_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer fwBuffer 
      );

      //! Static function for port from_Tlm
      //!
      static void from_Tlm_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! Static function for port from_Log
      //!
      static void from_Log_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_LogText
      //!
      static void from_LogText_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TextLogSeverity severity, /*!< The severity argument*/
          Fw::TextLogString &text /*!< Text of log message*/
      );
#endif

    private:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Test time stamp
      //!
      Fw::Time m_testTime;

  };

} // end namespace SnapdragonFlight

#endif
