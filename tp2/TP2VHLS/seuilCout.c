#include "seuilCout.h"

void seuilCout(pixelType *pixOut,pixelType pixIn){
    
    colorType valR,valG,valB;
    colorType resR,resG,resB;
    //recuperation des entre et recopie
    valB=pixIn.b;
    valG=pixIn.g;
    valR=pixIn.r;

    /*
    //comparaison des valeur de valR
    if(valR<valG || valR<valB){
        resR=0;
    }else{
        resR=valR;
    }
    //comparaison des valeur de valG
    if(valG<valR || valG<valB){
        resG=0;
    }else{
        resG=valG;
    }
    //comparaison des valeur de valB
    if(valB<valG || valB < valR){
        resB=0;
    }else{
        resB=valB;
    }
    */

    //variable = condition ? valeur_si_vrai : valeur_si_faux;
    resR = (valR<valG || valR<valB)? 0 : valR;
    resG = (valG<valR || valG<valB)? 0 : valG;
    resB = (valB<valR || valB<valG)? 0 : valB;

    pixOut->b=resB;
    pixOut->g=resG;
    pixOut->r=resR;


}
