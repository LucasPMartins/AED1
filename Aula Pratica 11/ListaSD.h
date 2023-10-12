#ifndef LISTASEMDESCRITOR_H_INCLUDED
#define LISTASEMDESCRITOR_H_INCLUDED

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct no* Lista;

Lista *criar();

void mostrar(Lista *l);

int buscarItem(Lista *l,int pos);

int insereInicio(Lista *l,int it);

int removeInicio(Lista *l);

int buscarUltimo(Lista *l,int *ultimo);

int listaVazia(Lista *l);

int soma(Lista *l);

void reversa(Lista *l);

int removeocorrencia(Lista *l,int num);


#endif // LISTASEMDESCRITOR_H_INCLUDED