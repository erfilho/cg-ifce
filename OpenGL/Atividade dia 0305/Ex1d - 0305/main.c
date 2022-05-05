#include <stdio.h>
#include "objects.h"
#include <GL/glut.h>

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tLinhaGL linha0;
    linha0.ponto[0][0] = -1.0;
    linha0.ponto[0][1] = 0.0;
    linha0.ponto[0][2] = 0.0;
    linha0.ponto[1][0] = 1.0;
    linha0.ponto[1][1] = 0.0;
    linha0.ponto[1][2] = 0.0;
    linha0.cor[0] = 0.0;
    linha0.cor[1] = 0.0;
    linha0.cor[2] = 0.0;

    tLinhaGL linha1;
    linha1.ponto[0][0] = 0.0;
    linha1.ponto[0][1] = 1.0;
    linha1.ponto[0][2] = 0.0;
    linha1.ponto[1][0] = 0.0;
    linha1.ponto[1][1] = -1.0;
    linha1.ponto[1][2] = 0.0;
    linha1.cor[0] = 0.0;
    linha1.cor[1] = 0.0;
    linha1.cor[2] = 0.0;

    tTrianguloGL triangulo0;
    triangulo0.ponto[0][0] = 0.93;
    triangulo0.ponto[0][1] = 0.03;
    triangulo0.ponto[0][2] = 0.0;
    triangulo0.ponto[1][0] = 1.0;
    triangulo0.ponto[1][1] = 0.0;
    triangulo0.ponto[1][2] = 0.0;
    triangulo0.ponto[2][0] = 0.93;
    triangulo0.ponto[2][1] = -0.03;
    triangulo0.ponto[2][2] = 0.0;
    triangulo0.cor[0] = 0.0;
    triangulo0.cor[1] = 0.0;
    triangulo0.cor[2] = 0.0;

    tTrianguloGL triangulo1;
    triangulo1.ponto[0][0] = 0.03;
    triangulo1.ponto[0][1] = 0.93;
    triangulo1.ponto[0][2] = 0.0;
    triangulo1.ponto[1][0] = 0.0;
    triangulo1.ponto[1][1] = 1.0;
    triangulo1.ponto[1][2] = 0.0;
    triangulo1.ponto[2][0] = -0.03;
    triangulo1.ponto[2][1] = 0.93;
    triangulo1.ponto[2][2] = 0.0;
    triangulo1.cor[0] = 0.0;
    triangulo1.cor[1] = 0.0;
    triangulo1.cor[2] = 0.0;


    tTrianguloGL triangulo2;
    triangulo2.ponto[0][0] = -0.7;
    triangulo2.ponto[0][1] = 0.2;
    triangulo2.ponto[0][2] = 0.0;
    triangulo2.ponto[1][0] = -0.5;
    triangulo2.ponto[1][1] = 0.6;
    triangulo2.ponto[1][2] = 0.0;
    triangulo2.ponto[2][0] = -0.3;
    triangulo2.ponto[2][1] = 0.2;
    triangulo2.ponto[2][2] = 0.0;
    triangulo2.cor[0] = 0.88;
    triangulo2.cor[1] = 0.57;
    triangulo2.cor[2] = 0.56;

    tTrianguloGL triangulo3 = inverte_xT(triangulo2);
    tTrianguloGL triangulo4 = inverte_yT(triangulo3);
    tTrianguloGL triangulo5 = inverte_xT(triangulo4);

    desenha_Linha(2, linha0);
    desenha_Linha(2, linha1);
    desenha_Triangulo(3, triangulo0, 0);
    desenha_Triangulo(3, triangulo1, 0);
    desenha_Triangulo(3, triangulo2, 1);
    desenha_Triangulo(3, triangulo3, 1);
    desenha_Triangulo(3, triangulo4, 1);
    desenha_Triangulo(3, triangulo5, 1);

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
    glutCreateWindow("OpenGL - Atividade 02 - D");

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
