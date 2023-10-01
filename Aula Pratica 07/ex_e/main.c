#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct lista {
    caracter *vet;
    int tamanho_vet;
    char *texto;
}Lista;

int tamanho(Lista *l){
    int count = 0;
    for(int i = 0;l->texto[i] != '\0';i++){
        count++;
    }
    return count;
}

Lista *criar(){
    Lista *l = (Lista *) malloc(sizeof(Lista));
    l->texto = (char *) malloc((2000)*sizeof(char));
    if(l->texto == NULL) printf("Erro !");
    l->tamanho_vet = 0;
    return l;
}

int ocorrencias(Lista *l){
    int i,j,count = 0,tam = 0,tam2 = 0;
    int existe = 0;
    char *c;
    if(l == NULL)return 1;
    if(listavazia(l) == 0) return 2;
    else{
        c = (char *) malloc(1*sizeof(char));
        if(c == NULL) return 3;
        l->vet = (caracter *) malloc(1*sizeof(caracter));
        if(l->vet == NULL) return 3;
        for(i = 0;l->texto[i] != '\0';i++){
            existe = 0;
            for(j = 0;j < tam;j++){
                if(l->texto[i] == c[j]){
                    existe = 1;
                }
            }
            if(existe == 0){
                c[tam] = l->texto[i];
                tam++;
                c = (char *) realloc(c,(tam+1)*sizeof(char));
                count = 0;
                for(j = i;l->texto[j] != '\0';j++){
                    if(l->texto[i] == l->texto[j]){
                        count++;
                    }
                }
                l->vet[tam2].count = count;
                l->vet[tam2].c = l->texto[i];
                tam2++;
                l->vet = (caracter *) realloc(l->vet,(tam2+1)*sizeof(caracter));
                l->tamanho_vet++;
            }
        }
        return 0;
    }
}

int listavazia(Lista *l){
    if(l == NULL) return 1;
    if(tamanho(l) == 0) return 0;
    else return 2;
}

void mostrar(Lista *l){
    printf("Texto:\n %s",l->texto);
    for(int i = 0;i < l->tamanho_vet;i++){
        printf("Letra %c - Ocorrencias: %d\n",l->vet[i].c,l->vet[i].count);
    }
}

void liberar(Lista *l){
    free(l->texto);
    free(l->vet);
}

int main(){
    Lista *l;
    int retorno;
    l = criar();
    printf("Digite o seu texto:");
    fgets(l->texto,2000,stdin);
    l->texto = (char *) realloc(l->texto,(tamanho(l))*sizeof(char));
    retorno = ocorrencias(l);
    if(retorno == 1) printf("Lista nao foi criada!\n");
    if(retorno == 2) printf("Lista vazia!\n");
    if(retorno == 0) mostrar(l);
    liberar(l);
    free(l);
    return 0;
}