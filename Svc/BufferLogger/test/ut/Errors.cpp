// ======================================================================
// \title  Errors.cpp
// \author bocchino, mereweth
// \brief  Implementation for Buffer Logger error tests
//
// \copyright
// Copyright (C) 2017 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <stdlib.h>

#include "Errors.hpp"
#include "Os/ValidatedFile.hpp"

#include <stdio.h>
#include <sys/time.h>
//#define DEBUG_PRINT(x,...) printf(x,##__VA_ARGS__); fflush(stdout)
#define DEBUG_PRINT(x,...)

namespace Svc {

  namespace Errors {

    Tester ::
      Tester(BufferLoggerFileMode writeMode,
             BufferLoggerCloseMode closeMode,
             U32 directChunkSize,
             bool doInitLog) :
        Svc::Tester(writeMode, closeMode, directChunkSize, doInitLog)
    {

    }

    void Tester ::
      LogFileOpen(void)
    {
      // Remove buf directory
      (void) system("rm -rf buf");

      this->component.setBaseName(Fw::EightyCharString("LogFileOpen"));
      //this->component.m_file.baseName = Fw::EightyCharString("LogFileOpen");
      //this->component.m_file.baseNameBeenSet = true;

      // Check initial state
      ASSERT_EQ(BufferLogger::File::Mode::CLOSED, this->component.m_file.mode);
      ASSERT_EVENTS_SIZE(0);

      // Send data
      this->sendComBuffers(3);

      // Check events
      // NOTE(mereweth) - not throttled
      ASSERT_EVENTS_SIZE(3);
      ASSERT_EVENTS_BL_LogFileOpenError_SIZE(3);
      for (int i = 0; i < 3; i++) {
        ASSERT_EVENTS_BL_LogFileOpenError(
          i,
          Os::File::DOESNT_EXIST,
          this->component.m_file.name.toChar()
        );
      }

      // Create buf directory and try again
      (void) system("mkdir buf");
      ASSERT_EQ(BufferLogger::File::Mode::CLOSED, this->component.m_file.mode);

      // Send data
      this->sendComBuffers(3);

      // Check events
      // NOTE(mereweth) - should have no more events than we did before
      ASSERT_EVENTS_SIZE(3);
      ASSERT_EVENTS_BL_LogFileOpenError_SIZE(3);
      this->component.m_file.close();

      // Remove buf directory and try again
      (void) system("rm -rf buf");
      ASSERT_EQ(BufferLogger::File::Mode::CLOSED, this->component.m_file.mode);

      // Send data
      this->sendComBuffers(3);

      // Check events
      // We expect 3 more; not throttled
      ASSERT_EVENTS_SIZE(6);
      ASSERT_EVENTS_BL_LogFileOpenError_SIZE(6);
      for (int i = 3; i < 6; i++) {
        ASSERT_EVENTS_BL_LogFileOpenError(
          i,
          Os::File::DOESNT_EXIST,
          this->component.m_file.name.toChar()
        );
      }

    }

    void Tester ::
      LogFileWrite(void)
    {
      ASSERT_EQ(BufferLogger::File::Mode::CLOSED, this->component.m_file.mode);
      ASSERT_EVENTS_SIZE(0);

      this->component.setBaseName(Fw::EightyCharString("LogFileWrite"));
      //this->component.m_file.baseName = Fw::EightyCharString("LogFileWrite");
      //this->component.m_file.baseNameBeenSet = true;

      // Send data
      this->sendComBuffers(1);

      // Force close the file
      this->component.m_file.osFile.close();

      // Send data
      this->sendComBuffers(1);

      // Construct file name
      Fw::EightyCharString fileName;
      fileName.format(
          "%s%s0000000%s",
          this->component.m_file.prefix.toChar(),
          this->component.m_file.baseName.toChar(),
          this->component.m_file.suffix.toChar()
      );

      // Check events
      // NOTE(mereweth) - not throttled
      ASSERT_EVENTS_SIZE(1);
      ASSERT_EVENTS_BL_LogFileWriteError_SIZE(1);
      ASSERT_EVENTS_BL_LogFileWriteError(
          0,
          Os::File::NOT_OPENED, // errornum
          0, // bytesWritten
          sizeof(SIZE_TYPE), // bytesAttempted
          fileName.toChar() // file
      );

      // Make comlogger open a new file:
      this->component.m_file.mode = BufferLogger::File::Mode::CLOSED;
      this->component.m_file.open();

      // NOTE(mereweth) - new file; counter has incremented
      fileName.format(
          "%s%s0000001%s",
          this->component.m_file.prefix.toChar(),
          this->component.m_file.baseName.toChar(),
          this->component.m_file.suffix.toChar()
      );

      // Try to write and make sure it succeeds
      // Send data
      this->sendComBuffers(3);

      // Expect no new errors
      ASSERT_EVENTS_SIZE(1);
      ASSERT_EVENTS_BL_LogFileWriteError_SIZE(1);

      // Force close the file from underneath the component
      component.m_file.osFile.close();

      // Send data
      this->sendComBuffers(3);

      // Check events
      DEBUG_PRINT("Checking that we assert for each com buffer in LogFileWrite; mode %d\n",
                  this->component.m_file.writeMode);
      // NOTE(mereweth) - not throttled; 3 more events
      ASSERT_EVENTS_SIZE(4);
      ASSERT_EVENTS_BL_LogFileWriteError_SIZE(4);
      for (int i = 1; i < 4; i++) {
          ASSERT_EVENTS_BL_LogFileWriteError(
              i,
              Os::File::NOT_OPENED,
              0, // bytesWritten
              sizeof(SIZE_TYPE), // bytesAttempted
              fileName.toChar()
          );
      }

    }

    void Tester ::
      LogFileValidation(void)
    {
      this->component.setBaseName(Fw::EightyCharString("LogFileValidation"));
      //this->component.m_file.baseName = Fw::EightyCharString("LogFileValidation");
      //this->component.m_file.baseNameBeenSet = true;

      // Send data
      this->sendComBuffers(1);
      // Remove permission to buf directory
      (void) system("chmod -w buf");
      // Send close file command
      this->sendCmd_BL_CloseFile(0, 0);
      this->dispatchOne();
      // Check events
      ASSERT_EVENTS_SIZE(2);
      Fw::EightyCharString fileName;
      fileName.format(
          "%s%s0000000%s",
          this->component.m_file.prefix.toChar(),
          this->component.m_file.baseName.toChar(),
          this->component.m_file.suffix.toChar()
      );
      ASSERT_EVENTS_BL_LogFileClosed(
          0,
          fileName.toChar()
      );
      Os::ValidatedFile validatedFile(fileName.toChar());
      const Fw::EightyCharString& hashFileName = validatedFile.getHashFileName();
      ASSERT_EVENTS_BL_LogFileValidationError(
          0,
          hashFileName.toChar(),
          Os::ValidateFile::VALIDATION_FILE_NO_PERMISSION
      );
      // Restore permission
      (void) system("chmod +w buf");
    }

  }

}
