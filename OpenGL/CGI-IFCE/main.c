//
//  main.c
//  exemploOpenGL_2D
//
//  Created by Necio de Lima Veras on 28/11/18.
//  Copyright © 2018 Necio de Lima Veras. All rights reserved.
//
// arquivos de cabe¡alho
#include <stdlib.h>
#include <GL/glut.h>

// fun¡Ño de desenho
void draw ()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.2, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.5, -0.2, 0.0);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();

    glFlush ();
}

void teclado(unsigned char key, int posX, int posY){
    if (key == 27) //O codigo ASC da tecla ESC
        exit(1);
}


// fun¡Ño para inicializar as variaveis de estado
void init ()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

// fun¡Ño principal
int main (int argc, const char * argv[])
{
    // configurando e exibindo uma janela
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow ("Exemplo 04: campo de visualizaÁ„o");

    // registrando fun¡Ño de callback
    glutDisplayFunc (draw);

    //callback que responde pelo teclado
    glutKeyboardFunc(teclado);

    // inicializa¡Ño das vari∑veis de estado
    init ();

    // loop de tratamento de eventos
    glutMainLoop ();

    return 0;
}
