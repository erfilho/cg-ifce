#include "objetos.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


tPolygon setQuadrado(float pA_x, float pA_y){
    tPolygon newQuadrado;

    newQuadrado.pointA.x = pA_x;
    newQuadrado.pointA.y = pA_y;

    newQuadrado.pointB.x = pA_x + 4;
    newQuadrado.pointB.y = pA_y;

    newQuadrado.pointC.x = pA_x;
    newQuadrado.pointC.y = pA_y + 4;

    newQuadrado.pointD.x = pA_x + 4;
    newQuadrado.pointD.y = pA_y + 4;

    return newQuadrado;
}

tPolygon setRetangulo(float pA_x, float pA_y){
    tPolygon newRetangulo;

    newRetangulo.pointA.x = pA_x;
    newRetangulo.pointA.y = pA_y;

    newRetangulo.pointB.x = pA_x + 4;
    newRetangulo.pointB.y = pA_y;

    newRetangulo.pointC.x = pA_x;
    newRetangulo.pointC.y = pA_y + 2;

    newRetangulo.pointD.x = pA_x + 4;
    newRetangulo.pointD.y = pA_y + 2;

    return newRetangulo;
}

tPolygon polFactory(int type){
    srand(time(NULL));
    float pA_x, pA_y;
    switch(type){
        case 1:
            pA_x = 1 + (rand() % 10);
            pA_y = 1 + (rand() % 10);
            tPolygon quadrado = setQuadrado(pA_x, pA_y);
            return quadrado;
            break;
        case 2:
            pA_x = 1 + (rand() % 8);
            pA_y = 1 + (rand() % 10);
            tPolygon retangulo = setRetangulo(pA_x, pA_y);
            return retangulo;
            break;
        default:
            printf("Errno");
            break;
    }
}

tPolygon tgTranslate(tPolygon poligon, float tX, float tY){
    tPolygon t_Poligon = poligon;
    
    t_Poligon.pointA.x += tX;
    t_Poligon.pointA.y += tY;

    t_Poligon.pointB.x += tX;
    t_Poligon.pointB.y += tY;

    t_Poligon.pointC.x += tX;
    t_Poligon.pointC.y += tY;

    t_Poligon.pointD.x += tX;
    t_Poligon.pointD.y += tY;
    
    return t_Poligon;
}

tPolygon tgScale(tPolygon poligon, float tX, float tY){
    tPolygon t_Poligon = poligon;

    t_Poligon.pointA.x *= tX;
    t_Poligon.pointA.y *= tY;

    t_Poligon.pointB.x *= tX;
    t_Poligon.pointB.y *= tY;
    
    t_Poligon.pointC.x *= tX;
    t_Poligon.pointC.y *= tY;
    
    t_Poligon.pointD.x *= tX;
    t_Poligon.pointD.y *= tY;

    return t_Poligon;
}

tPolygon tgRotate(tPolygon poligon, float rotateDegree){
    tPolygon t_Poligon = poligon;

    // Transformando de graus para radianos
    rotateDegree = (rotateDegree*M_PI)/180;

    float cos_deg = cos(rotateDegree);
    float sen_deg = sin(rotateDegree);
    float _sen_deg = -sin(rotateDegree);

    /* 
    [
        cos sen
        -sen cos
    ]
    */

    t_Poligon.pointA.x = (poligon.pointA.x * cos_deg) + (poligon.pointA.y * _sen_deg);
    t_Poligon.pointA.y = (poligon.pointA.y * cos_deg) + (poligon.pointA.x * sen_deg);
    t_Poligon.pointB.x = (poligon.pointB.x * cos_deg) + (poligon.pointB.y * _sen_deg);
    t_Poligon.pointB.y = (poligon.pointB.y * cos_deg) + (poligon.pointB.x * sen_deg);
    t_Poligon.pointC.x = (poligon.pointC.x * cos_deg) + (poligon.pointC.y * _sen_deg);
    t_Poligon.pointC.y = (poligon.pointC.y * cos_deg) + (poligon.pointC.x * sen_deg);
    t_Poligon.pointD.x = (poligon.pointD.x * cos_deg) + (poligon.pointD.y * _sen_deg);
    t_Poligon.pointD.y = (poligon.pointD.y * cos_deg) + (poligon.pointD.x * sen_deg);

    t_Poligon.pointA.x = floor(t_Poligon.pointA.x);
    t_Poligon.pointA.y = floor(t_Poligon.pointA.y);
    t_Poligon.pointB.x = floor(t_Poligon.pointB.x);
    t_Poligon.pointB.y = floor(t_Poligon.pointB.y);
    t_Poligon.pointC.x = floor(t_Poligon.pointC.x);
    t_Poligon.pointC.y = floor(t_Poligon.pointC.y);
    t_Poligon.pointD.x = floor(t_Poligon.pointD.x);
    t_Poligon.pointD.y = floor(t_Poligon.pointD.y);

    return t_Poligon;
};

int degFactory(){
    int deg = (rand() % 360) + 1;
    return deg;
}

float maxX(tPolygon poligon){
    float max_X = 0;
    float vetor[4] = {poligon.pointA.x, poligon.pointB.x, poligon.pointC.x, poligon.pointD.x};
    for(int i = 0; i < 4; i++){
        if(fabs(vetor[i]) > max_X){
            max_X = fabs(vetor[i]);
        }
    }
    return max_X;
}

float maxY(tPolygon poligon){
    float max_Y = 0;
    float vetor[4] = {poligon.pointA.y, poligon.pointB.y, poligon.pointC.y, poligon.pointD.y};
    for(int i = 0; i < 4; i++){
        if(fabs(vetor[i]) > max_Y){
            max_Y = fabs(vetor[i]);
        }
    }
    return max_Y;
}

void polCoordinates(tPolygon poligon){
    printf("A[%.2f, %.2f] B[%.2f, %.2f] \nC[%.2f, %.2f] D[%.2f, %.2f]\n", poligon.pointA.x, poligon.pointA.y, poligon.pointB.x, poligon.pointB.y, poligon.pointC.x, poligon.pointC.y, poligon.pointD.x, poligon.pointD.y);
}

void polDraw(tPolygon poligon){
    float tamX = (maxX(poligon)*2) + 2;
    float tamY = (maxY(poligon)*2) + 2;
    float Ox = tamX/2.0;
    float Oy = tamY/2.0;

    for(float y = tamY; y >= 0; y--){
        for(float x = 0.0; x <= tamX; x++){
            if(x == (poligon.pointA.x + Ox) && y == (poligon.pointA.y + Oy)){
                printf(" A ");
            } else if(x == (poligon.pointB.x + Ox) && y == (poligon.pointB.y + Oy)){
                printf(" B ");
            } else if(x == (poligon.pointC.x + Ox) && y == (poligon.pointC.y + Oy)){
                printf(" C ");
            } else if(x == (poligon.pointD.x + Ox) && y == (poligon.pointD.y + Oy)){
                printf(" D ");
            } else if(y == Oy){
                printf("---");
            } else if(x == Ox){
                printf(" | ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}