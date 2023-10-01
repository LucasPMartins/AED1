#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[30];
    char *c;
    int existe;
    int teste = 0;
    int nao_existe = 1;
    int i,j,k = 0;
    c = (char *) malloc(sizeof(char));
    if(c == NULL){
        printf("Memoria insuficiente!\n");
        free(c);
        exit(1);
    }
    printf("Entre com a string:");
    fgets(str,30,stdin);
    for(i = 0;str[i] != '\0';i++){
        existe = 0;
        for(j = 0;str[j] != '\0';j++){
            if(str[i] == str[j]){
                existe++;
            }
        }
        if(existe > 1){
            c = (char *) realloc(c,(k+1)*sizeof(char));
            if(c == NULL){
                printf("Memoria insuficiente!\n");
                free(c);
                exit(1);
            }
            for(j = 0;c[j] != '\0';j++){
                if(str[i] == c[j]){
                    teste = 1;
                }
            }
            if(teste == 0){
                c[k] = str[i];
                k++;
            }
            c[k+1] = '\0';
            teste = 0;
            nao_existe = 0;
        }
    }
    for(i = 0;c[i] != '\0';i++){
        printf("Letra repetida: %c\n",c[i]);
    }
    if(nao_existe == 1){
        printf("Nao existe letras repetidas!");
    }
    return 0;
}
