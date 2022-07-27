/*
IFCE - INSTITUTO FEDERAL DO CEARÁ - CAMPUS TIANGUÁ
Aluno: Francisco Erineldo Xavier Filho
Curso: Bacharelado em Ciências da Computação - 5o Semestre
Professor: Nécio de Lima Veras
Disciplina: Computação Gráfica

Execício: Introdução ao OpenGL - Transformações Geométricas

1) D)
    Desenhe, na mesma cena, três objetos diferentes, em duas ou três dimensões e aplique a transformação geométrica para mudança de Escala(SCALING) individualmente nos objetos(faça com que o clique do mouse em um objeto ative a tranformação geométrica ou diferentes teclas façam as transformações nos diferentes objetos)
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Definindo a constante para a movimentação da câmera
#define MOV_CAMERA 0.05
#define SCALE_CAM 0.25

// Definindo as funções para a alteração da câmera e translação
float camX = 0.0;
float camY = 0.0;
float camZ = 1.0;

float esferaX = 1.0, esferaY = 1.0, esferaZ = 1.0;
float coneX = 1.0, coneY = 1.0, coneZ = 1.0;
float roscaX = 1.0, roscaY = 1.0, roscaZ = 1.0;

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
        case 'e': 
            esferaX -= SCALE_CAM; 
            esferaY -= SCALE_CAM; 
            esferaZ -= SCALE_CAM; 
            break;
        case 'E': 
            esferaX += SCALE_CAM;
            esferaY += SCALE_CAM;
            esferaZ += SCALE_CAM; 
            break;
        case 'c': 
            coneX -= SCALE_CAM; 
            coneY -= SCALE_CAM; 
            coneZ -= SCALE_CAM; 
            break;
        case 'C': 
            coneX += SCALE_CAM;
            coneY += SCALE_CAM;
            coneZ += SCALE_CAM; 
            break;
        case 'r': 
            roscaX -= SCALE_CAM; 
            roscaY -= SCALE_CAM; 
            roscaZ -= SCALE_CAM; 
            break;
        case 'R': 
            roscaX += SCALE_CAM;
            roscaY += SCALE_CAM;
            roscaZ += SCALE_CAM; 
            break;
    }
    glutPostRedisplay();
}

void desenhaRosquinha(void){
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
        glTranslatef(-3, 0.0, 0.0);
        glutSolidTorus(0.75, 1.0, 20, 20); 
    glPopMatrix();
}

void desenhaCone(void){
    glColor3f(1.0, 0.6, 0.6);

    glPushMatrix();
        glTranslatef(0.0, 3.0, 0.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glutSolidCone(1.5, 3, 20, 20);
    glPopMatrix();
}

void desenhaEsfera(void){
    glColor3f(0.5, 0.0, 0.75);

    glPushMatrix();
        glTranslatef(3.0, 0.0, 0.0);
        glutSolidSphere(1.5, 20.0, 20.0);
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

    glPushMatrix();
        glScalef(roscaX, roscaY, roscaZ);
        desenhaRosquinha();
    glPopMatrix();
    
    glPushMatrix();
        glScalef(coneX, coneY, coneZ);
        desenhaCone();
    glPopMatrix();
    
    glPushMatrix();
        glScalef(esferaX, esferaY, esferaZ);
        desenhaEsfera();
    glPopMatrix();

    glFlush ();
}

int main(int argc, const char* argv[]){
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);

    glutCreateWindow("OpenGL d) Varios objetos");

    glutDisplayFunc(renderiza);

    glutKeyboardFunc(teclado);

    configuraJanela();

    glutMainLoop();

    return 0;
}