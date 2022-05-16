#include "objects.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

tPoligonoGL geraRetangulo(){
    tPoligonoGL retangulo;

    srand(time(NULL));

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            retangulo.ponto[i][j] = 0.0;
        }
    }
    for(int i = 0; i < 3; i++){
        retangulo.cor[i] = (float)(rand() % 101)/100;
    }

    return retangulo;
}

void desenha_Pol(int pontos, tPoligonoGL polig, int tipo){
    glShadeModel(GL_FLAT);
    if(tipo == 1){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glBegin(GL_POLYGON);
        for(int i = 0; i < pontos; i++){
            glColor3f(polig.cor[0], polig.cor[1], polig.cor[2]);
            glVertex3f(polig.ponto[i][0], polig.ponto[i][1], polig.ponto[i][2]);
        }
    glEnd();
}
