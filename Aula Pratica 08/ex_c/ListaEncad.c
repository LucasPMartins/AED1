#include "ListaEncad.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    Aluno valor;
    struct no *prox;
} No;

typedef struct lista
{
    No *inicio;
} Lista;

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int listaVazia(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    return 1;
}

int inserirInicio(Lista *l, Aluno it)
{
    if (l == NULL)
        return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    l->inicio = no;
    return 0;
}

int inserirFim(Lista *l, Aluno it)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return inserirInicio(l, it);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao(Lista *l, Aluno it, int pos)
{
    if (l == NULL)
        return 2;
    if (pos < 0)
        return 3;
    if ((listaVazia(l) == 0) || (pos == 0))
        return inserirInicio(l, it);
    No *noLista = l->inicio;
    int p = 0;
    while ((noLista->prox != NULL) && (p != pos))
    {
        p++;
        noLista = noLista->prox;
    }
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerInicio(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int removerFim(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL)
        l->inicio = NULL;
    else
        noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int removerItem(Lista*l,Aluno it){
    if(l == NULL) return 1;
    if(listaVazia(l) == 0) return 2;
    No *nolista = l->inicio;
    No *aux = NULL;
    while(nolista->prox != NULL){
        if(nolista->valor.mat == it.mat){
            break;
        }
        aux = nolista;
        nolista = nolista->prox;
    }
    if(aux == NULL) l->inicio = NULL;
    else aux->prox = nolista->prox;
    free(nolista);
    return 0;
}

int removerPosicao(Lista*l,int pos){
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    if(pos > tamanho(l)) return 3;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    int p = 0;
    while (noLista->prox != NULL && p != pos)
    {
        p++;
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL)
        l->inicio = NULL;
    else
        noAuxiliar = noLista->prox;
    free(noLista);
    return 0;
}

int buscarItemChave(Lista *l, int chave, Aluno *retorno)
{
    if (l == NULL)
        return 2;
    No *noLista = l->inicio;
    while ((noLista != NULL))
    {
        if ((noLista->valor).mat == chave)
        {
            *retorno = noLista->valor;
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

int ContemItem(Lista *l,Aluno it){
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return 3; 
    No *nolista = l->inicio;
    while(nolista != NULL){
        if(nolista->valor.mat == it.mat){
            return 0;
        }
        nolista = nolista->prox;
    }
    return 1;
}

int buscarPosicao(Lista*l,int posicao,Aluno *retorno){
    if (posicao < 0) return 3;
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(posicao > tamanho(l)) return -1;
    No *noLista = l->inicio;
    int p = 0;
    while ((noLista != NULL) && p != posicao)
    {
        p++;
        noLista = noLista->prox;
    }
    *retorno = noLista->valor;
    return 0;
}

void limpar(Lista *l)
{
    while (listaVazia(l) != 0)
        removerInicio(l);
}

void mostrar(Lista *l)
{
    if (l != NULL)
    {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL)
        {
            printf(" {%d, ", noLista->valor.mat);
            printf("%s, ", noLista->valor.nome);
            printf("%.2f} ", noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

Lista *Concatena(Lista *l1,Lista *l2){
    if(l1 == NULL || l2 == NULL) return NULL;
    if(listaVazia(l1) && listaVazia(l2)) return NULL;
    Lista *ret = criar();
    No *nolista = l1->inicio;
    while(nolista->prox != NULL){
        inserirFim(ret,nolista->valor);
        nolista = nolista->prox;
    }
    No *nolista = l2->inicio;
    while(nolista->prox != NULL){
        inserirFim(ret,nolista->valor);
        nolista = nolista->prox;
    }
    return ret;
}

int maior(Lista *l,Aluno *retorno){
    if(l == NULL) return 1;
    if(listaVazia(l) == 0) return 2;
    No *nolista = l->inicio;
    *retorno = nolista->valor; 
    while(nolista->prox != NULL){
        if(nolista->valor.n1 > retorno->n1){
            *retorno = nolista->valor;
        }
        nolista = nolista->prox;
    }
    printf("Nome: %s",(retorno->nome));
    printf("Mat: %d\n",(retorno->nome));
    printf("N1: %f\n",(retorno->n1));
    return 0;
}