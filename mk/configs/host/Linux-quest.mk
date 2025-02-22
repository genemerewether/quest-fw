include $(BUILD_ROOT)/mk/configs/host/Linux-common.mk
# This assumes that you have installed lxml and cheetah to the python distribution. Probably requires sudo access.

export PYTHON_BASE ?= /usr
export PYTHON_BIN := $(PYTHON_BASE)/bin/python
export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):$(PYTHON_BASE)/lib

export LXML_PATH :=
export CHEETAH_COMPILE ?= cheetah-compile
export MARKDOWN ?= $(PYTHON_BASE)/bin/markdown_py -x markdown.extensions.extra -x markdown.extensions.codehilite

JOBS := -j `nproc`

TURBOJPEG := /opt/tools/quest/turbojpeg
TURBOJPEG_INCLUDE := -I$(TURBOJPEG)/include

TI_CCS_DIR := /opt/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS

#LINUX_FP_FLAGS := -mmmx -msse -msse2 -msse3 -mssse3

ifeq ($(TARGET_8074),)
HEXAGON_V_ARCH := v60
TARGET_SOC := 8096
TARGET_DSP := sdsp
HEXAGON_SDK_ROOT := /opt/tools/quest/Qualcomm/Hexagon_SDK/3.1
HEXAGON_ARM_SYSROOT := /opt/tools/quest/Qualcomm/aarch64-toolchain/sysroots/aarch64-oe-linux/
INDIGO_ARM_SYSROOT := $(HEXAGON_ARM_SYSROOT)

LINARO_FP_FLAGS := -DARM_NEON -DENABLE_NEON -mfpu=neon-vfpv4 -mfloat-abi=softfp

MULTIARCH_TUPLE :=

RPATH_SYSROOT_CMD := -L$(INDIGO_ARM_SYSROOT)/usr/lib/ -Wl,-rpath-link=$(INDIGO_ARM_SYSROOT)/usr/lib/ -Wl,-rpath-link=$(INDIGO_ARM_SYSROOT)/lib
# arbitrary convention - for use in inc.mk
INCLUDE_ARM_SYSROOTS := $(INDIGO_ARM_SYSROOT)

ARM_CC_BASE := /opt/tools/quest/Qualcomm/aarch64-toolchain/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi
CC := $(ARM_CC_BASE)-gcc
CXX := $(ARM_CC_BASE)-g++
GCOV := $(ARM_CC_BASE)-gcov
AR := $(ARM_CC_BASE)-ar
HEXAGON_TOOLS_ROOT := $(HEXAGON_SDK_ROOT)/tools/HEXAGON_Tools/8.0.08/Tools

CHECK_LINK_BIN_LINKER := -Wl,-z=muldefs
else
HEXAGON_V_ARCH := v55
TARGET_SOC := 8074
TARGET_DSP := adsp
HEXAGON_SDK_ROOT := /opt/tools/quest/Qualcomm/Hexagon_SDK/3.0
ARM_CC_BASE := $(HEXAGON_SDK_ROOT)/gcc-linaro-4.9-2014.11-x86_64_arm-linux-gnueabihf_linux/bin/arm-linux-gnueabihf
CC :=  $(ARM_CC_BASE)-gcc
CXX := $(ARM_CC_BASE)-g++
GCOV := $(ARM_CC_BASE)-gcov
AR := $(ARM_CC_BASE)-ar
HEXAGON_TOOLS_ROOT := /opt/tools/quest/Qualcomm/HEXAGON_Tools/7.2.12/Tools
HEXAGON_ARM_SYSROOT := /opt/tools/quest/Qualcomm/qrlinux_sysroot
INDIGO_ARM_SYSROOT :=  /opt/tools/quest/Qualcomm/indigo_sysroot
TURBOJPEG_LIB := $(TURBOJPEG)/lib/libturbojpeg.a

LINARO_FP_FLAGS := -DARM_NEON -DENABLE_NEON -mfpu=neon -mfloat-abi=hard

MULTIARCH_TUPLE := arm-linux-gnueabihf

RPATH_SYSROOT_CMD := -L$(HEXAGON_ARM_SYSROOT)/usr/lib/ -L$(INDIGO_ARM_SYSROOT)/usr/lib/ -L$(INDIGO_ARM_SYSROOT)/usr/lib/$(MULTIARCH_TUPLE)/ -Wl,-rpath-link=$(HEXAGON_ARM_SYSROOT)/lib/ -Wl,-rpath-link=$(INDIGO_ARM_SYSROOT)/lib/ -Wl,-rpath-link=$(HEXAGON_ARM_SYSROOT)/usr/lib/ -Wl,-rpath-link=$(INDIGO_ARM_SYSROOT)/usr/lib/
# arbitrary convention - for use in inc.mk
INCLUDE_ARM_SYSROOTS := $(INDIGO_ARM_SYSROOT)

CHECK_LINK_BIN_LINKER := -Xlinker,-z,muldefs
endif

CRC := $(BUILD_ROOT)/mk/bin/run_file_crc.sh

NM:= /usr/bin/nm

SYMBOL_CHECK := echo
