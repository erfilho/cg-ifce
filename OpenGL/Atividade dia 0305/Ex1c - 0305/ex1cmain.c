#include <stdio.h>
#include "objects.h"
#include <GL/glut.h>

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tPoligonoGL hexagon;
    hexagon.ponto[0][0] = 0.4;
    hexagon.ponto[0][1] = -0.9;
    hexagon.ponto[0][2] = 0.0;
    hexagon.ponto[1][0] = 0.9;
    hexagon.ponto[1][1] = 0.0;
    hexagon.ponto[1][2] = 0.0;
    hexagon.ponto[2][0] = 0.4;
    hexagon.ponto[2][1] = 0.9;
    hexagon.ponto[2][2] = 0.0;
    hexagon.ponto[3][0] = -0.4;
    hexagon.ponto[3][1] = 0.9;
    hexagon.ponto[3][2] = 0.0;
    hexagon.ponto[4][0] = -0.9;
    hexagon.ponto[4][1] = 0.0;
    hexagon.ponto[4][2] = 0.0;
    hexagon.ponto[5][0] = -0.4;
    hexagon.ponto[5][1] = -0.9;
    hexagon.ponto[5][2] = 0.0;
    hexagon.cor[0] = 0.0;
    hexagon.cor[1] = 0.0;
    hexagon.cor[2] = 0.0;

    tTrianguloGL triangulo_0;
    triangulo_0.ponto[0][0] = -0.75;
    triangulo_0.ponto[0][1] = -0.45;
    triangulo_0.ponto[0][2] = 0.0;
    triangulo_0.ponto[1][0] = 0.75;
    triangulo_0.ponto[1][1] = -0.45;
    triangulo_0.ponto[1][2] = 0.0;
    triangulo_0.ponto[2][0] = 0.0;
    triangulo_0.ponto[2][1] = 0.95;
    triangulo_0.ponto[2][2] = 0.0;
    triangulo_0.cor[0] = 1.0;
    triangulo_0.cor[1] = 1.0;
    triangulo_0.cor[2] = 1.0;

    tTrianguloGL triangulo_1;
    triangulo_1.ponto[0][0] = -0.75;
    triangulo_1.ponto[0][1] = 0.45;
    triangulo_1.ponto[0][2] = 0.0;
    triangulo_1.ponto[1][0] = 0.0;
    triangulo_1.ponto[1][1] = -0.9;
    triangulo_1.ponto[1][2] = 0.0;
    triangulo_1.ponto[2][0] = 0.75;
    triangulo_1.ponto[2][1] = 0.45;
    triangulo_1.ponto[2][2] = 0.0;
    triangulo_1.cor[0] = 1.0;
    triangulo_1.cor[1] = 1.0;
    triangulo_1.cor[2] = 1.0;

    tTrianguloGL triangulo_2;
    triangulo_2.ponto[0][0] = -0.4;
    triangulo_2.ponto[0][1] = 0.9;
    triangulo_2.ponto[0][2] = 0.0;
    triangulo_2.ponto[1][0] = 0.0;
    triangulo_2.ponto[1][1] = 0.0;
    triangulo_2.ponto[1][2] = 0.0;
    triangulo_2.ponto[2][0] = 0.4;
    triangulo_2.ponto[2][1] = 0.9;
    triangulo_2.ponto[2][2] = 0.0;
    triangulo_2.cor[0] = 1.0;
    triangulo_2.cor[1] = 1.0;
    triangulo_2.cor[2] = 1.0;

    tTrianguloGL triangulo_3;
    triangulo_3.ponto[0][0] = -0.4;
    triangulo_3.ponto[0][1] = -0.9;
    triangulo_3.ponto[0][2] = 0.0;
    triangulo_3.ponto[1][0] = 0.4;
    triangulo_3.ponto[1][1] = -0.9;
    triangulo_3.ponto[1][2] = 0.0;
    triangulo_3.ponto[2][0] = 0.0;
    triangulo_3.ponto[2][1] = 0.0;
    triangulo_3.ponto[2][2] = 0.0;
    triangulo_3.cor[0] = 1.0;
    triangulo_3.cor[1] = 1.0;
    triangulo_3.cor[2] = 1.0;

    tTrianguloGL triangulo_4;
    triangulo_4.ponto[0][0] = -0.4;
    triangulo_4.ponto[0][1] = -0.225;
    triangulo_4.ponto[0][2] = 0.0;
    triangulo_4.ponto[1][0] = 0.4;
    triangulo_4.ponto[1][1] = -0.225;
    triangulo_4.ponto[1][2] = 0.0;
    triangulo_4.ponto[2][0] = 0.0;
    triangulo_4.ponto[2][1] = 0.5;
    triangulo_4.ponto[2][2] = 0.0;
    triangulo_4.cor[0] = 0.0;
    triangulo_4.cor[1] = 0.0;
    triangulo_4.cor[2] = 0.0;

    desenha_Pol(6, hexagon, 0);
    desenha_Triangulo(3, triangulo_0, 0);
    desenha_Triangulo(3, triangulo_1, 1);
    desenha_Triangulo(3, triangulo_2, 1);
    desenha_Triangulo(3, triangulo_3, 1);
    desenha_Triangulo(3, triangulo_4, 0);
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
    glutInitWindowSize(480, 480);
    // Configurando o título da janela
    glutCreateWindow("OpenGL - Atividade 02 - C");
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
