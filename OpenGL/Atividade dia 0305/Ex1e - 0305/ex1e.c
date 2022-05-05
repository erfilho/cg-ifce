#include <stdio.h>
#include <GL/glut.h>
#include "objects.h"

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tTrianguloGL triangulo_0;
    triangulo_0.ponto[0][0] = -0.5;
    triangulo_0.ponto[0][1] = 0.9;
    triangulo_0.ponto[1][0] = 0.5;
    triangulo_0.ponto[1][1] = 0.9;
    triangulo_0.ponto[2][0] = 0.0;
    triangulo_0.ponto[2][1] = 0.3;

    tTrianguloGL triangulo_1;
    triangulo_1.ponto[0][0] = -1*triangulo_0.ponto[0][0];
    triangulo_1.ponto[0][1] = -1*triangulo_0.ponto[0][1];
    triangulo_1.ponto[1][0] = -1*triangulo_0.ponto[1][0];
    triangulo_1.ponto[1][1] = -1*triangulo_0.ponto[1][1];
    triangulo_1.ponto[2][0] = -1*triangulo_0.ponto[2][0];
    triangulo_1.ponto[2][1] = -1*triangulo_0.ponto[2][1];

    tTrianguloGL triangulo_2;
    triangulo_2.ponto[0][0] = triangulo_0.ponto[0][1];
    triangulo_2.ponto[0][1] = triangulo_0.ponto[0][0];
    triangulo_2.ponto[1][0] = triangulo_0.ponto[1][1];
    triangulo_2.ponto[1][1] = triangulo_0.ponto[1][0];
    triangulo_2.ponto[2][0] = triangulo_0.ponto[2][1];
    triangulo_2.ponto[2][1] = triangulo_0.ponto[2][0];

    tTrianguloGL triangulo_3;
    triangulo_3.ponto[0][0] = -1*triangulo_0.ponto[0][1];
    triangulo_3.ponto[0][1] = -1*triangulo_0.ponto[0][0];
    triangulo_3.ponto[1][0] = -1*triangulo_0.ponto[1][1];
    triangulo_3.ponto[1][1] = -1*triangulo_0.ponto[1][0];
    triangulo_3.ponto[2][0] = -1*triangulo_0.ponto[2][1];
    triangulo_3.ponto[2][1] = -1*triangulo_0.ponto[2][0];

    tQuadGL quad_0;
    quad_0.ponto[0][0] = -0.3;
    quad_0.ponto[0][1] = 0.7;
    quad_0.ponto[1][0] = 0.3;
    quad_0.ponto[1][1] = 0.7;
    quad_0.ponto[2][0] = 0.3;
    quad_0.ponto[2][1] = 0.0;
    quad_0.ponto[3][0] = -0.3;
    quad_0.ponto[3][1] = 0.0;

    tQuadGL quad_1;
    quad_1.ponto[0][0] = -0.3;
    quad_1.ponto[0][1] = 0.7;
    quad_1.ponto[1][0] = 0.3;
    quad_1.ponto[1][1] = 0.7;
    quad_1.ponto[2][0] = 0.3;
    quad_1.ponto[2][1] = 0.0;
    quad_1.ponto[3][0] = -0.3;
    quad_1.ponto[3][1] = 0.0;

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_0.ponto[0][0], triangulo_0.ponto[0][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_0.ponto[1][0], triangulo_0.ponto[1][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_0.ponto[2][0], triangulo_0.ponto[2][1], 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_1.ponto[0][0], triangulo_1.ponto[0][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_1.ponto[1][0], triangulo_1.ponto[1][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_1.ponto[2][0], triangulo_1.ponto[2][1], 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_2.ponto[0][0], triangulo_2.ponto[0][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_2.ponto[1][0], triangulo_2.ponto[1][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_2.ponto[2][0], triangulo_2.ponto[2][1], 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_3.ponto[0][0], triangulo_3.ponto[0][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_3.ponto[1][0], triangulo_3.ponto[1][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(triangulo_3.ponto[2][0], triangulo_3.ponto[2][1], 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(quad_0.ponto[0][0], quad_0.ponto[0][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(quad_0.ponto[1][0], quad_0.ponto[1][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(quad_0.ponto[2][0], quad_0.ponto[2][1], 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(quad_0.ponto[3][0], quad_0.ponto[3][1], 0.0);
    glEnd();

    /*
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 2; b++){
            
        }
    }
    */
    glFlush();
}

void teclado(unsigned char key, int posX, int posY){
    // Definindo a função para escutar o teclado
    if(key == 27){
        exit(1);
    }
}

void init(){
    // Definindo a cor de fundo da janela
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Declarando a função principal, argumentos necessários para a execução correta em alguns s.o's
int main(int argc, const char* argv[]){
    // Configuração e inicialização de uma janela
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    // Configurando a posição inicial da janela
    glutInitWindowPosition(100, 100);
    // Configurando o tamanho da janela
    glutInitWindowSize(480, 480);
    // Configurando o título da janela
    glutCreateWindow("OpenGL - Atividade 02 - E");
    
    // Registrando a função de callback
    glutDisplayFunc(draw);
    // Registrando a função de callback que vai responder pelo teclado
    glutKeyboardFunc(teclado);
    // Inicializando as variáveis de estado
    init();
    // Loop de tratamento de eventos
    glutMainLoop();

    return 0;

}