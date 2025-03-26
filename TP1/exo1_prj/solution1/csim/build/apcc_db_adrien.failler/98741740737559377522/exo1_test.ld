#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution1/csim/build/apcc_db_adrien.failler/98741740737559377522/exo1_test.ld.bc ${1+"$@"}
