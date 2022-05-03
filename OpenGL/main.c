//
//  main.c
//  exemploOpenGL_2D
//
//  Created by Necio de Lima Veras on 28/11/18.
//  Copyright © 2018 Necio de Lima Veras. All rights reserved.
//
// arquivos de cabeÁalho
#include <stdlib.h>
#include <GL/GLUT.h> 

// funÁ„o de desenho
void draw ()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // desenhando o plano cartesiano 3D
    glBegin (GL_LINES);
    // eixo X
    glColor3f ( 0.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glColor3f ( 1.0, 0.0, 0.0);
    glVertex3f( 2.0, 0.0, 0.0);
    // eixo Y
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.0,-2.0, 0.0);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    // eixo Z
    glColor3f (0.0,  0.0, 0.0);
    glVertex3f(0.0,  0.0,-2.0);
    glColor3f (0.0,  0.0, 1.0);
    glVertex3f(0.0,  0.0, 2.0);
    glEnd ();
    
    // desenhando um cubo com linhas brancas
    glColor3f (1.0, 1.0, 1.0);
    glutWireCube (1.5);
    
    glFlush ();
}

// configura o campo de visualizaÁ„o
void confCamera ()
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45,1.0, 0.1, 10);
    //glOrtho (-2, 2, -2, 2, 1, 5);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    gluLookAt (1,1,2, 0,0,0, 0,1,0);
}

void teclado(unsigned char key, int posX, int posY){
    
    if (key == 27) //O codigo ASC da tecla ESC
        exit(1);
    
}


// funÁ„o para inicializar as variaveis de estado
void init ()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    confCamera ();
    glEnable (GL_DEPTH_TEST);
}

// funÁ„o principal
int main (int argc, const char * argv[])
{
    // configurando e exibindo uma janela
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow ("Exemplo 04: campo de visualização");
    
    // registrando funÁ„o de callback
    glutDisplayFunc (draw);
    
    //callback que responde pelo teclado
    glutKeyboardFunc(teclado);
    
    // inicializaÁ„o das vari·veis de estado
    init ();
    
    // loop de tratamento de eventos
    glutMainLoop ();
    
    return 0;
}
