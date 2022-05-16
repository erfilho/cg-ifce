#include "objects.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void desenha_circulo(int raio, float posX, float posY, tCorGL cor){
    float calx, caly;
    glBegin(GL_POLYGON);
    for(float i = 0; i < 10; i += 0.01){
        calx = raio * cos(i);
        caly = raio * sin(i);
        glColor3f(cor.r, cor.g, cor.b);
        glVertex3f(posX + calx, posY + caly, 0.0);
    }
    glEnd();
}
