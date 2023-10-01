#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num,i = 0;
    int soma = 0,quant = 0;
    num = (int *) malloc(sizeof(int));
    if(num == NULL){
        printf("Memoria insuficiente!\n");
        free(num);
        exit(1);
    }
    printf("Digite um numero %d:",i+1);
    scanf("%d",&num[i]);
    while(num[i] != 10){
        if(num[i] != 10){
            i++;
        }
        num = (int *) realloc(num,(i+1)*sizeof(int));
        if(num == NULL){
            printf("Memoria insuficiente!\n");
            free(num);
            exit(1);
        }
        printf("Digite um numero %d:",i+1);
        scanf("%d",&num[i]);
    }
    for(i = 0;num[i] != 10;i++){
        if(num[i] > 10){
            soma += num[i];
        }else{
            quant++;
        }
    }
    printf("Numeros digitados:\n");
    for(i = 0; num[i] != 10;i++){
        printf("%d ",num[i]);
    }
    printf("\nA soma dos numeros maiores que 10 eh %d\n",soma);
    printf("A quantidade de numeros menores que 10 eh %d\n",quant);
    free(num);
    return 0;
}
