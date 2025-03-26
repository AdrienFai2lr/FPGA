#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution7/sim/wrapc/apcc_db_adrien.failler/184361740740900567560/exo1.c_pre.c.tb.ld.bc ${1+"$@"}
