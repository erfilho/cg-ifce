#ifndef OBJECTS_H
#define OBJECT_H

    typedef struct {
        float ponto[6][3];
        float cor[3];
    } tPoligonoGL;

    tPoligonoGL geraRetangulo();
    void desenha_Pol(int pontos, tPoligonoGL pol, int tipo);
#endif
