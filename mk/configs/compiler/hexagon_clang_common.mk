HEX_CLANG_COMMON := -Wall -Wextra \
               -fno-builtin -fno-asm \
               \
               -Wno-unused-parameter \
               -Wno-long-long -v \
	       -fno-short-enums

DEPEND_FILE := -MMD -MP -MF

HEX_CLANG_CFLAGS_COMMON := $(HEX_CLANG_COMMON) -std=c99 \
				-pedantic \
				-Werror-implicit-function-declaration \
				-Wstrict-prototypes

HEX_CLANG_CXXFLAGS_COMMON := $(HEX_CLANG_COMMON) -fno-exceptions

# Special compiler flags to get around known AC warnings

AC_CC_FLAGS :=	-Wno-extra
AC_CXX_FLAGS :=
AC_HSM_FLAGS := -Wno-extra -Wno-parentheses
AC_PARAMS_FLAGS := -fno-strict-aliasing	-Wno-extra	

COMPILE_ONLY := -c

COMPILE_TO := -o
LIBRARY_TO := -o
LINK_BIN_PRE_TO := -o
LINK_BIN_POST_TO := -o
LINK_BIN_TO := -o

INCLUDE_PATH := -I


DEBUG := -g3

OPT_SPEED := -Os

OPT_NONE := -O0

SYMBOL_CHECK := $(PYTHON_BIN) $(BUILD_ROOT)/mk/bin/empty.py
