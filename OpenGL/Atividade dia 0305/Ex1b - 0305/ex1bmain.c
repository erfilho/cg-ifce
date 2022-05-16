#include <stdio.h>
#include "objects.h"
#include <GL/glut.h>

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tTrianguloGL triangulo_0;
    triangulo_0.ponto[0][0] = -0.8;
    triangulo_0.ponto[0][1] = 0.0;
    triangulo_0.ponto[0][2] = 0.0;
    triangulo_0.ponto[1][0] = -0.6;
    triangulo_0.ponto[1][1] = 0.0;
    triangulo_0.ponto[1][2] = 0.0;
    triangulo_0.ponto[2][0] = -0.7;
    triangulo_0.ponto[2][1] = 0.4;
    triangulo_0.ponto[2][2] = 0.0;
    triangulo_0.cor[0] = 0.92;
    triangulo_0.cor[1] = 0.0;
    triangulo_0.cor[2] = 0.47;

    tTrianguloGL triangulo_1;
    triangulo_1.ponto[0][0] = -0.5;
    triangulo_1.ponto[0][1] = 0.0;
    triangulo_1.ponto[0][2] = 0.0;
    triangulo_1.ponto[1][0] = -0.3;
    triangulo_1.ponto[1][1] = 0.0;
    triangulo_1.ponto[1][2] = 0.0;
    triangulo_1.ponto[2][0] = -0.2;
    triangulo_1.ponto[2][1] = 0.4;
    triangulo_1.ponto[2][2] = 0.0;
    triangulo_1.cor[0] = 0.25;
    triangulo_1.cor[1] = 0.67;
    triangulo_1.cor[2] = 0.45;

    tPoligonoGL quadrado_0;
    quadrado_0.ponto[0][0] = -0.1;
    quadrado_0.ponto[0][1] = 0.0;
    quadrado_0.ponto[0][2] = 0.0;
    quadrado_0.ponto[1][0] = -0.1;
    quadrado_0.ponto[1][1] = 0.4;
    quadrado_0.ponto[1][2] = 0.0;
    quadrado_0.ponto[2][0] = 0.1;
    quadrado_0.ponto[2][1] = 0.4;
    quadrado_0.ponto[2][2] = 0.0;
    quadrado_0.ponto[3][0] = 0.1;
    quadrado_0.ponto[3][1] = 0.0;
    quadrado_0.ponto[3][2] = 0.0;
    quadrado_0.cor[0] = 0.25;
    quadrado_0.cor[1] = 0.70;
    quadrado_0.cor[2] = 0.84;

    tPoligonoGL quadrado_1;
    quadrado_1.ponto[0][0] = 0.2;
    quadrado_1.ponto[0][1] = 0.0;
    quadrado_1.ponto[0][2] = 0.0;
    quadrado_1.ponto[1][0] = 0.2;
    quadrado_1.ponto[1][1] = 0.4;
    quadrado_1.ponto[1][2] = 0.0;
    quadrado_1.ponto[2][0] = 0.4;
    quadrado_1.ponto[2][1] = 0.4;
    quadrado_1.ponto[2][2] = 0.0;
    quadrado_1.ponto[3][0] = 0.4;
    quadrado_1.ponto[3][1] = 0.03;
    quadrado_1.ponto[3][2] = 0.0;
    quadrado_1.ponto[4][0] = 0.39;
    quadrado_1.ponto[4][1] = 0.0;
    quadrado_1.ponto[4][2] = 0.0;
    quadrado_1.cor[0] = 0.69;
    quadrado_1.cor[1] = 0.05;
    quadrado_1.cor[2] = 0.08;

    desenha_Triangulo(3, triangulo_0, 0);
    desenha_Triangulo(3, triangulo_1, 0);
    desenha_Pol(4, quadrado_0, 0);
    desenha_Pol(5, quadrado_1, 0);

    glFlush();
}

void teclado(unsigned char key, int posX, int posY){
    // Código ASCII da tecla ESC
    if(key == 27){
        exit(1);
    }
}

void init(){
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
    glutInitWindowSize(960, 480);
    // Configurando o título da janela
    glutCreateWindow("OpenGL - Atividade 02 - B");
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
