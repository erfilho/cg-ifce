#include "objects.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

tPoligonoGL geraRetangulo(){
    tPoligonoGL retangulo;

    srand(time(NULL));

    retangulo.pontoA.X = 0;
    retangulo.pontoA.Y = 0;
    retangulo.pontoA.Z = 0;
    retangulo.pontoB.X = 0;
    retangulo.pontoB.Y = 0;
    retangulo.pontoB.Z = 0;
    retangulo.pontoC.X = 0;
    retangulo.pontoC.Y = 0;
    retangulo.pontoC.Z = 0;
    retangulo.pontoD.X = 0;
    retangulo.pontoD.Y = 0;
    retangulo.pontoD.Z = 0;

    retangulo.cor.r = (float)(rand() % 101)/100;
    retangulo.cor.g = (float)(rand() % 101)/100;
    retangulo.cor.b = (float)(rand() % 101)/100;

    return retangulo;
}
