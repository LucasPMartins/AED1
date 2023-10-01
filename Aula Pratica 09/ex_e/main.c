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
    it.mat = 1234567;
    it.n1 = 67.9;
    strcpy(it.nome,"Lucas");
    printf("Sem repeticao 1:\n");
    insercaoFinal_sem_repeticao(l,it);
    mostrar(l);
    it.mat = 127;
    it.n1 = 67;
    strcpy(it.nome,"Tais");
    printf("Sem repeticao 2:\n");
    insercaoFinal_sem_repeticao(l,it);
    mostrar(l);
    return 0;
}
