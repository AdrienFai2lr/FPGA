#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution1/sim/wrapc/apcc_db_adrien.failler/142321740739402229127/exo1_test.c_pre.c.tb.ld.bc ${1+"$@"}
