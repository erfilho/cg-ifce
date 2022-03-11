#include "objetos.h"
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