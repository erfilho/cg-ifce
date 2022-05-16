/*
IFCE - Campus Tianguá
Aluno: Francisco Erineldo Xavier Filho

Atividade 01 - Introdução ao OpenGL3d

a) Desenhe com auxílio da GLUT, um cone (wireframe) e manipule sua visualização sob três diferentes ângulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void){
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glutSolidCone(100, 100, 50, 50);
    glFlush();
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
}

void confCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, 0.5, 20);

    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 1.0, 0, 50, 10, 5, 5, 5);
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(480, 480);
    glutCreateWindow("OpenGL a) Exemplo 3d cone");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    confCamera();
    glutDisplayFunc(draw);
    glutKeyboardFunc(teclado);
    init();
    glutMainLoop();
    return 0;
}