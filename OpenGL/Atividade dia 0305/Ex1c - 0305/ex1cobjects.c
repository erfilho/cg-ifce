#include "objects.h"
#include <GL/glut.h>
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

tTrianguloGL inverte_xT(tTrianguloGL pol){
    tTrianguloGL polig;

    for(int i = 0; i < 3; i++){
            for(int a = 0; a < 3; a++){
                if(a == 0){
                    polig.ponto[i][a] = -1*(pol.ponto[i][a]);
                } else {
                    polig.ponto[i][a] = pol.ponto[i][a];
                }
            }
            polig.cor[i] = pol.cor[i];
    }

    return polig;
}

tTrianguloGL inverte_yT(tTrianguloGL pol){
    tTrianguloGL polig;

    for(int i = 0; i < 3; i++){
            for(int a = 0; a < 3; a++){
                if(a == 1){
                    polig.ponto[i][a] = -1*(pol.ponto[i][a]);
                } else {
                    polig.ponto[i][a] = pol.ponto[i][a];
                }
            }
            polig.cor[i] = pol.cor[i];
    }

    return polig;
}

void desenha_Linha(int pontos, tLinhaGL linha){
    glShadeModel(GL_FLAT);
    glBegin(GL_LINES);
        for(int i = 0; i < pontos; i++){
            glColor3f(linha.cor[0], linha.cor[1], linha.cor[2]);
            glVertex3f(linha.ponto[i][0], linha.ponto[i][1], linha.ponto[i][2]);
        }
    glEnd();
}

void desenha_Triangulo(int pontos, tTrianguloGL triangulo, int tipo){
    glShadeModel(GL_FLAT);
    if(tipo == 1){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glBegin(GL_TRIANGLES);
        for(int i = 0; i < pontos; i++){
            glColor3f(triangulo.cor[0], triangulo.cor[1], triangulo.cor[2]);
            glVertex3f(triangulo.ponto[i][0], triangulo.ponto[i][1], triangulo.ponto[i][2]);
        }
    glEnd();
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
