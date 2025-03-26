#include <stdio.h>
#include "exo1.h"
#define TAILLE 5
int main () {
  FILE         *fp;

  data_t in1, in2, output;
  coef_t c1 = 23;
  coef_t c2 = 50;
  
  fp=fopen("out.dat","w");
  

  int tab_test_in1[TAILLE]={13,15,10,1,19};
  int tab_test_in2[TAILLE]={9,20,5,8,32};
  
  for(int i = 0;i < TAILLE ;i++){
	  exo1(&output,c1,c2,tab_test_in1[i],tab_test_in2[i]);
  }
    
  fprintf(fp,"%i\n",output);
  
  fclose(fp);
  
  printf ("Comparing against output data \n");
//  if (system("diff -w out.dat out.gold.dat")) {
//
//	fprintf(stdout, "*******************************************\n");
//	fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
//	fprintf(stdout, "*******************************************\n");
//     return 1;
//  } else {
//	fprintf(stdout, "*******************************************\n");
//	fprintf(stdout, "PASS: The output matches the golden output!\n");
//	fprintf(stdout, "*******************************************\n");
//     return 0;
//  }
}
