#include "objects.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

tPoligonoGL geraRetangulo(){
    tPoligonoGL retangulo;

    srand(time(NULL));

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 2; j++){
            retangulo.ponto[i][j] = 0.0;
        }
    }
    for(int i = 0; i < 3; i++){
        retangulo.cor[i] = (rand() % 101)/100;
    }

    return retangulo;
}
