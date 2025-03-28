/* #include <stdio.h>
#include <stdlib.h>
#include "seuilCout.h"


#define TAILLE 321600
int main () {
  FILE         *fpTest, *fpRes;

  int r,g,b;
  pixelType res;


  
  fpTest=fopen("/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierTest.ppm","r");
  fpRes=fopen("/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierRes.ppm","w");
  
  if (fpTest == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de test\n");
      return 1;
  }
  if (fpRes == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de résultat\n");
      return 1;
  }

  detectType resOut;
  validType validOut;  // Nouveau signal de validation
   
  for (int i = 0; i < LARGEUR*HAUTEUR; i++) {
    fscanf(fpTest,"%i",&r);
    fscanf(fpTest,"%i",&g);
    fscanf(fpTest,"%i",&b);
    //printf("r: %d g: %d b: %d\n",r,g,b);
    res.b = b;
    res.g = g;
    res.r = r;
    detectCoul(&resOut, &validOut, res);  // Appel modifié avec le paramètre de validation
    printf("Valeur de i : %d, valeur du resultat : %u, valide : %u\n", i, resOut, validOut);
    
    if (validOut) {  // Si le résultat est significatif
      if (resOut == ROUGE) {
        fprintf(fpRes,"%i\n", 255); 
        fprintf(fpRes,"%i\n", 0);   
        fprintf(fpRes,"%i\n", 0);  
      } else if (resOut == VERT) {
        fprintf(fpRes,"%i\n", 0); 
        fprintf(fpRes,"%i\n", 255); 
        fprintf(fpRes,"%i\n", 0);  
      } else if (resOut == BLEU) {
        fprintf(fpRes,"%i\n", 0);   
        fprintf(fpRes,"%i\n", 0);  
        fprintf(fpRes,"%i\n", 255);
      }
    } else {  // Si le résultat n'est pas significatif
      // Valeur par défaut (gris par exemple)
      fprintf(fpRes,"%i\n", 128);   
      fprintf(fpRes,"%i\n", 128);  
      fprintf(fpRes,"%i\n", 128);
    }
  }

  fclose(fpTest);
  fclose(fpRes);
  
//   printf ("Comparing against output data \n");
//   if (system("diff -w /home/etudiants/master1/adrien.failler/FPGA/tp3/fichierRes.ppm /home/etudiants/master1/adrien.failler/FPGA/tp3/fichierGOLD.ppm")) {
//     fprintf(stdout, "*******************************************\n");
//     fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
//     fprintf(stdout, "*******************************************\n");
//      return 1;
//   } else {
//     fprintf(stdout, "*******************************************\n");
//     fprintf(stdout, "PASS: The output matches the golden output!\n");
//     fprintf(stdout, "*******************************************\n");
//     return 0;
//  }
}

*/

#include <stdio.h>
#include <stdlib.h>
#include "seuilCout.h"
#define TAILLE 321600

int main() {
  FILE *fpTest, *fpRes;
  int r, g, b;
  pixelType pixIn, pixOut;
  detectType resultats;
  validType valid;
  
  fpTest = fopen("/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierTest.ppm", "r");
  fpRes = fopen("/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierRes.ppm", "w");
  
  if (fpTest == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de test\n");
      return 1;
  }
  if (fpRes == NULL) {
      printf("Erreur : Impossible d'ouvrir le fichier de résultat\n");
      return 1;
  }
  
  fprintf(fpRes, "P3\n");
  fprintf(fpRes, "%d %d\n", LARGEUR, HAUTEUR);
  fprintf(fpRes, "255\n");
  
  for (int i = 0; i < LARGEUR*HAUTEUR; i++) {
    fscanf(fpTest, "%i", &r);
    fscanf(fpTest, "%i", &g);
    fscanf(fpTest, "%i", &b);
    
    // Préparation du pixel d'entrée
    pixIn.r = r;
    pixIn.g = g;
    pixIn.b = b;
    
    traitCoul(&pixIn, &pixOut, &resultats, &valid);
    

    printf("Pixel %d: Entrée[R:%d,G:%d,B:%d] -> Sortie[R:%d,G:%d,B:%d], Détection:%u, Valide:%u\n", 
           i, pixIn.r, pixIn.g, pixIn.b, pixOut.r, pixOut.g, pixOut.b, resultats, valid);
    
    fprintf(fpRes, "%i\n", pixOut.r);
    fprintf(fpRes, "%i\n", pixOut.g);
    fprintf(fpRes, "%i\n", pixOut.b);
    
  }
  
  fclose(fpTest);
  fclose(fpRes);
  

  if (valid) {
    printf("Couleur dominante détectée: ");
    if (resultats == ROUGE) printf("ROUGE\n");
    else if (resultats == VERT) printf("VERT\n");
    else if (resultats == BLEU) printf("BLEU\n");
    else printf("AUTRE (%u)\n", resultats);
  } else {
    printf("Aucune couleur dominante détectée (résultat non valide)\n");
  }
  
  return 0;
}
