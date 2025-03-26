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
