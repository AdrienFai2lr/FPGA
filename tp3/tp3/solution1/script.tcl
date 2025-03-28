############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project tp3
set_top traitCoul
add_files seuilCout.c
add_files seuilCout.h
add_files -tb testSeuilCout.c -cflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg484-1}
create_clock -period 15 -name default
source "./tp3/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
