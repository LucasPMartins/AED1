#include <stdlib.h>
#include <stdio.h>
#include "ListaEncad.h"

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
    nolista = l2->inicio;
    while(nolista->prox != NULL){
        inserirFim(ret,nolista->valor);
        nolista = nolista->prox;
    }
    return ret;
}

int tamanho(Lista *l){
    if(l == NULL) return 0;
    if(listaVazia(l) == 0) return 0;
    int i = 0;
    No *lista = l->inicio;
    while(lista->prox != NULL){
        i++;
        lista = lista->prox;
    }
    return i;
}

int main(){
    int op,op2;
    int retorno;
    int pos,mat;
    Aluno it;
    Lista *l;
    do{
        printf("1 - criar\n2 - inserir\n3 - remover\n4 - buscar\n5 - mostrar\n6 - contem\n7 - concatena:");
        setbuf(stdin,NULL);
        scanf("%d",&op);
        if(op == 1){
            l = criar();
        }
        if(op == 2){//inserir
            printf("Nome:");
            setbuf(stdin,NULL);
            fgets(it.nome,30,stdin);
            printf("Mat:");
            setbuf(stdin,NULL);
            scanf("%d",&it.mat);
            printf("N1:");
            setbuf(stdin,NULL);
            scanf("%f",&it.n1);
            printf("1 - inicio\n2 - fim\n3 - posicao:");
            setbuf(stdin,NULL);
            scanf("%d",&op2);
            if(op2 == 1){
                retorno = inserirInicio(l,it);
                if(retorno == 2) printf("Lista nao criada!\n");
            }
            if(op2 == 2){
                retorno = inserirFim(l,it);
                if(retorno == 2) printf("Lista nao criada!\n");
            }
            if(op2 == 3){
                printf("Digite a posicao:");
                setbuf(stdin,NULL);
                scanf("%d",&pos);
                retorno = inserirPosicao(l,it,pos);
                if(retorno == 2) printf("Lista nao criada!\n");
                if(retorno == 3) printf("Posicao inexistente!\n");
            }
        }
        if(op == 3){//remover
            printf("1 - inicio\n2 - fim\n3 - posicao\n4 - item:");
            setbuf(stdin,NULL);
            scanf("%d",&op2);
            if(op2 == 1){
                retorno = removerInicio(l);
                if(retorno == 1) printf("Lista nao criada!\n");
                if(retorno == 2) printf("Lista vazia!\n");
            }
            if(op2 == 2){
                retorno = removerFim(l);
                if(retorno == 1) printf("Lista nao criada!\n");
                if(retorno == 2) printf("Lista vazia!\n");
            } 
            if(op2 == 3){
                printf("Digite a posicao:");
                setbuf(stdin,NULL);
                scanf("%d",&pos);
                retorno = inserirPosicao(l,it,pos);
                if(retorno == 2) printf("Lista nao criada!\n");
                if(retorno == 1) printf("Lista vazia!\n");
                if(retorno == 3) printf("Posicao inexistente!\n");
            }
            if(op2 == 4){
                printf("Nome:");
                setbuf(stdin,NULL);
                fgets(it.nome,30,stdin);
                printf("Mat:");
                setbuf(stdin,NULL);
                scanf("%d",&it.mat);
                printf("N1:");
                setbuf(stdin,NULL);
                scanf("%f",&it.n1);
                retorno = removerItem(l,it);
                if(retorno == 1) printf("Lista nao criada!\n");
                if(retorno == 2) printf("Lista vazia!\n");
            }
        }
        if(op == 4){//buscar
            printf("1 - item\n2 - posicao:");
            setbuf(stdin,NULL);
            scanf("%d",&op2);
            if(op2 == 1){
                printf("Mat:");
                setbuf(stdin,NULL);
                scanf("%d",&mat);
                retorno = buscarItemChave(l,mat,&it);
                if(retorno == 2) printf("lista nao criada!\n");
                else{
                    printf("Nome:%s",it.nome);
                    printf("Mat:%d",it.mat);
                    printf("N1:%f",it.n1);
                }
            }
            if(op2 == 2){
                printf("Digite a posicao:");
                setbuf(stdin,NULL);
                scanf("%d",&pos);
                retorno = buscarPosicao(l,pos,&it);
                if(retorno == 3 || retorno == -1) printf("posicao inexistente!\n");
                if(retorno == 2) printf("Lista nao criada!\n");
                if(retorno == 1) printf("Lista vazia!\n");
                else{
                    printf("Nome:%s",it.nome);
                    printf("Mat:%d",it.mat);
                    printf("N1:%f",it.n1);
                }
            }
        }
        if(op == 5){
            mostrar(l);
        }
        if(op == 6){
            printf("Nome:");
            setbuf(stdin,NULL);
            fgets(it.nome,30,stdin);
            printf("Mat:");
            setbuf(stdin,NULL);
            scanf("%d",&it.mat);
            printf("N1:");
            setbuf(stdin,NULL);
            scanf("%f",&it.n1); 
            retorno = ContemItem(l,it);
            if(retorno == 3) printf("Lista vazia!\n");
            if(retorno == 2) printf("Lista nao criada!\n");
            if(retorno == 1) printf("Item nao encontrado!\n");
            if(retorno == 0) printf("Item encontrado!\n");
        }
        if(op == 7){
            Lista *l2;
            l2 = criar();
            do{
                printf("Inserir?(0 -> Sim)");
                setbuf(stdin,NULL);
                scanf("%d",&op2);
                if(op2 == 0){
                    printf("Nome:");
                    setbuf(stdin,NULL);
                    fgets(it.nome,30,stdin);
                    printf("Mat:");
                    setbuf(stdin,NULL);
                    scanf("%d",&it.mat);
                    printf("N1:");
                    setbuf(stdin,NULL);
                    scanf("%f",&it.n1);
                    retorno = inserirFim(l2,it);
                    if(retorno == 2) printf("Lista nao criada!\n");
                }
            }while(op2 != 0);
            Lista *ret;
            ret = Concatena(l,l2);
            mostrar(ret);
        }
    }while(op > 0 && op < 5);
    return 0;
}