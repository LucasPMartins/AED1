#include <stdio.h>
#include <stdlib.h>

int multi(int *vet,int n,int valor){
    int i;
    for(i = 0;i < n;i++){
        *(vet+i) = *(vet+i)*valor;
    }
}

int main()
{
    int tamanho,*vetor,i,num;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&tamanho);
    vetor = (int *) malloc(tamanho*sizeof(int));
    for(i = 0;i < tamanho;i++){
        printf("Numero %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("Digite uma valor para a multiplicacao por escalar:");
    scanf("%d",&num);
    printf("Vetor antes:");
    for(i = 0;i < tamanho;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n\nVetor depois:");
    multi(vetor,tamanho,num);
    for(i = 0;i < tamanho;i++){
        printf("%d ",vetor[i]);
    }
    free(vetor);
    return 0;
}
