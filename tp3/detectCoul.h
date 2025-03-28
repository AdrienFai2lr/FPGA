//#include <stdint.h>

#define LARGEUR 400
#define HAUTEUR 268

#define ROUGE 2
#define VERT 1
#define BLEU 0

typedef unsigned char detectType;
typedef unsigned char validType;  // Type pour le signal de validation (1 bit)
typedef int colorType;

typedef struct{
    colorType r;
    colorType g;
    colorType b;
}pixelType;

void seuilCout(pixelType *pixOut,pixelType pixIn);

void detectCoul(detectType *res, validType *valid, pixelType pixIn);