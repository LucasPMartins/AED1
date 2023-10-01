#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDupla.h"

int main()
{
    Lista *l1;
    l1 = criar();
    Aluno it;
    
   
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
    inserirInicio(l1,it);
    
    it.mat = 13224;
    it.n1 = 32;
    strcpy(it.nome,"Thais");
    inserirInicio(l1,it);
    it.mat = 24424;
    it.n1 = 22;
    strcpy(it.nome,"Matheus");
    inserirInicio(l1,it);
    it.mat = 1234;
    it.n1 = 32;
    strcpy(it.nome,"Lucas");
    inserirInicio(l1,it);

    mostrar(l1);

    printf("removendo repetidos...\n");

    int ret = removerRepetido(l1);

    if(ret != 0) printf("erro\n");

    mostrar(l1);

    return 0;
}