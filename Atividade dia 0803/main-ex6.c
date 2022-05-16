#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "objetos-ex6.h"

int main(){
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    srand(time(NULL));
    // Poligono do tipo quadrado sendo criado
    tPolygon poligono = polFactory(1);

    // Mostrando as coordenadas do polígono
    printf("Polígono gerado: \n");
    polCoordinates(poligono);

    // Exibindo o polígono no terminal
    polDraw(poligono);

    // Gerando o ângulo para a rotação
    int deg = degFactory();
    printf("\nÂngulo gerado para a rotação: [%.d]\n", deg);

    // Aplicando a matriz de retoração no polígono
    poligono = tgRotate(poligono, deg);

    // Exibindo as coordenadas do polígono após a transformação
    printf("\nPolígono após a rotação: \n");
    polCoordinates(poligono);
    polDraw(poligono);
}