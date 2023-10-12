#include <stdio.h>
#include <stdlib.h>
#include "ListaSD.h"

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    (*l) = NULL;
    return l;
}

void mostrar(Lista *l)
{
    if (l != NULL)
    {
        if ((listaVazia(l)) != 0)
        {
            no *no = (*l);
            printf("%d, ", no->valor);
            mostrar(&(no->prox));
        }
    }
}

int buscarItem(Lista *l, int pos)
{
    if (l == NULL)
        return 2;
}

int insereInicio(Lista *l, int it)
{
    if (l == NULL)
        return 1;
    no *nl = (no *)malloc(sizeof(no));
    nl->valor = it;
    nl->prox = (*l);
    (*l) = nl;
    return 0;
}

int removeInicio(Lista *l)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    no *nl = (*l);
    (*l) = (*l)->prox;
    free(nl);
    return 0;
}
// ex a
int buscarUltimo(Lista *l, int *ultimo)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    no *nl = (*l);
    if (nl->prox == NULL)
    {
        *ultimo = nl->valor;
        return 0;
    }
    return buscarUltimo(&(nl->prox), ultimo);
}

int listaVazia(Lista *l)
{
    if (l == NULL)
        return 1;
    if ((*l) == NULL)
        return 0;
    return 2;
}
// ex b
int soma(Lista *l)
{
    if (l == NULL)
        return 0;
    if (listaVazia(l) == 0)
        return 0;
    no *nl = (*l);
    if (nl != NULL)
    {
        return nl->valor + soma(&(nl->prox));
    }
}
// ex c
void reversa(Lista *l)
{
    if (l != NULL)
    {
        if (listaVazia(l) != 0)
        {
            no *nl = (*l);
            reversa(&(nl->prox));
            printf("%d, ", nl->valor);
        }
    }
}
// ex d
int removeocorrencia(Lista *l, int num)
{
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    no *nl = (*l);
    if (nl->valor == num)
    {
        (*l) = (*l)->prox;
        free(nl);
        return removeocorrencia(l, num);
    }
    return removeocorrencia(&nl->prox, num);
}
