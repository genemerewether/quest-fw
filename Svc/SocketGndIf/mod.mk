#
#   Copyright 2004-2008, by the California Institute of Technology.
#   ALL RIGHTS RESERVED. United States Government Sponsorship
#   acknowledged.
#
#

# This is a template for the mod.mk file that goes in each module
# and each module's subdirectories.
# With a fresh checkout, "make gen_make" should be invoked. It should also be
# run if any of the variables are updated. Any unused variables can 
# be deleted from the file.

# There are some standard files that are included for reference

SRC =

HDR =				SvcSocketGndIfImpl.hpp

SRC_LINUX = 		SvcSocketGndIfImpl.cpp

SRC_SDFLIGHT = 		SvcSocketGndIfImpl.cpp

SRC_CYGWIN =		SvcSocketGndIfImpl.cpp

SRC_DARWIN =        SvcSocketGndIfImpl.cpp

SRC_RASPIAN = 		SvcSocketGndIfImpl.cpp

SRC_LINUXRT = SvcSocketGndIfImpl.cpp
