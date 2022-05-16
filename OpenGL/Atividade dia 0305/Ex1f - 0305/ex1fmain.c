#include <stdio.h>
#include <GL/glut.h>
#include "objects.h"

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100);

    tCorGL amarelo;
    amarelo.r = 1.0;
    amarelo.g = 1.0;
    amarelo.b = 0.0;

    tCorGL verde;
    verde.r = 0.0;
    verde.g = 1.0;
    verde.b = 0.0;

    tCorGL azul;
    azul.r = 0.0;
    azul.g = 0.0;
    azul.b = 1.0;

    tCorGL vermelho;
    vermelho.r = 1.0;
    vermelho.g = 0.0;
    vermelho.b = 0.0;

    tCorGL laranja;
    laranja.r = 1.0;
    laranja.g = 0.5;
    laranja.b = 0.0;

    desenha_circulo(10, 0, 0, laranja);
    desenha_circulo(10, 0, 14, amarelo);
    desenha_circulo(10, 14, 0, verde);
    desenha_circulo(10, 0, -14, azul);
    desenha_circulo(10, -14, 0, vermelho);

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
