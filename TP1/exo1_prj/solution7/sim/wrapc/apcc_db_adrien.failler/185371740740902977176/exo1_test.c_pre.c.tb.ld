#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution7/sim/wrapc/apcc_db_adrien.failler/185371740740902977176/exo1_test.c_pre.c.tb.ld.bc ${1+"$@"}
