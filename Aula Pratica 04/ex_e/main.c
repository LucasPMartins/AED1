#include <stdio.h>
#include <stdlib.h>

int *vetor(int num){
    int *vet,i;
    vet = (int *) malloc(10*sizeof(int));
    for(i = 0;i < 10;i++){
        *(vet+i) = num;
    }
    return vet;
}

int main()
{
    int valor;
    int *vet;
    int i;
    printf("Digite um numero:");
    scanf("%d",&valor);
    vet = vetor(valor);
    printf("Vetor com os valor digitado:");
    for(i = 0;i < 10;i++){
        printf("%d ",*(vet+i));
    }
    free(vet);
    return 0;
}
