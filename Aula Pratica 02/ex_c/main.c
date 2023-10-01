#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **mat1;
    int **mat2;
    int **mat3;
    int i,j;
    srand(time(NULL));
    mat1 = (int **) malloc(3*sizeof(int *));
    if(mat1 == NULL){
        printf("Memoria insuficiente!");
        exit (1);
    }
    for(i = 0;i < 3;i++){
        mat1[i] = (int *) malloc(3*sizeof(int));
        if(mat1[i] == NULL){
        printf("Memoria insuficiente!");
        exit (1);
        }
        for(j = 0;j < 3;j++){
            mat1[i][j] = rand() % 100;
        }
    }
    mat2 = (int **) malloc(3*sizeof(int *));
    if(mat2 == NULL){
        printf("Memoria insuficiente!");
        exit (1);
    }
    for(i = 0;i < 3;i++){
        mat2[i] = (int *) malloc(3*sizeof(int));
        if(mat2[i] == NULL){
        printf("Memoria insuficiente!");
        exit (1);
        }
        for(j = 0;j < 3;j++){
            mat2[i][j] = rand() % 100;
        }
    }
    printf("\nMatriz 1: 3x3\n\n");
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            printf("[%-3d]",mat1[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz 2: 3x3\n\n");
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            printf("[%-3d]",mat2[i][j]);
        }
        printf("\n");
    }
    mat3 = (int **) malloc(3*sizeof(int *));
    if(mat3 == NULL){
        printf("Memoria insuficiente!");
        exit (1);
    }
    for(i = 0;i < 3;i++){
        mat3[i] = (int *) malloc(3*sizeof(int));
        if(mat3[i] == NULL){
        printf("Memoria insuficiente!");
        exit (1);
        }
        for(j = 0;j < 3;j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nMatriz 3: 3x3\n\n");
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            printf("[%-3d]",mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
