#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/exo1_prj/solution1/csim/build/apcc_db_adrien.failler/99791740737562077957/exo1.ld.bc ${1+"$@"}
