#ifndef OBJETOS_H
#define OBJETOS_H

    typedef struct {
        float x;
        float y;
    } tPoint;

    typedef struct {
        tPoint pointA;
        tPoint pointB;
        tPoint pointC;
        tPoint pointD;
    } tPolygon;

    tPolygon setQuadrado(float pA_x, float pA_y);
    tPolygon setRetangulo(float pA_x, float pA_y);
    tPolygon polFactory(int type);
    tPolygon tgTranslate(tPolygon poligon, float tX, float tY);
    tPolygon tgScale(tPolygon poligon, float tX, float tY);
    tPolygon tgRotate(tPolygon poligon, float rotateDegree);
    int degFactory();
    float maxX(tPolygon poligon);
    float maxY(tPolygon poligon);
    void polCoordinates(tPolygon poligon);
    void polDraw(tPolygon poligon);
#endif