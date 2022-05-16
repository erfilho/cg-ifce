/*
IFCE - Campus Tiangu�
Aluno: Francisco Erineldo Xavier Filho

Atividade 01 - Introdu��o ao OpenGL3d

b) Desenhe um paralelep�pedo (sem o aux�lio de objetos prontos da GLUT) e manipule sua visualiza��o sob diversos �ngulos (pelo menos tr�s diferentes vis�es);
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.1, 0.1, 0.1);
        glVertex3f(0.1, 0.9, 0.1);
        glVertex3f(0.9, 0.9, 0.1);
        glVertex3f(0.9, 0.1, 0.1);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.1, 0.1, 0.9);
        glVertex3f(0.1, 0.9, 0.9);
        glVertex3f(0.9, 0.9, 0.9);
        glVertex3f(0.9, 0.1, 0.9);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.1, 0.9, 0.1);
        glVertex3f(0.1, 0.9, 0.9);
        glVertex3f(0.9, 0.9, 0.9);
        glVertex3f(0.9, 0.9, 0.1);
    glEnd();

    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(0.1, 0.1, 0.1);
        glVertex3f(0.1, 0.1, 0.9);
        glVertex3f(0.9, 0.1, 0.9);
        glVertex3f(0.9, 0.1, 0.1);
    glEnd();

    glColor3f(0.0, 1.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(0.1, 0.1, 0.1);
        glVertex3f(0.1, 0.9, 0.1);
        glVertex3f(0.1, 0.9, 0.9);
        glVertex3f(0.1, 0.1, 0.9);
    glEnd();

    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(0.9, 0.1, 0.1);
        glVertex3f(0.9, 0.9, 0.1);
        glVertex3f(0.9, 0.9, 0.9);
        glVertex3f(0.9, 0.1, 0.9);
    glEnd();

    glFlush ();
}

void confCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Primeira visualiza��o
    gluLookAt(0.0, 0.5, 3.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);
    // Segunda visualiza��o
    gluLookAt(1.5, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // Terceira visualiza��o
    gluLookAt(2.5, 2.5, 3.0, 0.5, 0.5, 0.5, 0.0, 1.0, 0.0);
}

void teclado(unsigned char key, int posX, int posY){
    // C�digo ASCII da tecla ESC
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

    glutCreateWindow("OpenGL b) Exemplo 3d paralelepipedo");

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    init();

    glutMainLoop();
    return 0;
}
