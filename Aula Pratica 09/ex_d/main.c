#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"

int main()
{
    Aluno it;
    it.mat = 1234567;
    it.n1 = 67.9;
    strcpy(it.nome,"Lucas");
    Lista *l = criar();
    inserirInicio(l,it);
    it.mat = 124567;
    it.n1 = 7.9;
    strcpy(it.nome,"Cassio");
    inserirFim(l,it);
    it.mat = 12567;
    it.n1 = 79.9;
    strcpy(it.nome,"Leonardo");
    inserirFim(l,it);
    printf("Lista 1:\n");
    mostrar(l);
    Lista *l2 = criar();
    it.mat = 1234567;
    it.n1 = 67.9;
    strcpy(it.nome,"Lucas");
    inserirInicio(l2,it);
    it.mat = 12567;
    it.n1 = 79.9;
    strcpy(it.nome,"Leonardo");
    inserirInicio(l2,it);
    printf("Lista 2:\n");
    mostrar(l2);
    printf("Lista intersecao:\n");
    Lista *l3 = interseccao(l,l2);
    mostrar(l3);
    return 0;
}
