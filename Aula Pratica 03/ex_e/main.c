#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculaHexagono (float l,float *area,float *perimetro){
    *area = 6*((pow(l,2)*sqrt(3))/4);
    *perimetro = 6*l;
}

int main()
{
    float lado;
    float area,perimetro;
    printf("Digite o tamanho do lado do Hexagono:");
    scanf("%f",&lado);
    calculaHexagono(lado,&area,&perimetro);
    printf("O Perimetro do hexagono de lado %.2f eh %.2f\n",lado,perimetro);
    printf("A area do hexagono de lado %.2f eh %.2f",lado,area);
    return 0;
}
