#ifndef OBJECTS_H
#define OBJECT_H
    typedef struct {
        float X;
        float Y;
        float Z;
    } tPontoGL;

    typedef struct {
        float r;
        float g;
        float b;
    } tCorGL;

    typedef struct {
        tPontoGL pontoA;
        tPontoGL pontoB;
        tPontoGL pontoC;
        tPontoGL pontoD;
        tPontoGL pontoE;
        tCorGL cor;
    } tPoligonoGL;

    typedef struct {
        float ponto[3][2];
    } tTrianguloGL;

    typedef struct {
        float ponto[4][2];
    } tQuadGL;

    tPoligonoGL geraRetangulo();
    tTrianguloGL inverte_xT(tTrianguloGL pol);
    tTrianguloGL inverte_yT(tTrianguloGL pol);
    tQuadGL inverte_xQ(tQuadGL pol);
    tQuadGL inverte_yQ(tQuadGL pol);
#endif