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
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // desenhando um cubo com linhas brancas
    glRotatef(270, 1, 0, 0);
    glColor3f (1.0, 1.0, 1.0);
    glutWireCone(0.5, 1, 50, 50);
    glFlush ();
}

void confCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Primeira visualização
    //gluLookAt(1.0, 1.0, 2, 0.0, 0.5, 0, 0, 1, 0);
    // Segunda visualização
    //gluLookAt(1, 2, 0.5, 0.0, 0.50, 0, 0, 1, 0);
    // Terceira visualização
    gluLookAt(0.0, 0.0, 2, 0.0, 0.5, 0, 0, 1, 0);
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

    glutCreateWindow("OpenGL a) Exemplo 3d cone");

    glutDisplayFunc(draw);

    glutKeyboardFunc(teclado);

    init();

    glutMainLoop();
    return 0;
}
