#include <stdio.h>
#include <stdlib.h>





int main()
{
    int *vet; //vet = NULL;
    int i,j;
    int count = 1;
    char c;
    int sair = 0;
    int parada;
    printf("Digite um numero (-1 para parar)\n\n");
    vet = (int *) malloc(1*sizeof(int));
    do{
        printf("Numero %d:",count);
        scanf("%d",&vet[count - 1]);
        if(vet[count-1] != -1){
            count++;
            vet = (int *) realloc(vet,count*sizeof(int));
            sair = 0;
        }else{
            count--;
            sair = 1;
        }
    }while(sair == 0);
    printf("Vetor digitado:");
    for(i = 0;i < count;i++){
        printf("%d ",*(vet+i));
    }
    printf("\n\nNovo vetor sem numeros repetidos consecutivos: ");
    for(i = 0;i < count;i++){
        if(vet[i] == vet[i+1]){
            for(j = i;j < count;j++){
                vet[j] = vet[j+1];
            }
            count--;
            i--;
        }
    }
    vet = (int *) realloc(vet,count*sizeof(int));
    for(i = 0;i < count;i++){
        printf("%d ",*(vet+i));
    }
    do{
        printf("\n\nDeseja continuar? (S para sim,N para nao)\nR:");
        setbuf(stdin,NULL);
        scanf("%c",&c);
        if(c == 'S'){
            printf("Digite o valor para parar o loop:");
            scanf("%d",&parada);
            printf("Digite um numero (%d para parar)\n\n",parada);
            vet = (int *) realloc(vet,(count+1)*sizeof(int));
            do{
                printf("Numero %d:",count);
                scanf("%d",&vet[count - 1]);
                if(vet[count-1] != parada){
                    count++;
                    vet = (int *) realloc(vet,count*sizeof(int));
                    sair = 0;
                }else{
                    count--;
                    sair = 1;
                }
            }while(sair == 0);
            printf("Vetor digitado:");
            for(i = 0;i < count;i++){
                printf("%d ",*(vet+i));
            }
            printf("\n\nNovo vetor sem numeros repetidos consecutivos: ");
            for(i = 0;i < count;i++){
                if(vet[i] == vet[i+1]){
                    for(j = i;j < count;j++){
                        vet[j] = vet[j+1];
                    }
                    count--;
                    i--;
                }
            }
            vet = (int *) realloc(vet,count*sizeof(int));
            for(i = 0;i < count;i++){
                printf("%d ",*(vet+i));
            }
        }
    }while(c == 'S');
    free(vet);
    return 0;
}
