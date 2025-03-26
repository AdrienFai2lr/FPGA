############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project exo1_prj
set_top exo1
add_files exo1.c
add_files exo1.h
add_files -tb exo1_test.c
add_files -tb out.gold.dat
open_solution "solution2" -flow_target vivado
set_part {xc7z020clg484-1}
create_clock -period 30 -name default
config_cosim -rtl vhdl -tool xsim
#source "./exo1_prj/solution2/directives.tcl"
csim_design
csynth_design
cosim_design -rtl vhdl -tool xsim
export_design -format ip_catalog
