#include <stdio.h>
#include <stdlib.h>
#include "objetos.h"

int main(){
    tPolygon teste = polFactory(1);
    printf("%d", teste.pointA.x);
    return 0;
}