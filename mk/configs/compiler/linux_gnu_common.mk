include $(BUILD_ROOT)/mk/configs/compiler/include_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/defines_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/linux_common.mk
include $(BUILD_ROOT)/mk/configs/compiler/gnu-common.mk

CC :=  /usr/bin/gcc
CXX := /usr/bin/g++
GCOV := /usr/bin/gcov
AR := /usr/bin/ar

BUILD_32BIT := -m32

CC_MUNCH := $(BUILD_ROOT)/mk/bin/empty.sh

LINK_LIB := $(AR)
LINK_LIB_FLAGS := rcs
LIBRARY_TO := 
POST_LINK_LIB := ranlib

LINK_BIN := $(CXX)
LINK_BIN_FLAGS := $(LINUX_FP_FLAGS) -z muldefs $(LIBS) #$(BUILD_32BIT)

FILE_SIZE := $(LS) $(LS_SIZE)
LOAD_SIZE := $(SIZE)



LINK_LIBS := -ldl -lpthread -lm -lrt -lutil

OPT_SPEED := -O3 -funroll-loops
DEBUG := -g3

LINUX_GNU_CFLAGS := $(LINUX_FLAGS_COMMON) \
					$(COMMON_DEFINES) \
					$(LINUX_FP_FLAGS) \
					$(GNU_CFLAGS_COMMON) \
					#$(BUILD_32BIT) # Quantum framework won't build 32-bit

LINUX_GNU_CXXFLAGS :=	$(LINUX_FLAGS_COMMON) \
						-std=c++11 \
						$(COMMON_DEFINES) \
						$(LINUX_FP_FLAGS) \
						$(GNU_CXXFLAGS_COMMON) \
						#$(BUILD_32BIT)

COVERAGE := -fprofile-arcs -ftest-coverage

LINUX_GNU_INCLUDES := $(LINUX_INCLUDES_COMMON) $(COMMON_INCLUDES)

DUMP = $(BUILD_ROOT)/mk/bin/empty.sh

MUNCH := $(BUILD_ROOT)/mk/bin/empty.sh
