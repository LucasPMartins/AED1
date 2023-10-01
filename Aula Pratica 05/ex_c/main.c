#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k = 0,l;
    int **mat;
    int *vet;
    printf("Digite as dimensoes da matriz:");
    scanf("%d %d",&n,&m);
    mat = (int **) malloc(n*sizeof(int *));
    printf("Digite os numeros da matriz:\n");
    for(i = 0;i < n;i++){
        mat[i] = (int *) malloc(m*sizeof(int));
        for(j = 0;j < m;j++){
            printf("Numero [%d,%d]:",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    vet = (int *) malloc((n*m)*sizeof(int));
    printf("Matriz %dx%d:\n",n,m);
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            printf("[%d]",mat[i][j]);
            vet[k] = mat[i][j];
            k++;
        }
        printf("\n");
    }
    for(i = 0;i < k;i++){
        for(j = i+1;j < k;j++){
            if(vet[j] == vet[i]){
                for(l = j;l < k;l++){
                    vet[l] = vet[l+1];
                }
                k--;
                vet = (int *) realloc(vet,k*sizeof(int));
            }
        }
    }
    vet = (int *) realloc(vet,k*sizeof(int));
    printf("\nVetor do numeros presentes na matriz:");
    printf("[");
    for(i = 0;i < k;i++){
        printf("%d ",vet[i]);
    }
    printf("]");
    free(vet);
    for(i = 0;i < n;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}
