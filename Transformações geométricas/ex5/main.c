#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "objetos.h"

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

    // Gerando uma matriz de transformação de escala controlada para o polígono, considerando a escala igual para o eixo x e y
    int tX = (rand() % 3) + 2;
    int tY = tX;
    printf("\nMatriz de transformação de escala gerada: [%d, %d]\n", tX, tY);

    // Aplicando a matriz de transformação no polígono
    poligono = tgScale(poligono, tX, tY);
    // Exibindo as coordenadas do polígono após a transformação
    printf("\nPolígono após a translação: \n");
    polCoordinates(poligono);
    // Exibindo o polígono no terminal 
    polDraw(poligono);
}