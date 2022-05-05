#include "objetos-ex5.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


tPolygon setQuadrado(int pA_x, int pA_y){
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

tPolygon setRetangulo(int pA_x, int pA_y){
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
    int pA_x, pA_y;
    switch(type){
        case 1:
            pA_x = 1 + (rand() % 14);
            pA_y = 1 + (rand() % 14);
            tPolygon quadrado = setQuadrado(pA_x, pA_y);
            return quadrado;
            break;
        case 2:
            pA_x = 1 + (rand() % 13);
            pA_y = 1 + (rand() % 15);
            tPolygon retangulo = setRetangulo(pA_x, pA_y);
            return retangulo;
            break;
        default:
            printf("Errno");
            break;
    }
}

tPolygon tgTranslate(tPolygon poligon, int tX, int tY){
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

tPolygon tgScale(tPolygon poligon, int tX, int tY){
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

void polCoordinates(tPolygon poligon){
    printf("A[%d, %d] B[%d, %d] \nC[%d, %d] D[%d, %d]\n", poligon.pointA.x, poligon.pointA.y, poligon.pointB.x, poligon.pointB.y, poligon.pointC.x, poligon.pointC.y, poligon.pointD.x, poligon.pointD.y);
}

void polDraw(tPolygon poligon){
    int max_X = poligon.pointD.x + 2;
    int max_Y = poligon.pointC.y + 2;
    
    for(int y = 0; y < max_Y; y++){
        for(int x = 0; x < max_X; x++){
            if(x == poligon.pointA.x && y == poligon.pointA.y){
                printf(" A ");
            } else if(x == poligon.pointB.x && y == poligon.pointB.y){
                printf(" B ");
            } else if(x == poligon.pointC.x && y == poligon.pointC.y){
                printf(" C ");
            } else if(x == poligon.pointD.x && y == poligon.pointD.y){
                printf(" D ");
            } else if((x >= poligon.pointA.x && x <= poligon.pointD.x) && (y >= poligon.pointA.y && y <= poligon.pointD.y)){
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}