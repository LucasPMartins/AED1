#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    int count = 0;
    int *vet;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&n);
    vet = (int *) malloc(n*sizeof(int));
    if(vet == NULL){
        printf("Memoria insuficiente!");
        return 0;
    }
    printf("Digite os %d numeros:\n",n);
    for(i = 0;i < n;i++){
        printf("Numero %d:",i+1);
        scanf("%d",vet+i);
    }
    printf("\nRemovendo os numeros impares...\n\n");
    for(i = 0;i < n; i++){
        if(*(vet+i)% 2 != 0){
            *(vet+i) = 0;
        }else{
            count++;
        }
    }
    for(i = 0;i < n;i++){
        if(*(vet+i) == 0){
            for(j = i;j < n;j++){
                if(*(vet+j) != 0){
                    *(vet+i) = *(vet+j);
                    *(vet+j) = 0;
                    break;
                }
            }
        }
    }
    printf("\nRedimencionando vetor...\n\n");
    vet = (int *) realloc(vet,count*sizeof(int));
    printf("Novo vetor sem numeros impares:\n");
    for(i = 0;i < count; i++){
        printf("Numero %d: %d\n",i+1,*(vet+i));
    }
    free(vet);
    return 0;
}
