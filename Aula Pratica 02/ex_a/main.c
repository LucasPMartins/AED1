#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[] = "Carla Faria";
    double *vet;
    int i;
    for(i = 0;nome[i] != '\0';i++){
        printf("%c\n",nome[i]);
    }
    vet = (double *) malloc(10*sizeof(double));
    for(i = 0;i < 10;i++){
        printf("%e\n",*(vet+i));
    }
    free(vet);
    return 0;
}
