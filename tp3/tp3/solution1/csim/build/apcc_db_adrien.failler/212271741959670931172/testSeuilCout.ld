#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/tp3/tp3/solution1/csim/build/apcc_db_adrien.failler/212271741959670931172/testSeuilCout.ld.bc ${1+"$@"}
