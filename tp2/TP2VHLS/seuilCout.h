//#include <stdint.h>

#define LARGEUR 400
#define HAUTEUR 268
typedef int colorType;

typedef struct{
    colorType r;
    colorType g;
    colorType b;
}pixelType;



void seuilCout(pixelType *pixOut,pixelType pixIn);
