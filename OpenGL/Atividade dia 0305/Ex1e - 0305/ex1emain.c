#include <stdio.h>
#include <GL/glut.h>
#include "objects.h"

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    tPoligonoGL triangulo_0;
    triangulo_0.ponto[0][0] = -0.5;
    triangulo_0.ponto[0][1] = 0.9;
    triangulo_0.ponto[0][2] = 0.0;
    triangulo_0.ponto[1][0] = 0.5;
    triangulo_0.ponto[1][1] = 0.9;
    triangulo_0.ponto[1][2] = 0.0;
    triangulo_0.ponto[2][0] = 0.0;
    triangulo_0.ponto[2][1] = 0.3;
    triangulo_0.ponto[2][2] = 0.0;
    triangulo_0.cor[0] = 1.0;
    triangulo_0.cor[1] = 0.0;
    triangulo_0.cor[2] = 0.0;

    tPoligonoGL quad_0;
    quad_0.ponto[0][0] = -0.3;
    quad_0.ponto[0][1] = 0.7;
    quad_0.ponto[0][2] = 0.0;
    quad_0.ponto[1][0] = 0.3;
    quad_0.ponto[1][1] = 0.7;
    quad_0.ponto[1][2] = 0.0;
    quad_0.ponto[2][0] = 0.3;
    quad_0.ponto[2][1] = 0.0;
    quad_0.ponto[2][2] = 0.0;
    quad_0.ponto[3][0] = -0.3;
    quad_0.ponto[3][1] = 0.0;
    quad_0.ponto[3][2] = 0.0;
    quad_0.cor[0] = 1.0;
    quad_0.cor[1] = 0.0;
    quad_0.cor[2] = 0.0;

    tPoligonoGL quad_4;
    quad_4.ponto[0][0] = -0.2;
    quad_4.ponto[0][1] = 0.6;
    quad_4.ponto[0][2] = 0.0;
    quad_4.ponto[1][0] = 0.2;
    quad_4.ponto[1][1] = 0.6;
    quad_4.ponto[1][2] = 0.0;
    quad_4.ponto[2][0] = 0.2;
    quad_4.ponto[2][1] = 0.0;
    quad_4.ponto[2][2] = 0.0;
    quad_4.ponto[3][0] = -0.2;
    quad_4.ponto[3][1] = 0.0;
    quad_4.ponto[3][2] = 0.0;
    quad_4.cor[0] = 1.0;
    quad_4.cor[1] = 1.0;
    quad_4.cor[2] = 1.0;

    tPoligonoGL quad_1 = rotate_r(4, quad_0);
    tPoligonoGL quad_2 = rotate_r(4, quad_1);
    tPoligonoGL quad_3 = rotate_r(4, quad_2);

    tPoligonoGL quad_5 = rotate_r(4, quad_4);
    tPoligonoGL quad_6 = rotate_r(4, quad_5);
    tPoligonoGL quad_7 = rotate_r(4, quad_6);

    tPoligonoGL triangulo_1 = rotate_r(3, triangulo_0);
    tPoligonoGL triangulo_2 = rotate_r(3, triangulo_1);
    tPoligonoGL triangulo_3 = rotate_r(3, triangulo_2);

    desenha_Pol(3, triangulo_0, 0);
    desenha_Pol(3, triangulo_1, 0);
    desenha_Pol(3, triangulo_2, 0);
    desenha_Pol(3, triangulo_3, 0);
    desenha_Pol(4, quad_0, 0);
    desenha_Pol(4, quad_1, 0);
    desenha_Pol(4, quad_2, 0);
    desenha_Pol(4, quad_3, 0);
    desenha_Pol(4, quad_4, 0);
    desenha_Pol(4, quad_5, 0);
    desenha_Pol(4, quad_6, 0);
    desenha_Pol(4, quad_7, 0);

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
