#ifndef OBJETOS_H
#define OBJETOS_H

    typedef struct {
        int x;
        int y;
    } tPoint;

    typedef struct {
        tPoint pointA;
        tPoint pointB;
        tPoint pointC;
        tPoint pointD;
    } tPolygon;

    tPolygon setQuadrado(int pA_x, int pA_y);
    tPolygon setRetangulo(int pA_x, int pA_y);
    tPolygon polFactory(int type);
    tPolygon tgTranslate(tPolygon poligon, int tX, int tY);

#endif