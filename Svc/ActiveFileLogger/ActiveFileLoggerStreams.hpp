#ifndef _ACTIVE_FILE_LOGGER_STREAMS_HPP_
#define _ACTIVE_FILE_LOGGER_STREAMS_HPP_

typedef enum {
    AFL_SERIAL_DATA = 0,
    AFL_HLROSIFACE_IMUNOCOV,
    AFL_HLROSIFACE_BATCHIMU,
    AFL_HLROSIFACE_RANGE,
    AFL_FILTIFACE_ODOMNOCOV,
    AFL_FILTIFACE_IMUSTATEUPDATENOCOV,
    AFL_MRCTRLIFACE_ACCEL_CMD,
    AFL_ACTADAP_ESC,
    AFL_MVCAM_CALLBACK,
    AFL_SCAM_CALLBACK,
    AFL_ATINETBOX_WRENCH,
    AFL_ATINETBOX_WRENCH_AA,
    NUM_AFL_STREAMS,
} active_file_logger_stream_t;

#endif //_ACTIVE_FILE_LOGGER_STREAMS_HPP_
