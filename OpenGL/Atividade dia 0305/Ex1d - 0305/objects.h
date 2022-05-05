#ifndef OBJECTS_H
#define OBJECT_H

    typedef struct {
        float ponto[6][3];
        float cor[3];
    } tPoligonoGL;

    typedef struct {
        float ponto[3][3];
        float cor[3];
    } tTrianguloGL;

    typedef struct {
        float ponto[2][3];
        float cor[3];
    } tLinhaGL;

    typedef struct {
        float ponto[4][3];
        float cor[3];
    } tQuadGL;

    tPoligonoGL geraRetangulo();
    tTrianguloGL inverte_xT(tTrianguloGL pol);
    tTrianguloGL inverte_yT(tTrianguloGL pol);
    tQuadGL inverte_xQ(tQuadGL pol);
    tQuadGL inverte_yQ(tQuadGL pol);
    void desenha_Linha(int pontos, tLinhaGL linha);
    void desenha_Triangulo(int pontos, tTrianguloGL triangulo, int tipo);
#endif
