#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "objects.h"

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tPoligonoGL retangulo = geraRetangulo();

    retangulo.ponto[0][0] = -0.2;
    retangulo.ponto[0][1] = -0.5;
    retangulo.ponto[0][2] = 0.0;
    retangulo.ponto[1][0] = -0.2;
    retangulo.ponto[1][1] = 0.2;
    retangulo.ponto[1][2] = 0.0;
    retangulo.ponto[2][0] = 0.2;
    retangulo.ponto[2][1] = 0.2;
    retangulo.ponto[2][2] = 0.0;
    retangulo.ponto[3][0] = 0.2;
    retangulo.ponto[3][1] = -0.5;
    retangulo.ponto[3][2] = 0.0;

    desenha_Pol(4, retangulo, 0);

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
