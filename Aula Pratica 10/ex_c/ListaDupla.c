#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDupla.h"

typedef struct no
{
    Aluno valor;
    struct no *prox;
    struct no *ant;
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
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
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

int listaVazia(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
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
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)
        l->inicio->ant = no;
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
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;
}

int inserirPos(Lista *l, int pos, Aluno it)
{
    if (l == NULL)
        return 1;
    if ((listaVazia(l) == 0) || (pos == 0))
    {
        return inserirInicio(l, it);
    }
    No *nl = l->inicio;
    while ((nl != NULL) && (pos > 0))
    {
        nl = nl->prox;
        pos--;
    }
    if (nl == NULL)
        return inserirFim(l, it);
    else
    {
        No *n = (No *)malloc(sizeof(No));
        n->valor = it;
        n->prox = nl;
        n->ant = nl->ant;
        nl->ant = n;
        n->ant->prox = n;
    }
    return 0;
}

int removerInicio(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    if (noLista->prox == NULL)
    {
        l->inicio = NULL;
        free(noLista);
        return 0;
    }
    l->inicio = noLista->prox;
    l->inicio->ant = NULL;
    free(noLista);
    return 0;
}

int removerFim(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    if (noLista->ant == NULL)
        l->inicio = NULL;
    else
        noLista->ant->prox = NULL;
    free(noLista);
    return 0;
}

int removerPosicao(Lista *l, int pos)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    No *n = l->inicio;
    while ((n->prox != NULL) && (pos > 0))
    {
        n = n->prox;
        pos--;
    }
    if (n->ant == NULL)
        return removerInicio(l);
    if (n->prox == NULL)
        return removerFim(l);
    n->ant->prox = n->prox;
    n->prox->ant = n->ant;
    free(n);
    return 0;
}

void maior_nota(Lista *l)
{
    if (l == NULL)
        printf("Lista nao criada!\n");
    if (listaVazia(l) == 0)
        printf("Lista Vazia!\n");
    Aluno ret;
    ret.n1 = l->inicio->valor.n1;
    strcpy(ret.nome, l->inicio->valor.nome);
    ret.mat = l->inicio->valor.mat;
    No *n = l->inicio;
    while (n->prox != NULL)
    {
        n = n->prox;
        if (n->valor.n1 > ret.n1)
        {
            ret.n1 = n->valor.n1;
            strcpy(ret.nome, n->valor.nome);
            ret.mat = n->valor.mat;
        }
    }
    printf("Aluno com maior nota:\n");
    printf("Nome: %s\n", ret.nome);
    printf("Matricula: %d\n", ret.mat);
    printf("Nota: %.2f\n", ret.n1);
}

int inserirmatricula(Lista *l, Aluno it)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return inserirInicio(l, it);
    No *n = (No *)malloc(sizeof(No));
    n->valor = it;
    No *no = l->inicio;
    while (no != NULL)
    {
        if (it.mat <= no->valor.mat)
        {
            if (no->ant == NULL)
                return inserirInicio(l, it);
            no->ant->prox = n;
            n->ant = no->ant->prox;
            n->prox = no;
            return 0;
        }
        no = no->prox;
    }
    return inserirFim(l, it);
}

int removerItem(Lista *l, Aluno it)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    No *n = l->inicio;
    while (n->prox != NULL)
    {
        if (n->prox->valor.mat == it.mat)
        {
            n->ant->prox = n->prox;
            n->prox->ant = n->ant;
            free(n);
        }
        n = n->prox;
    }
    return 0;
}

int troca(Lista *l, int pos1, int pos2)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    if (pos1 > tamanho(l) || pos2 > tamanho(l))
        return 3;
    if (pos1 == pos2)
        return 4;
    No *n1 = l->inicio;
    while (n1->prox != NULL && pos1 > 0)
    {
        n1 = n1->prox;
        pos1--;
    }
    No *n2 = l->inicio;
    while (n2->prox != NULL && pos2 > 0)
    {
        n2 = n2->prox;
        pos2--;
    }
    No *temp = n1;
    n1->ant->prox = n2;
    n1->prox->ant = n2;
    n2->ant->prox = temp;
    n2->prox->ant = temp;
    return 0;
}

int aluno_rep(Lista *l1, Lista *l2, Aluno it)
{
    if (l1 == NULL || l2 == NULL)
        return 1;
    if (listaVazia(l1) == 0 || listaVazia(l2) == 0)
        return 2;
    No *n1 = l1->inicio;
    No *n2 = l2->inicio;
    int teste = 1, teste2 = 1;
    while (n1 != NULL)
    {
        if (n1->valor.mat == it.mat)
            teste = 0;
        n1 = n1->prox;
    }
    while (n2 != NULL)
    {
        if (n2->valor.mat == it.mat)
            teste2 = 0;
        n2 = n2->prox;
    }
    if (teste2 == 0 && teste == 0)
    {
        return 0;
    }
    else
        return 3;
}