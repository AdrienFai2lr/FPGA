#include "seuilCout.h"

void seuilCout(pixelType *pixOut,pixelType pixIn){
    
    colorType valR,valG,valB;
    colorType resR,resG,resB;

   
    //recuperation des entre et recopie
    valB=pixIn.b;
    valG=pixIn.g;
    valR=pixIn.r;

    //variable = condition ? valeur_si_vrai : valeur_si_faux;
    resR = (valR<valG || valR<valB)? 0 : valR;
    resG = (valG<valR || valG<valB)? 0 : valG;
    resB = (valB<valR || valB<valG)? 0 : valB;

    pixOut->b=resB;
    pixOut->g=resG;
    pixOut->r=resR;


}

void detectCoul(detectType *resultats, validType *valid, pixelType pixIn){

    colorType valR = pixIn.r;
    colorType valG = pixIn.g;
    colorType valB = pixIn.b;

    static int cptPix = 0;
    static int cptR = 0;
    static int cptG = 0;
    static int cptB = 0;

    colorType resR = 0;
    colorType resG = 0;
    colorType resB = 0;

    *valid = 0;
    
    
    if (valR > valG && valR > valB) {
        resR = valR;  
        cptR++;
    }
    else if (valG > valR && valG > valB) {
        resG = valG;  
        cptG++;
    }
    else if (valB > valR && valB > valG) {
        resB = valB;  
        cptB++;
    }
    else if (valR == valG && valR > valB) {

        resR = valR;
        resG = valG;
        cptR++;
        cptG++;
    }
    else if (valR == valB && valR > valG) {

        resR = valR;
        resB = valB;
        cptR++;
        cptB++;
    }
    else if (valG == valB && valG > valR) {

        resG = valG;
        resB = valB;
        cptG++;
        cptB++;
    }
    else if (valR == valG && valR == valB) {

        resR = valR;
        resG = valG;
        resB = valB;
        
        cptR++;
        cptG++;
        cptB++;
    }

    cptPix++;
    
    if (cptR > cptG && cptR > cptB) {
        *resultats = ROUGE;
        *valid = 1;  
    }
    else if (cptG > cptR && cptG > cptB) {
        *resultats = VERT;
        *valid = 1;  
    }
    else if (cptB > cptR && cptB > cptG) {
        *resultats = BLEU;
        *valid = 1;
    }
    else if (cptR == cptG && cptR > cptB) {
        *resultats = ROUGE;
        *valid = 1;
    }
    else if (cptR == cptB && cptR > cptG) { 
        *resultats = ROUGE;
        *valid = 1;
    }
    else if (cptG == cptB && cptG > cptR) {
        *resultats = VERT;
        *valid = 1;
    }
    else {

        *resultats = 0;
        *valid = 0;
    }
    //printf("%d,%d,%d \n",cptR,cptG,cptB);
    if (cptPix == HAUTEUR * LARGEUR)
    {
        cptPix = 0;
        cptB = 0;
        cptG = 0;
        cptR = 0;
    }
}



void traitCoul(pixelType *pixIn, pixelType *pixOut, detectType *resultats, validType *valid) {
    // Appel à la première fonction pour le seuillage des couleurs
    seuilCout(pixOut, pixIn);
    
    // Appel à la deuxième fonction pour la détection de couleur
    detectCoul(resultats, valid, pixIn);
}
