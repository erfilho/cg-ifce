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

void desenha_Triangulo(int pontos, tTrianguloGL triangulo){
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
        for(int i = 0; i < 3; i++){
            glColor3f(triangulo.cor[0], triangulo.cor[1], triangulo.cor[2]);
            glVertex3f(triangulo.ponto[i][0], triangulo.ponto[i][1], triangulo.ponto[i][2]);
        }
    glEnd();
}
