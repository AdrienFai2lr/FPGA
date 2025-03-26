#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/TP1/exo1_prj/solution1/csim/build/apcc_db_adrien.failler/112891741083594815500/exo1_test.ld.bc ${1+"$@"}
