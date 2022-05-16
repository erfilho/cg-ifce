#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

	typedef struct {
		int x, y;
	} tPonto;

	typedef struct {
		tPonto ponto_a;
		tPonto ponto_b;
		tPonto ponto_c;
		tPonto ponto_d;
	} poligono;

	poligono setQuadrado (int ponto_a_x, int ponto_a_y){
		poligono Quadrado;
		Quadrado.ponto_a.x = ponto_a_x;
		Quadrado.ponto_a.y = ponto_a_y;

		Quadrado.ponto_b.x = ponto_a_x + 4;
		Quadrado.ponto_b.y = ponto_a_y;

		Quadrado.ponto_c.x = ponto_a_x;
		Quadrado.ponto_c.y = ponto_a_y + 4;

		Quadrado.ponto_d.x = ponto_a_x + 4;
		Quadrado.ponto_d.y = ponto_a_y + 4;
		return Quadrado;
	}

	poligono setTriangulo (int ponto_a_x, int ponto_a_y){
		poligono Triangulo;
		Triangulo.ponto_a.x = ponto_a_x;
		Triangulo.ponto_a.y = ponto_a_y;

		Triangulo.ponto_b.x = ponto_a_x - 1;
		Triangulo.ponto_b.y = ponto_a_y + 2;

		Triangulo.ponto_c.x = ponto_a_x + 1;
		Triangulo.ponto_c.y = ponto_a_y + 2;
		return Triangulo;
	}

	poligono setRetangulo (int ponto_a_x, int ponto_a_y){
		poligono Retangulo;
		Retangulo.ponto_a.x = ponto_a_x;
		Retangulo.ponto_a.y = ponto_a_y;
		
		Retangulo.ponto_b.x = ponto_a_x + 5;
		Retangulo.ponto_b.y = ponto_a_y;
		
		Retangulo.ponto_c.x = ponto_a_x;
		Retangulo.ponto_c.y = ponto_a_y + 3;
		
		Retangulo.ponto_d.x = ponto_a_x + 5;
		Retangulo.ponto_d.y = ponto_a_y + 3;
		return Retangulo;
	}

	srand(time(NULL));

	int option, ponto_a_x, ponto_a_y;

	printf("Selecione o polígono: \n1 - Quadrado\n2 - Triangulo\n3 - Retângulo\n>> ");
	scanf("%d", &option);

	switch(option){
		case 1:
			printf("Selecionado: Quadrado \n");
			poligono quadrado;
			ponto_a_x = 1+(rand() % 16);
			ponto_a_y = 1+(rand() % 16);
			quadrado = setQuadrado(ponto_a_x, ponto_a_y);
			for(int y = 1; y <= 20; y++){
				for(int x = 1; x <= 20; x++){
					if(x == quadrado.ponto_a.x && y == quadrado.ponto_a.y){
						printf(" A ");
					} else if( x == quadrado.ponto_b.x && y == quadrado.ponto_b.y){
						printf(" B ");
					} else if( x == quadrado.ponto_c.x && y == quadrado.ponto_c.y){
						printf(" C ");
					} else if( x == quadrado.ponto_d.x && y == quadrado.ponto_d.y){
						printf(" D ");
					} else if(((x > quadrado.ponto_a.x && x < quadrado.ponto_b.x) && y == quadrado.ponto_a.y) || ((x > quadrado.ponto_c.x && x < quadrado.ponto_d.x) && y == quadrado.ponto_c.y)){
						printf(" - ");
					} else if(((y > quadrado.ponto_a.y && y < quadrado.ponto_c.y) && x == quadrado.ponto_c.x) || ((y > quadrado.ponto_b.y && y < quadrado.ponto_d.y) && x == quadrado.ponto_d.x)){
						printf(" | ");
					} else if((x > quadrado.ponto_a.x && x < quadrado.ponto_d.x) && (y > quadrado.ponto_a.y && y < quadrado.ponto_d.y)){
						printf(" * ");
					} else {
						printf(" . ");
					}
				}
				printf("\n");
			}
			break;
		case 2:
			printf("Selecionado: Triângulo \n");
			poligono triangulo;
			ponto_a_x = 2+(rand() % 16);
			ponto_a_y = 1+(rand() % 16);
			triangulo = setTriangulo(ponto_a_x, ponto_a_y);
			for(int y = 1; y <= 20; y++){
				for(int x = 1; x <= 20; x++){
					if(x == triangulo.ponto_a.x && y == triangulo.ponto_a.y){
						printf(" A ");
					} else if(x == triangulo.ponto_b.x && y == triangulo.ponto_b.y){
						printf(" B ");
					} else if(x == triangulo.ponto_c.x && y == triangulo.ponto_c.y){
						printf(" C ");
					} else if(x == (triangulo.ponto_a.x + 1) && y == (triangulo.ponto_a.y + 1)){
						printf("\\  ");
					} else if(x == (triangulo.ponto_a.x - 1) && y == (triangulo.ponto_a.y + 1)){
						printf("  /");
					} else if(((x > triangulo.ponto_b.x) && (x < triangulo.ponto_c.x)) && y == triangulo.ponto_b.y){
						printf(" _ ");
					} else if((x > (triangulo.ponto_a.x - 1) && (x < triangulo.ponto_c.x)) && (y > triangulo.ponto_a.y && y < triangulo.ponto_c.y)){
						printf(" * ");
					} else {
						printf(" . ");
					}
				}
				printf("\n");
			}
			break;
		case 3:
			printf("Selecionado: Retângulo \n");
			poligono retangulo;
			ponto_a_x = 1 + (rand() % 15);
			ponto_a_y = 1 + (rand() % 16);
			retangulo = setRetangulo(ponto_a_x, ponto_a_y);
			for(int y = 1; y <= 20; y++){
				for(int x = 1; x <= 20; x++){
					if(x == retangulo.ponto_a.x && y == retangulo.ponto_a.y){
						printf(" A ");
					} else if(x == retangulo.ponto_b.x && y == retangulo.ponto_b.y){
						printf(" B ");
					} else if(x == retangulo.ponto_c.x && y == retangulo.ponto_c.y){
						printf(" C ");
					} else if(x == retangulo.ponto_d.x && y == retangulo.ponto_d.y){
						printf(" D ");
					} else if((x > retangulo.ponto_a.x && x < retangulo.ponto_b.x) && (y == retangulo.ponto_c.y || y == retangulo.ponto_a.y)){
						printf(" - ");
					} else if((x == retangulo.ponto_a.x || x == retangulo.ponto_b.x) && (y > retangulo.ponto_a.y && y < retangulo.ponto_d.y)){
						printf(" | ");
					} else if((x > retangulo.ponto_a.x && x < retangulo.ponto_d.x) && (y > retangulo.ponto_a.y && y < retangulo.ponto_d.y)){
						printf(" * ");
					} else {
						printf(" . ");
					}
				}
				printf("\n");
			}
			break;
		default:
			printf("Errno");
	}
};