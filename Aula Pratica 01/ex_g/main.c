#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j;
    int soma[10] = {0,0,0,0,0,0,0,0,0,0};
    int matriz[5][10];
    srand(time(NULL));
    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            matriz[i][j] = rand() % 100;
        }
    }
    printf("Matriz 5x10:\n");
    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            printf("%-4i ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nSomando cada linha...\n");
    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            soma[i] += matriz[i][j];
        }
    }
    printf("\nMultiplicando cada elemento pelo valor da soma da linha correspondente...\n\n");
    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            matriz[i][j] = matriz[i][j]*soma[i];
        }
    }
    printf("Nova matriz:\n");
    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            printf("%-4i ",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
