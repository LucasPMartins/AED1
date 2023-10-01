#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vet;
    int i;
    vet = (int *) malloc(5*sizeof(int));
    if(vet == NULL){
        printf(("Impossivel alocar memoria!"));
        exit(1);
    }
    printf("Digite 5 numeros:\n");
    for(i = 0;i < 5;i++){
        printf("Numero %d:",i+1);
        scanf(("%d"),vet+i);
    }
    for(i = 0;i < 5;i++){
        printf("Numero %d: %d\n",i+1,*(vet+i));
    }
    free(vet);
    return 0;
}
