/*
IFCE - INSTITUTO FEDERAL DO CEARÁ - CAMPUS TIANGUÁ
Aluno: Francisco Erineldo Xavier Filho
Curso: Bacharelado em Ciências da Computação - 5o Semestre
Professor: Nécio de Lima Veras
Disciplina: Computação Gráfica

Execício: Introdução ao OpenGL - Transformações Geométricas

1) E)
    Desenhe um objeto qualquer em duas dimensões e implemente a transformação geométrica de ESPELHAMENTO, demonstrando linhas que delimitam os eixos x e y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Definindo a constante para a movimentação da câmera
#define MOV_CAMERA 0.05

// Definindo constantes para auxiliar na exibição dos objetos
#define X 0
#define Y 1
#define Z 2

// Definindo os pontos para o quadrado
float quadrado[4][3] = {
    {1.0, 1.0, 0.0}, {1.0, 4.0, 0.0},
    {4.0, 4.0, 0.0}, {4.0, 1.0, 0.0}
};

// Definindo as funções para a alteração da câmera e translação
float camX = 0.0;
float camY = 0.0;
float camZ = 1.0;

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

void transX(void){
    for(int i = 0; i < 4; i++){
        quadrado[i][X] *= -1;
    }
}

void transY(void){
    for(int i = 0; i < 4; i++){
        quadrado[i][Y] *= -1;
    }
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
        case 'e': transX(); break;
        case 'E': transY(); break;
    }
    glutPostRedisplay();
}

void desenhaObj(void){
    glColor3f(1.0, 1.0, 1.0);
    
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(1.0, 0.8, 0.8);
            for(int i = 0; i < 4; i++){
                glVertex3f(quadrado[i][X], quadrado[i][Y], quadrado[i][Z]);
            }
        glEnd();
    glPopMatrix();
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

    desenhaObj();

    glFlush ();
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);

    glutCreateWindow("OpenGL e) Espelhamento");

    glutDisplayFunc(renderiza);

    glutKeyboardFunc(teclado);

    configuraJanela();

    glutMainLoop();

    return 0;
}