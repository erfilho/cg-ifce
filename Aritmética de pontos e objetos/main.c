/*
IFCE - Instituto Federal do Ceará - Campus Tianguá
Aluno: Francisco Erineldo Xavier Filho
Curso: Bacharelado em Ciências da Computação - 5º Semestre
Disciplina: Computação Gráfica

Atividade sobre aritmética de pontos e objetos - dia 21/02/2022
*/

#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    srand(time(NULL));

    int opt_object, opt_transform;
    int pointA_x, pointA_y;

    typedef struct {
        int x, y;
    } tPoint;

    typedef struct {
        tPoint pointA;
        tPoint pointB;
        tPoint pointC;
        tPoint pointD;
    } tPolygon;

    tPolygon setQuadrado (int pontoA_x, int pontoA_y){
		tPolygon Quadrado;
		Quadrado.pointA.x = pontoA_x;
		Quadrado.pointA.y = pontoA_y;

		Quadrado.pointB.x = pontoA_x + 4;
		Quadrado.pointB.y = pontoA_y;

		Quadrado.pointC.x = pontoA_x;
		Quadrado.pointC.y = pontoA_y + 4;

		Quadrado.pointD.x = pontoA_x + 4;
		Quadrado.pointD.y = pontoA_y + 4;
		return Quadrado;
	}

	tPolygon setRetangulo (int pontoA_x, int pontoA_y){
		tPolygon Retangulo;
		Retangulo.pointA.x = pontoA_x;
		Retangulo.pointA.y = pontoA_y;
		
		Retangulo.pointB.x = pontoA_x + 5;
		Retangulo.pointB.y = pontoA_y;
		
		Retangulo.pointC.x = pontoA_x;
		Retangulo.pointC.y = pontoA_y + 3;
		
		Retangulo.pointD.x = pontoA_x + 5;
		Retangulo.pointD.y = pontoA_y + 3;
		return Retangulo;
	}

    tPolygon pol_factory(int type){
        switch(type){
            case 1:
                pointA_x = 1 + (rand() % 14);
                pointA_y = 1 + (rand() % 14);
                tPolygon quadrado = setQuadrado(pointA_x, pointA_y);
                return quadrado;
                break;
            case 2:
                pointA_x = 1 + (rand() % 13);
                pointA_y = 1 + (rand() % 15);
                tPolygon retangulo = setRetangulo(pointA_x, pointA_y);
                return retangulo;
                break;
            default:
                printf("Errno");
        }
    }

    tPolygon pol_oposto(tPolygon pol){
        tPolygon pol_oposto;

        pol_oposto.pointA.x = -pol.pointA.x;
        pol_oposto.pointA.y = -pol.pointA.y;
        pol_oposto.pointB.x = -pol.pointB.x;
        pol_oposto.pointB.y = -pol.pointB.y;
        pol_oposto.pointC.x = -pol.pointC.x;
        pol_oposto.pointC.y = -pol.pointC.y;
        pol_oposto.pointD.x = -pol.pointD.x;
        pol_oposto.pointD.y = -pol.pointD.y;

        return pol_oposto;
    }

    tPolygon pol_multiplica(tPolygon pol_a, tPolygon pol_b){
        tPolygon pol_resultado;

        pol_resultado.pointA.x = (pol_a.pointA.x * pol_b.pointA.x) + (pol_a.pointB.x * pol_b.pointC.x);
        pol_resultado.pointA.y = (pol_a.pointA.y * pol_b.pointA.y) + (pol_a.pointB.y * pol_b.pointC.y);
        pol_resultado.pointB.x = (pol_a.pointA.x * pol_b.pointB.x) + (pol_a.pointB.x * pol_b.pointD.x);
        pol_resultado.pointB.y = (pol_a.pointA.y * pol_b.pointB.y) + (pol_a.pointB.y * pol_b.pointD.y); 
        pol_resultado.pointC.x = (pol_a.pointC.x * pol_b.pointA.x) + (pol_a.pointD.x * pol_b.pointC.x); 
        pol_resultado.pointC.y = (pol_a.pointC.y * pol_b.pointA.y) + (pol_a.pointD.y * pol_b.pointC.y);
        pol_resultado.pointD.x = (pol_a.pointC.x * pol_b.pointB.x) + (pol_a.pointD.x * pol_b.pointD.x);
        pol_resultado.pointD.y = (pol_a.pointC.y * pol_b.pointB.y) + (pol_a.pointD.y * pol_b.pointD.y);

        return pol_resultado;
    }

    tPolygon pol_soma(tPolygon pol_a, tPolygon pol_b){
        tPolygon pol_resultado;

        pol_resultado.pointA.x = pol_a.pointA.x + pol_b.pointA.x;
        pol_resultado.pointA.y = pol_a.pointA.y + pol_b.pointA.y;
        pol_resultado.pointB.x = pol_a.pointB.x + pol_b.pointB.x;
        pol_resultado.pointB.y = pol_a.pointB.y + pol_b.pointB.y;
        pol_resultado.pointC.x = pol_a.pointC.x + pol_b.pointC.x;
        pol_resultado.pointC.y = pol_a.pointC.y + pol_b.pointC.y;
        pol_resultado.pointD.x = pol_a.pointD.x + pol_b.pointD.x;
        pol_resultado.pointD.y = pol_a.pointD.y + pol_b.pointD.y;

        return pol_resultado;
    }

    void pol_coordinates(tPolygon polygon){
        printf("A [%d, %d] ", polygon.pointA.x, polygon.pointA.y);
        printf("B [%d, %d] \n", polygon.pointB.x, polygon.pointB.y);
        printf("C [%d, %d] ", polygon.pointC.x, polygon.pointC.y);
        printf("D [%d, %d] \n", polygon.pointD.x, polygon.pointD.y);
    }

    int b_X = 0, b_Y = 0;
    int c_X = 0, c_Y = 0;
    int d_X = 0, d_Y = 0;
    tPolygon polygonA;
    tPolygon polygonB;
    tPolygon polygonC;
    tPolygon polygonD;
    tPolygon mat_transf_B;
    tPolygon mat_transf_C;

    void pol_transform(tPolygon poligono, int propriedade){
        switch(propriedade){
            case 1:
                // Associativa
                // (A + B) + C = A + (B + C);
                polygonA = poligono;
                polygonB = poligono;
                // (A+B)+C
                b_X = rand() % 16;
                b_Y = rand() % 16;
                c_X = rand() % polygonA.pointB.x;
                c_Y = rand() % polygonA.pointB.y;

                printf("\nMatriz de movimento B : [%d, %d]\n", b_X, b_Y);
                printf("Matriz de movimento C : [%d, %d]\n", c_X, c_Y);
                polygonA.pointA.x += b_X;
                polygonA.pointA.y += b_Y;
                polygonA.pointB.x += b_X;
                polygonA.pointB.y += b_Y;
                polygonA.pointC.x += b_X;
                polygonA.pointC.y += b_Y;
                polygonA.pointD.x += b_X;
                polygonA.pointD.y += b_Y;
                printf("\n(A + B)\n");
                pol_coordinates(polygonA);

                polygonA.pointA.x += c_X; 
                polygonA.pointA.y += c_Y;
                polygonA.pointB.x += c_X;
                polygonA.pointB.y += c_Y;
                polygonA.pointC.x += c_X;
                polygonA.pointC.y += c_Y;
                polygonA.pointD.x += c_X;
                polygonA.pointD.y += c_Y;

                printf("\n(A + B) + C\n");
                pol_coordinates(polygonA);

                d_X = b_X + c_X;
                d_Y = b_Y + c_Y;
                printf("\n(B + C)\n");
                printf("[%d, %d]\n", d_X, d_Y);

                polygonB.pointA.x += d_X;
                polygonB.pointA.y += d_Y;
                polygonB.pointB.x += d_X;
                polygonB.pointB.y += d_Y;
                polygonB.pointC.x += d_X;
                polygonB.pointC.y += d_Y;
                polygonB.pointD.x += d_X;
                polygonB.pointD.y += d_Y;

                printf("\nA + (B + C)\n");
                pol_coordinates(polygonB);
                break;
            case 2:
                // Comutativa
                // A + B = B + A
                polygonA = poligono;
                polygonB = poligono;

                b_X = rand() % 16;
                b_Y = rand() % 16;

                printf("\nMatriz de movimento B : [%d, %d]\n", b_X, b_Y);
                polygonA.pointA.x += b_X;
                polygonA.pointA.y += b_Y;
                polygonA.pointB.x += b_X;
                polygonA.pointB.y += b_Y;
                polygonA.pointC.x += b_X;
                polygonA.pointC.y += b_Y;
                polygonA.pointD.x += b_X;
                polygonA.pointD.y += b_Y;
                printf("\nA + B\n");
                pol_coordinates(polygonA);

                polygonB.pointA.x = b_X + poligono.pointA.x;
                polygonB.pointA.y = b_Y + poligono.pointA.y;
                polygonB.pointB.x = b_X + poligono.pointB.x;
                polygonB.pointB.y = b_Y + poligono.pointB.y;
                polygonB.pointC.x = b_X + poligono.pointC.x;
                polygonB.pointC.y = b_Y + poligono.pointC.y;
                polygonB.pointD.x = b_X + poligono.pointD.x;
                polygonB.pointD.y = b_Y + poligono.pointD.y;
                printf("\nB + A\n");
                pol_coordinates(polygonB);
                break;
            case 3:
                // Neutro
                // A + 0 = 0 + A = A
                polygonA = poligono;
                polygonB = poligono;
                
                b_X = 0;
                b_Y = 0;

                printf("Matriz de movimento B : [%d, %d]\n", b_X, b_Y);
                polygonA.pointA.x += b_X;
                polygonA.pointA.y += b_Y;
                polygonA.pointB.x += b_X;
                polygonA.pointB.y += b_Y;
                polygonA.pointC.x += b_X;
                polygonA.pointC.y += b_Y;
                polygonA.pointD.x += b_X;
                polygonA.pointD.y += b_Y;

                printf("\nA + 0\n");
                pol_coordinates(polygonA);

                polygonB.pointA.x = b_X + poligono.pointA.x;
                polygonB.pointA.y = b_Y + poligono.pointA.y;
                polygonB.pointB.x = b_X + poligono.pointB.x;
                polygonB.pointB.y = b_Y + poligono.pointB.y;
                polygonB.pointC.x = b_X + poligono.pointC.x;
                polygonB.pointC.y = b_Y + poligono.pointC.y;
                polygonB.pointD.x = b_X + poligono.pointD.x;
                polygonB.pointD.y = b_Y + poligono.pointD.y;
                
                printf("\n0 + A\n");
                pol_coordinates(polygonB);

                printf("\nA + 0 = 0 + A = A\n");
                pol_coordinates(poligono);
                break;
            case 4:
                // Oposto
                // Oposto: A = -A
                // Se B = -A logo A + B = 0

                polygonA = poligono;
                polygonB = pol_oposto(poligono);

                printf("\nB = -A\n");
                pol_coordinates(polygonB);

                polygonA.pointA.x += polygonB.pointA.x;
                polygonA.pointA.y += polygonB.pointA.y;
                polygonA.pointB.x += polygonB.pointB.x;
                polygonA.pointB.y += polygonB.pointB.y;
                polygonA.pointC.x += polygonB.pointC.x;
                polygonA.pointC.y += polygonB.pointC.y;
                polygonA.pointD.x += polygonB.pointD.x;
                polygonA.pointD.y += polygonB.pointD.y;

                printf("\nA + B = 0\n");
                pol_coordinates(polygonA);
                break;
            case 5:
                // Associativa - Multiplicação
                // (A * B) * C = A * (B * C)
                polygonA = poligono;

                mat_transf_B = pol_factory(1);
                printf("\nMatriz de transformação B:\n");
                pol_coordinates(mat_transf_B);

                mat_transf_C = pol_factory(1);
                printf("\nMatriz de transformação C:\n");
                pol_coordinates(mat_transf_C);

                polygonC = pol_multiplica(polygonA, mat_transf_B);
                printf("\n(A * B)\n");
                pol_coordinates(polygonC);
                
                polygonD = pol_multiplica(polygonC, mat_transf_C);
                printf("\n(A * B) * C\n");
                pol_coordinates(polygonD);

                polygonD = pol_multiplica(mat_transf_B, mat_transf_C);
                printf("\n(B * C) \n");
                pol_coordinates(polygonD);

                polygonC = pol_multiplica(polygonA, polygonD);
                printf("\nA * (B * C)\n");
                pol_coordinates(polygonC);
                break;
            case 6:
                // Distributiva - Multiplicação
                // (A + B) * C = A*C + B*C
                polygonA = poligono;

                mat_transf_B = pol_factory(1);
                printf("\nMatriz de transformação B\n");
                pol_coordinates(mat_transf_B);

                mat_transf_C = pol_factory(1);
                printf("\nMatriz de transformação C\n");
                pol_coordinates(mat_transf_C);

                polygonB = pol_soma(polygonA, mat_transf_B);
                printf("\n(A + B)\n");
                pol_coordinates(polygonB);

                polygonC = pol_multiplica(polygonB, mat_transf_C);
                printf("\n(A + B) * C\n");
                pol_coordinates(polygonC);

                polygonB = pol_multiplica(polygonA, mat_transf_C);
                printf("\nA * C\n");
                pol_coordinates(polygonB);

                polygonC = pol_multiplica(mat_transf_B, mat_transf_C);
                printf("\nB * C\n");
                pol_coordinates(polygonC);

                polygonD = pol_soma(polygonB, polygonC);
                printf("\nA*C + B*C\n");
                pol_coordinates(polygonD);
                
                // A * (B + C) = A*B + A*C
                polygonB = pol_soma(mat_transf_B, mat_transf_C);
                printf("\n(B + C)\n");
                pol_coordinates(polygonB);

                polygonC = pol_multiplica(polygonA, polygonB);
                printf("\nA * (B + C)\n");
                pol_coordinates(polygonC); 

                polygonB = pol_multiplica(polygonA, mat_transf_B);
                printf("\nA * B\n");
                pol_coordinates(polygonB);

                polygonC = pol_multiplica(polygonA, mat_transf_C);
                printf("\nA * C\n");
                pol_coordinates(polygonC);

                polygonD = pol_soma(polygonB, polygonC);
                printf("\nA*B + A*C\n");
                pol_coordinates(polygonD);
                break;
            default:
                printf("Errno");
        }
    }

    printf("Digite o objeto desejado: \n1 > Quadrado \n2 > Retângulo \n>> ");
    scanf("%d", &opt_object);

    printf("Digite a transformação a ser testada: \n");
    printf("Soma de matrizes: \n 1 - Associativa\n 2 - Comutativa\n 3 - Neutro\n 4 - Oposto\n");
    printf("Multiplicação de matrizes: \n 5 - Associativa\n 6 - Distributiva\n>> ");
    scanf("%d", &opt_transform);

    tPolygon poligono;

    switch(opt_object){
        case 1:
            poligono = pol_factory(1);
            break;
        case 2:
            poligono = pol_factory(2);
            break;
        default:
            printf("Errno");
    }

    switch(opt_transform){
        case 1:
            // Associativa
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 1);
            break;
        case 2:
            // Comutativa
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 2);
            break;
        case 3:
            // Neutro
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 3);
            break;
        case 4:
            // Oposto
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 4);
            break;
        case 5:
            // Associativa - Multiplicação
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 5);
            break;
        case 6:
            // Distributiva - Multiplicação
            printf("\nPoligono gerado A\n");
            pol_coordinates(poligono);
            pol_transform(poligono, 6);
            break;
        default:
            printf("Errno");
    }
}