#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution1/sim/wrapc/apcc_db_adrien.failler/141221740739399776973/exo1.c_pre.c.tb.ld.bc ${1+"$@"}
