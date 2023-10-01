#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

typedef struct no
{
    Aluno valor;
    struct no *prox;
} No;

typedef struct lista
{
    No *final;
} ListaCircular;

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->final = NULL;
    return l;
}
void limpar(Lista *l)
{
    while (listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho(Lista *l)
{
    if (l == NULL)
        return -1;
    if (listaVazia(l) == 0)
        return 0;
    No *noLista = l->final;
    int cont = 0;
    do
    {
        cont++;
        noLista = noLista->prox;
    } while (noLista != l->final);
    return cont;
}

void mostrar(Lista *l)
{
    if (l != NULL)
    {
        printf("[");
        if (listaVazia(l) != 0)
        {
            No *noLista = l->final;
            noLista = noLista->prox;
            do
            {
                printf(" {%d, ", noLista->valor.mat);
                printf("%s, ", noLista->valor.nome);
                printf("%.2f} ", noLista->valor.n1);
                noLista = noLista->prox;
            } while (noLista != l->final->prox);
        }
        printf("]\n");
    }
}

int listaVazia(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->final == NULL)
        return 0;
    else
        return 1;
}
int listaCheia(Lista *l)
{
    return 1;
}

int inserirInicio(Lista *l, Aluno it)
{
    if (l == NULL)
        return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0)
    {
        l->final = no;
        no->prox = no;
    }
    else
    {
        no->prox = l->final->prox;
        l->final->prox = no;
    }
    return 0;
}

int inserirFim(Lista *l, Aluno it)
{
    if (l == NULL)
        return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0)
    {
        return inserirInicio(l,it);
    }
    else
    {
        no->prox = l->final->prox;
        l->final->prox = no;
        l->final = no;
    }
    return 0;
}

int removerInicio(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    if (l->final->prox == l->final)
    {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *n = l->final;
    n = n->prox;
    l->final->prox = n->prox;
    free(n); 
    return 0;
}

int removerFim(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    if (l->final->prox == l->final)
    {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *no = l->final;
    while(no->prox != l->final) no = no->prox;
    no->prox = l->final->prox;
    No *temp = l->final;
    l->final = no;
    free(temp);
    return 0;
}

int removerPosicao(Lista *l, int pos)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (tamanho(l) == 1 || pos == tamanho(l)-1){
        removerFim(l);
        return 0;
    }
    if(pos == 0) return removerInicio(l);
    No *anterior = NULL, *no = l->final;
    while ((pos != 0))
    {
        anterior = no;
        no = no->prox;
        pos--;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int buscarItem(Lista *l, int chave, Aluno *it)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *no = l->final;
    while ((no->prox != l->final) && ((no->valor).mat != chave))
        no = no->prox;
    if ((no->valor).mat != chave)
        return 1;
    else
    {
        *it = no->valor;
        return 0;
    }
}

//Implementacao de B
int removeCentral(Lista *l){
    if(l == NULL) return 3;
    int t = tamanho(l);
    if(t == 0) return 2;
    if(t == 1) return removerInicio(l);
    int d = 1;
    if(t % 2 == 0) d = 0;
        t = (t/2) +d; //t==1
    removerPosicao(l, t);
    return 0;
}

//Implementacao de C

int removePrimeiroItem(Lista*l, int chave){
    if(l == NULL) return 3;
    if(!listaVazia(l)) return 2;
    No* temp = l->final;
    int t=0;
    while(temp->prox != l->final && temp->valor.mat != chave){
        temp = temp->prox;
        t++;
    }
    if(temp->valor.mat != chave){
        return 1;
    }
    return removerPosicao(l,t);
}
//Implementacao de D

int buscarItemChave(Lista *l, int chave){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
        No *no = l->final;
    while ((no->prox != l->final)&&((no->valor).mat != chave))
        no = no->prox;
    if ((no->valor).mat != chave )
        return 1;
    return 0;
}

Lista* interseccao(Lista *l1, Lista* l2){
    if(l1 == NULL) return l1;
    if(l2 == NULL) return l2;
    if(l1 == NULL && l2 == NULL) return criar();
    if(listaVazia(l1)==0) return l2 ;
    if(listaVazia(l2) == 0) return l1;
    Lista *l3 = criar();
    // Alunos que estao nas duas listas
    No* temp = l1->final;
    while(temp->prox != l1->final){
        if(buscarItemChave(l2,temp->valor.mat) == 0){
            inserirInicio(l3,temp->valor);
        }
        temp = temp->prox;
    }

    return l3;
}

// QUESTAO E
int contaOcorrencias(Lista*l, int chave){
    if(l == NULL || listaVazia(l) == 0) return 0;
    No*temp = l->final;
    int cont = 0;
    while(temp->prox != l->final){
        if(temp->valor.mat == chave) cont++;
        temp = temp->prox;
    }
    return cont;    
}

int insercaoFinal_sem_repeticao(Lista* l, Aluno it){
    if(l == NULL) return 3;
    if(contaOcorrencias(l,it.mat) == 0) return inserirFim(l,it);
    return 1;
}