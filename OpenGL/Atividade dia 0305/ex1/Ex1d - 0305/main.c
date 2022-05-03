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

    glShadeModel(GL_FLAT);
    glBegin(GL_LINES);
        for(int i = 0; i < 2; i++){
            glColor3f(linha0.cor[0], linha0.cor[1], linha0.cor[2]);
            glVertex3f(linha0.ponto[i][0], linha0.ponto[i][1], linha0.ponto[i][2]);
        }
    glEnd();

    glShadeModel(GL_FLAT);
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.93, 0.03, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.93, -0.03, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.03, 0.93, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-0.03, 0.93, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.7, 0.2, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.5, 0.6, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.3, 0.2, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.7, 0.2, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.5, 0.6, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.3, 0.2, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.7, -0.2, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.5, -0.6, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(-0.3, -0.2, 0.0);
    glEnd();

    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.7, -0.2, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.5, -0.6, 0.0);
        glColor3f(0.88, 0.57, 0.56);
        glVertex3f(0.3, -0.2, 0.0);
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
