// ======================================================================
// \title  BufferLogger/test/ut/Tester.hpp
// \author bocchino, mereweth
// \brief  hpp file for BufferLogger test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "Svc/BufferLogger/BufferLogger.hpp"

#define COM_BUFFER_LENGTH 4
#define MAX_ENTRIES_PER_FILE 5
#define SIZE_TYPE U32
#define MAX_BYTES_PER_FILE \
  (MAX_ENTRIES_PER_FILE*COM_BUFFER_LENGTH + MAX_ENTRIES_PER_FILE*sizeof(SIZE_TYPE))

#define DIRECT_CHUNK_SIZE 512

namespace Svc {

  class Tester :
    public BufferLoggerGTestBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
      Tester(
          BufferLoggerFileMode writeMode = BL_REGULAR_WRITE,  //! The write mode - direct, bulk, or looping
          BufferLoggerCloseMode closeMode = BL_CLOSE_SYNC,
          U32 directChunkSize = 512, //! The filesystem chunk size - direct mode uses this
          bool doInitLog = true
      );

      //! Destroy object Tester
      //!
      ~Tester(void);

      // ----------------------------------------------------------------------
      // Tests (rest are in Errors, Health, and Logging classes)
      // ----------------------------------------------------------------------

    public:

      //! No-one called initLog
      void LogNoInit(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_bufferSendOut
      //!
      void from_bufferSendOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer& fwBuffer
      );

      //! Handler for from_pingOut
      //!
      void from_pingOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Dispatch one message on the queue
      void dispatchOne(void);

      //! Dispatch all messages on the queue
      void dispatchAll(void);

      //! Generate a test time
      Fw::Time generateTestTime(
          const U32 seconds //!< The seconds value
      );

      //! Set test time seconds
      void setTestTimeSeconds(
          const U32 seconds //!< The seconds value
      );

      //! Send com buffers to comIn
      void sendComBuffers(
          const U32 n //!< The number of buffers to send
      );

      //! Send managed buffers to bufferSendIn
      void sendManagedBuffers(
          const U32 n //!< The number of buffers to send
      );

      //! Check that file exists
      void checkFileExists(
          const Fw::EightyCharString& fileName //!< The file name
      );

      //! Check that hash file exists
      void checkHashFileExists(
          const Fw::EightyCharString& fileName //!< The file name
      );

      //! Check the integrity of a log file
      void checkLogFileIntegrity(
          const char *const fileName, //!< The file name
          const U32 expectedSize, //!< The expected file size in bytes
          const U32 expectedNumBuffers //!< The expected number of buffers
      );

      //! Check file validation
      void checkFileValidation(
          const char *const fileName //!< The file name
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts(void);

      //! Initialize components
      //!
      void initComponents(void);

    protected:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      BufferLogger component;

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! Data for input buffers
      static const U8 data[COM_BUFFER_LENGTH];

  };

} // end namespace Svc

#endif
