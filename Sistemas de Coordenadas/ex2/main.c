#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define XMAX 1000.0
#define XMIN 0.0
#define YMAX 1500.0
#define YMIN 0.0

int main(){
    // Configuração para acentos no terminal
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    float so_x = 0, so_y = 0;
    printf("As coordenadas máximas e mínimas do plano cartesiano são: \n");
    printf("Xmax = 1000, Xmin = 0\nYmax = 1500, Ymin = 0\n");

    printf("Digite as coordenadas X e Y no sistema usuário: \n");
    scanf("%f %f", &so_x, &so_y);
    
    float ndcx = 0, ndcy = 0;
    float revx = 0, revy = 0;

    ndcx = (so_x - XMIN)/(XMAX - XMIN);
    ndcy = (so_y - YMIN)/(YMAX - YMIN);

    printf("As coordenadas normalizadas do dispositivo são: \n (%.4f, %.4f)\n\n", ndcx, ndcy);

    revx = (ndcx)*(XMAX-XMIN);
    revy = (ndcy)*(YMAX-YMIN);

    printf("As coordenadas do usuário, a partir das normalizadas são: \n (%.4f, %.4f)", revx, revy);
}