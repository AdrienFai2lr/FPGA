// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
# 1 "/home/etudiants/master1/adrien.failler/FPGA/exo1.c"
# 1 "/home/etudiants/master1/adrien.failler/FPGA/exo1.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 150 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/home/etudiants/master1/adrien.failler/FPGA/exo1.c" 2
# 1 "/home/etudiants/master1/adrien.failler/FPGA/exo1.h" 1
typedef int coef_t;
typedef int data_t;

void exo1 (
  data_t *res,
  coef_t c1,
  coef_t c2,
  data_t in1,
  data_t in2
  );
# 2 "/home/etudiants/master1/adrien.failler/FPGA/exo1.c" 2

void exo1 (
  data_t *res,
  coef_t c1,
  coef_t c2,
  data_t in1,
  data_t in2
  ) {

 data_t temp1,temp2,temp3,temp4;

 temp1 = in1*c1;
 temp2 = in2*c2;

 temp3 = temp1*temp2;

 if(temp1>temp2) {
  temp4 = temp3;}
 else{
  temp4 = -temp3;}

 *res=temp4;
  }
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_exo1_ir(int *, int, int, int, int);
#ifdef __cplusplus
extern "C"
#endif
void exo1_hw_stub(int *res, int c1, int c2, int in1, int in2){
exo1(res, c1, c2, in1, in2);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void refine_signal_handler();
#ifdef __cplusplus
extern "C"
#endif
void apatb_exo1_sw(int *res, int c1, int c2, int in1, int in2){
refine_signal_handler();
apatb_exo1_ir(res, c1, c2, in1, in2);
return ;
}
#endif
# 24 "/home/etudiants/master1/adrien.failler/FPGA/exo1.c"

