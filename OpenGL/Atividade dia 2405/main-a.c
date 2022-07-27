/*
IFCE - INSTITUTO FEDERAL DO CEARÁ - CAMPUS TIANGUÁ
Aluno: Francisco Erineldo Xavier Filho
Curso: Bacharelado em Ciências da Computação - 5o Semestre
Professor: Nécio de Lima Veras
Disciplina: Computação Gráfica

Execício: Introdução ao OpenGL - Transformações Geométricas

1) A)
    Desenhe um objeto qualquer em duas dimensões e implemente a transformação geométrica de TRANSLAÇÃO definida pela própria biblioteca gráfica OPENGL
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Definindo a constante para a movimentação da câmera
#define MOV_CAMERA 0.1

// Definindo as funções para a alteração da câmera e translação
float camX = 0.0;
float camY = 0.0;
float camZ = 1.0;
float TransPosX = 0.0;
float TransPosY = 0.0;


void configuraJanela(){
    // Definindo a cor de fundo da janela
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void configuraCamera(){
    // Configurando o campo de visualização
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);

    // Configurando a visualização
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void teclado(unsigned char key, int posX, int posY){
    // Código ASCII da tecla ESC
    if(key == 27){
        exit(1);
    }
    switch(key){
        case 'w': camY += MOV_CAMERA; break;  
        case 's': camY -= MOV_CAMERA; break;
        case 'a': camX -= MOV_CAMERA; break;
        case 'd': camX += MOV_CAMERA; break;
        case 'z': camZ -= MOV_CAMERA; break;
        case 'Z': camZ += MOV_CAMERA; break;
        case 'x': TransPosX -= MOV_CAMERA; break;
        case 'X': TransPosX += MOV_CAMERA; break;
        case 'y': TransPosY -= MOV_CAMERA; break;
        case 'Y': TransPosY += MOV_CAMERA; break;
    }
    glutPostRedisplay();
}

void desenhaObj(void){
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-5.0, -5.0, 0.0);
        glVertex3f(-5.0, 5.0, 0.0);
        glVertex3f(5.0, 5.0, 0.0);
        glVertex3f(5.0, -5.0, 0.0);
    glEnd();
}

void desenhaLinha3d(void){
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-20.0, 0.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(20.0, 0.0, 0.0);

        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -20.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 20.0, 0.0);

        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, -20.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 20.0);
    glEnd();
}

void renderiza(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    configuraCamera();

    desenhaLinha3d();

    glTranslatef(TransPosX, TransPosY, 0.0);

    desenhaObj();

    glFlush ();
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);

    glutCreateWindow("OpenGL a) Translacao");

    glutDisplayFunc(renderiza);

    glutKeyboardFunc(teclado);

    configuraJanela();

    glutMainLoop();

    return 0;
}