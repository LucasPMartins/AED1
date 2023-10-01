#include <stdio.h>
#include <stdlib.h>

void mediamaior(int *vet,int n,float *media,int *maior){
    int soma = 0;
    int i;
    int nummaior = *(vet+0);
    for(i = 0;i < n;i++){
        soma += *(vet+i);
        if(*(vet+i) > nummaior){
            nummaior = *(vet+i);
        }
    }
    *media = soma/(1.00*n);
    *maior = nummaior;

}

int main()
{
    int count;
    int *vetor;
    float mediavet;
    int maiornum;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&count);
    vetor = (int *) malloc(count*sizeof(int));
    for(int i = 0;i < count;i++){
        printf("Numero %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    mediamaior(vetor,count,&mediavet,&maiornum);
    printf("O maior numero eh %d\n",maiornum);
    printf("A media do vetor eh %.2f",mediavet);
    return 0;
}
