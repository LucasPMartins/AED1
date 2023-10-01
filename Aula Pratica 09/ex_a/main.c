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
    mostrar(l);
    removerFim(l);
    mostrar(l);
    it.mat = 12567;
    it.n1 = 79.9;
    strcpy(it.nome,"Leonardo");
    inserirInicio(l,it);
    mostrar(l);
    return 0;
}
