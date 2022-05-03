#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "objects.h"

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tPoligonoGL retangulo = geraRetangulo();

    retangulo.pontoA.X = -0.2;
    retangulo.pontoA.Y = -0.5;
    retangulo.pontoA.Z = 0;
    retangulo.pontoB.X = -0.2;
    retangulo.pontoB.Y = 0.2;
    retangulo.pontoB.Z = 0;
    retangulo.pontoC.X = 0.2;
    retangulo.pontoC.Y = 0.2;
    retangulo.pontoC.Z = 0;
    retangulo.pontoD.X =  0.2;
    retangulo.pontoD.Y = -0.5;
    retangulo.pontoD.Z =  0;

    glShadeModel(GL_FLAT);
    glBegin(GL_POLYGON);
        glColor3f(retangulo.cor.r, retangulo.cor.g, retangulo.cor.b);
        glVertex3f(retangulo.pontoA.X, retangulo.pontoA.Y, retangulo.pontoA.Z);
        glColor3f(retangulo.cor.r, retangulo.cor.g, retangulo.cor.b);
        glVertex3f(retangulo.pontoB.X, retangulo.pontoB.Y, retangulo.pontoB.Z);
        glColor3f(retangulo.cor.r, retangulo.cor.g, retangulo.cor.b);
        glVertex3f(retangulo.pontoC.X, retangulo.pontoC.Y, retangulo.pontoC.Z);
        glColor3f(retangulo.cor.r, retangulo.cor.g, retangulo.cor.b);
        glVertex3f(retangulo.pontoD.X, retangulo.pontoD.Y, retangulo.pontoD.Z);
    glEnd();

    glFlush();
}

void teclado(unsigned char key, int posX, int posY){
    // Código ASCII da tecla ESC
    if(key == 27){
        exit(1);
    }
}

void init(){
    srand(time(NULL));
    // Definindo a cor preta para o fundo da tela
    glClearColor((float)(rand()%101)/100, (float)(rand()%101)/100, (float)(rand()%101)/100, 0.0);
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
    glutCreateWindow("OpenGL - Atividade 02 - A");

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
