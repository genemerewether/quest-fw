#!/bin/csh
# *******************************************************************************
# * Copyright 2013, by the California Institute of Technology.
# * ALL RIGHTS RESERVED. United States Government Sponsorship
# * acknowledged. Any commercial use must be negotiated with the Office
# * of Technology Transfer at the California Institute of Technology.
# *
# * This software may be subject to U.S. export control laws and
# * regulations. By accepting this document, the user agrees to comply
# * with all applicable U.S. export laws and regulations.  User has the 
# * responsibility to obtain export licenses,
# * or other export authority as may be required before exporting such
# * information to foreign countries or providing access to foreign
# * persons.
# *

if !($?BUILD_ROOT) then
    set curdir = "${PWD}"
    setenv BUILD_ROOT `dirname $0`/../..
    cd $BUILD_ROOT
    setenv BUILD_ROOT ${PWD}
    cd ${curdir}
endif

echo "BUILD_ROOT is: ${BUILD_ROOT}"

# Borrow some variables from build

setenv PYTHON_BASE `make -s -f ${BUILD_ROOT}/mk/makefiles/build_vars.mk print_python_base`
echo "PYTHON_BASE: ${PYTHON_BASE}"

setenv LD_LIBRARY_PATH ${PYTHON_BASE}/lib
setenv PYTHONPATH ${BUILD_ROOT}/Gse/src
setenv GSE_GENERATED_PATH ${BUILD_ROOT}/Gse/generated/BLIMPHEXREF
${PYTHON_BASE}/bin/python ${BUILD_ROOT}/Gse/bin/tinyseqgen.py $*
