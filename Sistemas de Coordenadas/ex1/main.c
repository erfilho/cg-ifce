#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    // Configuração para acentos no terminal
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int sis_origin = 0, sis_destiny = 0;

    printf("Qual o sistema de origem? \n 1 - SRU\n 2 - SRD\n>>");
    scanf("%d", &sis_origin);
    printf("Qual o sistema de destino? \n 1 - SRU\n 2 - SRD\n>>");
    scanf("%d", &sis_destiny);
    
    if(sis_origin != sis_destiny){
        float so_x_min = 0, so_x_max = 0, so_y_min = 0, so_y_max = 0;
        printf("Digite o X_min, X_max, Y_min e Y_max do sistema de origem, nessa ordem: ");
        scanf("%f %f %f %f", &so_x_min, &so_x_max, &so_y_min, &so_y_max);

        float sd_x_min = 0, sd_x_max = 0, sd_y_min = 0, sd_y_max = 0;
        printf("Digite o X_min, X_max, Y_min e Y_max do sistema de destino, nessa ordem: ");
        scanf("%f %f %f %f", &sd_x_min, &sd_x_max, &sd_y_min, &sd_y_max);

        float so_x = 0, so_y = 0;
        printf("Digite as coordenadas X e Y no sistema de origem: \n>> ");
        scanf("%f %f", &so_x, &so_y);

        float Xd = 0, Yd = 0;
        switch(sis_origin){
            case 1: // SRU to SRD
                Xd = (so_x * sd_x_max)/so_x_max; 
                Yd = ((so_y * (-sd_y_max))/so_y_max)+sd_y_max;
                printf("Coordenadas no sistema de destino: X: %.2f, Y %.2f", Xd, Yd);
                break;
            case 2: // SRD to SRU
                Xd = (so_x * sd_x_max)/so_x_max; 
                Yd = ((so_y * (-sd_y_max))/so_y_max)+sd_y_max;
                printf("Coordenadas no sistema de destino: X: %.2f, Y %.2f", Xd, Yd);
                break;
            default:
                printf("Errno!");
        }
    }
}