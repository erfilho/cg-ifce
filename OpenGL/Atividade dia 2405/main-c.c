/*
IFCE - INSTITUTO FEDERAL DO CEARÁ - CAMPUS TIANGUÁ
Aluno: Francisco Erineldo Xavier Filho
Curso: Bacharelado em Ciências da Computação - 5o Semestre
Professor: Nécio de Lima Veras
Disciplina: Computação Gráfica

Execício: Introdução ao OpenGL - Transformações Geométricas

1) C)
    Desenhe um objeto qualquer em três dimensões e implemente. Para cada um dos três eixos, DUAS tranformações geométricas definidas pela própria biblioteca gráfica OPENGL. OBS: Não use um objeto pronto da GLUT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Definindo a constante para a movimentação da câmera
#define MOV_CAMERA 0.05
#define MOV_ANG 1.0

// Definindo constantes para auxílio na exibição de objetos
#define X 0
#define Y 1
#define Z 2

// Definindo as funções para a alteração da câmera e translação
float camX = 0.0;
float camY = 0.0;
float camZ = 1.0;
float transX = 0.0;
float transY = 0.0;
float transZ = 0.0;
float rotX = 0.0;
float rotY = 0.0;
float rotZ = 0.0;

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
        case 'x': rotX -= MOV_ANG; break;
        case 'X': rotX += MOV_ANG; break;
        case 'y': rotY -= MOV_ANG; break;
        case 'Y': rotY += MOV_ANG; break;
        case 'q': rotZ -= MOV_ANG; break;
        case 'Q': rotZ += MOV_ANG; break;
        case 'c': transX -= MOV_CAMERA; break;
        case 'C': transX += MOV_CAMERA; break;
        case 'v': transY -= MOV_CAMERA; break;
        case 'V': transY += MOV_CAMERA; break;
        case 'b': transZ -= MOV_CAMERA; break;
        case 'B': transZ += MOV_CAMERA; break;
    }
    glutPostRedisplay();
}

void desenhaObj(void){
    glColor3f(1.0, 1.0, 1.0);
    
    // Definindo os pontos para o desenho da parede do cubo
    float cubo[10][3] = {
        {-2, -2, -2}, {-2, 2, -2}, {2, -2, -2}, {2, 2, -2},
        {2, -2, 2}, {2, 2, 2}, {-2, -2, 2}, {-2, 2, 2}, 
        {-2, -2, -2}, {-2, 2, -2},
    };
    // Definido os pontos para o desenho do topo e do fundo do cubo
    float face_up_dw[8][3] = {
        {-2, 2, 2}, {2, 2, 2}, {2, 2, -2}, {-2, 2, -2},
        {-2, -2, 2}, {2, -2, 2}, {2, -2, -2}, {-2, -2, -2} 
    };

    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        for(int i = 0; i < 10; i++){
            glVertex3f(cubo[i][X], cubo[i][Y], cubo[i][Z]);
        }
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        for(int i = 0; i < 8; i++){
            glVertex3f(face_up_dw[i][X], face_up_dw[i][Y], face_up_dw[i][Z]);
        }
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
    
    glRotatef(rotX, 1.0, 0.0, 0.0);
    glRotatef(rotY, 0.0, 1.0, 0.0);
    glRotatef(rotZ, 0.0, 0.0, 1.0);
    glTranslatef(transX, transY, transZ);
    desenhaObj();

    glFlush ();
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);

    glutCreateWindow("OpenGL c) Duas transformacoes");

    glutDisplayFunc(renderiza);

    glutKeyboardFunc(teclado);

    configuraJanela();

    glutMainLoop();

    return 0;
}