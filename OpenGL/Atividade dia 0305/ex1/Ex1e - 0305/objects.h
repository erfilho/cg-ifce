#ifndef OBJECTS_H
#define OBJECT_H
    typedef struct {
        float X;
        float Y;
        float Z;
    } tPontoGL;

    typedef struct {
        tPontoGL pontoA;
        tPontoGL pontoB;
        tPontoGL pontoC;
        tPontoGL pontoD;
        tPontoGL pontoE;
    } tPoligonoGL;

    typedef struct {
        float ponto[3][2];
    } tTrianguloGL;

    typedef struct {
        float ponto[4][2];
    } tQuadGL;

    tTrianguloGL inverte_xT(tTrianguloGL pol);
    tTrianguloGL inverte_yT(tTrianguloGL pol);
    tQuadGL inverte_xQ(tQuadGL pol);
    tQuadGL inverte_yQ(tQuadGL pol);
#endif