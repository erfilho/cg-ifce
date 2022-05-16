#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    // Configuração para acentos no terminal
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    float so_x_min = 0, so_x_max = 0, so_y_min = 0, so_y_max = 0;
    printf("Digite o X_min, X_max, Y_min e Y_max do sistema do usuário, nessa ordem: ");
    scanf("%f %f %f %f", &so_x_min, &so_x_max, &so_y_min, &so_y_max);

    float sd_x_min = 0, sd_x_max = 0, sd_y_min = 0, sd_y_max = 0;
    printf("Digite o X_min, X_max, Y_min e Y_max do sistema do dispositivo, nessa ordem: ");
    scanf("%f %f %f %f", &sd_x_min, &sd_x_max, &sd_y_min, &sd_y_max);

    float so_x = 0, so_y = 0;
    printf("Digite as coordenadas X e Y no sistema do usuário: \n>> ");
    scanf("%f %f", &so_x, &so_y);

    
    float ndcx = 0, ndcy = 0;
    float sd_x = 0, sd_y = 0;

    ndcx = (so_x - so_x_min)/(so_x_max - so_x_min);
    ndcy = (so_y - so_y_min)/(so_y_max - so_y_min);

    printf("As coordenadas normalizadas do dispositivo são: \n (%.4f, %.4f)\n\n", ndcx, ndcy);

    sd_x = ndcx * (sd_x_max - sd_x_min);
    sd_y = -(ndcy * (sd_y_max - sd_y_min)) + sd_y_max;

    printf("As coordenadas do sistema do dispositivo são: \n (%.4f, %.4f)\n\n", sd_x, sd_y);
}