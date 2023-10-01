#include <stdio.h>
#include <stdlib.h>

int swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int swapvetor(int *vet,int n){
    int i,j;
    for(j = n - 1,i = 0;j > i && i < n;j--,i++){
        swap((vet+i),(vet+j));
    }
}

int main()
{
    int tamanho,*vetor,i;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&tamanho);
    vetor = (int *) malloc(tamanho*sizeof(int));
    for(i = 0;i < tamanho;i++){
        printf("Numero %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("\nTrocando os valores do vetor...\n\n");
    printf("Vetor antes:");
    for(i = 0;i < tamanho;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n\nVetor depois:");
    swapvetor(vetor,tamanho);
    for(i = 0;i < tamanho;i++){
        printf("%d ",vetor[i]);
    }
    free(vetor);
    return 0;
}
