#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDupla.h"

int main()
{
    Lista *l1,*l2;
    l1 = criar();
    l2 = criar();
    Aluno it;
    
    it.mat = 1234;
    it.n1 = 32;
    strcpy(it.nome,"Lucas");
    inserirInicio(l1,it);
    it.mat = 124;
    it.n1 = 32;
    strcpy(it.nome,"Thiago");
    inserirInicio(l1,it);
    it.mat = 24;
    it.n1 = 22;
    strcpy(it.nome,"Lulu");
    inserirInicio(l1,it);


    it.mat = 1234;
    it.n1 = 32;
    strcpy(it.nome,"Lucas");
    inserirInicio(l2,it);
    it.mat = 13224;
    it.n1 = 32;
    strcpy(it.nome,"Thais");
    inserirInicio(l2,it);
    it.mat = 24424;
    it.n1 = 22;
    strcpy(it.nome,"Matheus");
    inserirInicio(l2,it);


    mostrar(l1);
    printf("\n");
    mostrar(l2);


    it.mat = 1234;
    it.n1 = 32;
    strcpy(it.nome,"Lucas");
    int ret = aluno_rep(l1,l2,it);
    if (ret == 0)
    printf("Aluno se repete!\n");
    else printf("Aluno nao se repete!\n");

    return 0;
}