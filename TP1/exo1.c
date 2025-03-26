#include "exo1.h"

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


