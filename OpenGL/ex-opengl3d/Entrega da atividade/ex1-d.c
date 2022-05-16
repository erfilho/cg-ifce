/*
IFCE - Campus Tianguá
Aluno: Francisco Erineldo Xavier Filho

Atividade 01 - Introdução ao OpenGL3d

d) Abstraia um objeto 3D qualquer (diferente das questões anteriores), monte uma estrutura
de dados adequada para manipula-lo, e implemente-o de forma que o possamos ver sob vários
ângulos de visualização. Obs.: não use nenhum objeto pronto da biblioteca GLUT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

typedef struct {
    float ponto[8][3];
    float cor[3];
} tPoligonoGL;


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

void draw(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tPoligonoGL base;
    tPoligonoGL costas;
    tPoligonoGL perna1;
    tPoligonoGL perna2;
    tPoligonoGL perna3;
    tPoligonoGL perna4;

    base.cor[0] = 0.87;
    base.cor[1] = 0.72;
    base.cor[2] = 0.52;
    base.ponto[0][0] = 0.1;
    base.ponto[0][1] = 0.4;
    base.ponto[0][2] = 0.1;
    base.ponto[1][0] = 0.1;
    base.ponto[1][1] = 0.4;
    base.ponto[1][2] = 0.5;
    base.ponto[2][0] = 0.5;
    base.ponto[2][1] = 0.4;
    base.ponto[2][2] = 0.5;
    base.ponto[3][0] = 0.5;
    base.ponto[3][1] = 0.4;
    base.ponto[3][2] = 0.1;

    costas.cor[0] = 0.87;
    costas.cor[1] = 0.72;
    costas.cor[2] = 0.52;
    costas.ponto[0][0] = 0.1;
    costas.ponto[0][1] = 0.4;
    costas.ponto[0][2] = 0.1;
    costas.ponto[1][0] = 0.1;
    costas.ponto[1][1] = 1.0;
    costas.ponto[1][2] = 0.1;
    costas.ponto[2][0] = 0.5;
    costas.ponto[2][1] = 1.0;
    costas.ponto[2][2] = 0.1;
    costas.ponto[3][0] = 0.5;
    costas.ponto[3][1] = 0.4;
    costas.ponto[3][2] = 0.1;

    perna1.cor[0] = 0.87;
    perna1.cor[1] = 0.72;
    perna1.cor[2] = 0.52;
    perna1.ponto[0][0] = 0.1;
    perna1.ponto[0][1] = 0.4;
    perna1.ponto[0][2] = 0.5;
    perna1.ponto[1][0] = 0.15;
    perna1.ponto[1][1] = 0.4;
    perna1.ponto[1][2] = 0.5;
    perna1.ponto[2][0] = 0.15;
    perna1.ponto[2][1] = 0.1;
    perna1.ponto[2][2] = 0.5;
    perna1.ponto[3][0] = 0.1;
    perna1.ponto[3][1] = 0.1;
    perna1.ponto[3][2] = 0.5;

    perna2.cor[0] = 0.87;
    perna2.cor[1] = 0.72;
    perna2.cor[2] = 0.52;
    perna2.ponto[0][0] = 0.1;
    perna2.ponto[0][1] = 0.4;
    perna2.ponto[0][2] = 0.1;
    perna2.ponto[1][0] = 0.15;
    perna2.ponto[1][1] = 0.4;
    perna2.ponto[1][2] = 0.1;
    perna2.ponto[2][0] = 0.15;
    perna2.ponto[2][1] = 0.1;
    perna2.ponto[2][2] = 0.1;
    perna2.ponto[3][0] = 0.1;
    perna2.ponto[3][1] = 0.1;
    perna2.ponto[3][2] = 0.1;

    perna3.cor[0] = 0.87;
    perna3.cor[1] = 0.72;
    perna3.cor[2] = 0.52;
    perna3.ponto[0][0] = 0.45;
    perna3.ponto[0][1] = 0.4;
    perna3.ponto[0][2] = 0.5;
    perna3.ponto[1][0] = 0.5;
    perna3.ponto[1][1] = 0.4;
    perna3.ponto[1][2] = 0.5;
    perna3.ponto[2][0] = 0.5;
    perna3.ponto[2][1] = 0.1;
    perna3.ponto[2][2] = 0.5;
    perna3.ponto[3][0] = 0.45;
    perna3.ponto[3][1] = 0.1;
    perna3.ponto[3][2] = 0.5;

    perna4.cor[0] = 0.87;
    perna4.cor[1] = 0.72;
    perna4.cor[2] = 0.52;
    perna4.ponto[0][0] = 0.45;
    perna4.ponto[0][1] = 0.4;
    perna4.ponto[0][2] = 0.1;
    perna4.ponto[1][0] = 0.5;
    perna4.ponto[1][1] = 0.4;
    perna4.ponto[1][2] = 0.1;
    perna4.ponto[2][0] = 0.5;
    perna4.ponto[2][1] = 0.1;
    perna4.ponto[2][2] = 0.1;
    perna4.ponto[3][0] = 0.45;
    perna4.ponto[3][1] = 0.1;
    perna4.ponto[3][2] = 0.1;

    desenha_Pol(4, base, 0);
    desenha_Pol(4, costas, 0);
    desenha_Pol(4, perna1, 0);
    desenha_Pol(4, perna2, 0);
    desenha_Pol(4, perna3, 0);
    desenha_Pol(4, perna4, 0);

    glFlush ();
}

void confCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Primeira visualização
    gluLookAt(1.0, 1, 3.0, 0.0, 0.5, 0.0, 0.0, 1.0, 0.0);
    // Segunda visualização
    gluLookAt(0.0, 1.0, 3.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);
    // Terceira visualização
    gluLookAt(0.0, 2, 3.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);
}

void teclado(unsigned char key, int posX, int posY){
    // Código ASCII da tecla ESC
    if(key == 27){
        exit(1);
    }
}

void init(){
    // Definindo a cor de fundo da janela
    glClearColor(0.0, 0.0, 0.0, 0.0);
    confCamera();
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);

    glutCreateWindow("OpenGL d) Exemplo 3d cadeira");

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    init();

    glutMainLoop();
    return 0;
}