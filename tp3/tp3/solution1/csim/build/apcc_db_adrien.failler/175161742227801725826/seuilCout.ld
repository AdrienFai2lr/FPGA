#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/etudiants/master1/adrien.failler/FPGA/tp3/tp3/solution1/csim/build/apcc_db_adrien.failler/175161742227801725826/seuilCout.ld.bc ${1+"$@"}
