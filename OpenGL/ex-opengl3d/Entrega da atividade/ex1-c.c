/*
IFCE - Campus Tianguá
Aluno: Francisco Erineldo Xavier Filho

Atividade 01 - Introdução ao OpenGL3d

Desenhe uma pirâmide com base pentagonal (sem o auxílio de objetos prontos da GLUT) e manipule sua visualização sob diversos ângulos (pelo menos três diferentes visões);
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.2, 0.1, 0.4);
        glVertex3f(0.4, 0.1, 0.0);
        glVertex3f(0.8, 0.1, 0.4);
        glVertex3f(0.8, 0.1, 0.8);
        glVertex3f(0.2, 0.1, 0.8);
    glEnd();

    glColor3f(0.5, 0.5, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.2, 0.1, 0.4);
        glVertex3f(0.2, 0.1, 0.8);
        glVertex3f(0.4, 0.8, 0.4);
    glEnd();

    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(0.4, 0.1, 0.0);
        glVertex3f(0.2, 0.1, 0.4);
        glVertex3f(0.4, 0.8, 0.4);
    glEnd();

    glColor3f(0.4, 0.2, 0.9);
    glBegin(GL_POLYGON);
        glVertex3f(0.4, 0.1, 0.0);
        glVertex3f(0.8, 0.1, 0.4);
        glVertex3f(0.4, 0.8, 0.4);
    glEnd();

    glColor3f(0.9, 0.4, 0.4);
    glBegin(GL_POLYGON);
        glVertex3f(0.8, 0.1, 0.4);
        glVertex3f(0.8, 0.1, 0.8);
        glVertex3f(0.4, 0.8, 0.4);
    glEnd();

    glColor3f(0.1, 0.9, 0.9);
    glBegin(GL_POLYGON);
        glVertex3f(0.8, 0.1, 0.8);
        glVertex3f(0.2, 0.1, 0.8);
        glVertex3f(0.4, 0.8, 0.4);
    glEnd();

    glFlush ();
}

void confCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Primeira visualização
    gluLookAt(0.0, 0.5, 3.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);
    // Segunda visualização
    gluLookAt(2.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // Terceira visualização
    gluLookAt(0.5, 0.5, 2.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);
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

    glutCreateWindow("OpenGL c) Exemplo 3d pirâmide");

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    init();

    glutMainLoop();
    return 0;
}
