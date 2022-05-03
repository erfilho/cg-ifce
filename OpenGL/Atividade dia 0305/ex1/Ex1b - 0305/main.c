#include <stdio.h>
#include <GL/glut.h>

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(0.92, 0.0, 0.47);
        glVertex3f(-0.8, 0.0, 0.0);
        glColor3f(0.92, 0.0, 0.47);
        glVertex3f(-0.6, 0.0, 0.0);
        glColor3f(0.92, 0.0, 0.47);
        glVertex3f(-0.7, 0.4, 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3f(0.25, 0.67, 0.45);
        glVertex3f(-0.5, 0.0, 0.0);
        glColor3f(0.25, 0.67, 0.45);
        glVertex3f(-0.3, 0.0, 0.0);
        glColor3f(0.25, 0.67, 0.45);
        glVertex3f(-0.2, 0.4, 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
        glColor3f(0.25, 0.70, 0.84);
        glVertex3f(-0.1, 0.0, 0.0);
        glColor3f(0.25, 0.70, 0.84);
        glVertex3f(-0.1, 0.4, 0.0);
        glColor3f(0.25, 0.70, 0.84);
        glVertex3f(0.1, 0.4, 0.0);
        glColor3f(0.25, 0.70, 0.84);
        glVertex3f(0.1, 0.0, 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
        glColor3f(0.69, 0.05, 0.08);
        glVertex3f(0.2, 0.0, 0.0);
        glColor3f(0.69, 0.05, 0.08);
        glVertex3f(0.2, 0.4, 0.0);
        glColor3f(0.69, 0.05, 0.08);
        glVertex3f(0.4, 0.4, 0.0);
        glColor3f(0.69, 0.05, 0.08);
        glVertex3f(0.4, 0.03, 0.0);
        glColor3f(0.69, 0.05, 0.08);
        glVertex3f(0.39, 0.0, 0.0);
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
