#include <stdio.h>
#include <stdlib.h>
#include "seuilCout.h"


#define TAILLE 321600
int main () {
  FILE         *fpTest, *fpRes;

  int r,g,b;
  pixelType res;


  
  fpTest=fopen("/home/etudiants/master1/adrien.failler/FPGA/tp2/TP2VHLS/fichierTest.ppm","r");
  fpRes=fopen("/home/etudiants/master1/adrien.failler/FPGA/tp2/TP2VHLS/fichierRes.ppm","w");
  
  if (fpTest == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de test\n");
      return 1;
  }
  if (fpRes == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de résultat\n");
      return 1;
  }

  pixelType resOut;
  for (int i = 0;i<LARGEUR*HAUTEUR;i++){
    fscanf(fpTest,"%i",&r);
    fscanf(fpTest,"%i",&g);
    fscanf(fpTest,"%i",&b);

    //printf("r: %d g: %d b: %d\n",r,g,b);
    res.b=b;
    res.g=g;
    res.r=r;
    seuilCout(&resOut,res);

    //printf("%d\n",resOut.b);
    fprintf(fpRes,"%i\n",resOut.r);
    fprintf(fpRes,"%i\n",resOut.g);
    fprintf(fpRes,"%i\n",resOut.b);

  }

  fclose(fpTest);
  fclose(fpRes);
  
  printf ("Comparing against output data \n");
  if (system("diff -w /home/etudiants/master1/adrien.failler/FPGA/tp2/TP2VHLS/fichierRes.ppm /home/etudiants/master1/adrien.failler/FPGA/tp2/TP2VHLS/fichierGOLD.ppm")) {
    fprintf(stdout, "*******************************************\n");
    fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
    fprintf(stdout, "*******************************************\n");
     return 1;
  } else {
    fprintf(stdout, "*******************************************\n");
    fprintf(stdout, "PASS: The output matches the golden output!\n");
    fprintf(stdout, "*******************************************\n");
    return 0;
 }
}
