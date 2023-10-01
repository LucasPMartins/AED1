#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lotomania[10];
    int num[10];
    int *acertou;
    int i,j,count = 0;
    srand(time(NULL));
    for(i = 0;i < 10;i++){
        num[i] = 0;
    }
    printf("Digite o sua aposta:\n");
    for(i = 0;i < 10;i++){
        do{
            printf("Numero %d:",i+1);
            scanf("%d",&num[i]);
            count = 0;
            for(j = 0;j < 10;j++){
                if(num[i] == num[j]){
                    count++;
                }
            }
            if(count >= 2){
                printf("\nDigite um numero diferente!\n\n");
            }
        }while(count >= 2);
        do{
            lotomania[i] = rand() % 100;
            count = 0;
            for(j = 0;j < 10;j++){
                if(lotomania[i] == lotomania[j]){
                    count++;
                }
            }
        }while(count >= 2);
    }
    count = 0;
    acertou = (int *) malloc(1*sizeof(int));
    for(i = 0;i < 10;i++){
        for(j = 0;j < 10;j++){
            if(num[i] == lotomania[j]){
                acertou[count] = num[i];
                count++;
                acertou = (int *) realloc(acertou,(count+1)*sizeof(int));
            }
        }
    }
    printf("\n\nNumeros da Lotomania:");
    for(i = 0;i < 10;i++){
        printf("%d ",lotomania[i]);
    }
    printf("\n\nNumeros da aposta:");
    for(i = 0;i < 10;i++){
        printf("%d ",num[i]);
    }
    printf("\n\nNumeros acertados:");
    if(count == 0){
        printf("Nenhum!");
    }else{
        for(i = 0;i < count;i++){
            printf("%d ",acertou[i]);
        }
    }

    free(acertou);
    return 0;
}
