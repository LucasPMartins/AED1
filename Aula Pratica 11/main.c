#include <stdio.h>
#include <stdlib.h>
#include "ListaSD.h"

int main ()
{
    int escolha, num;
    Lista *l = criar();
    int retorno;
    int x;

    do{
        

        printf("\nEscolha uma opcao:\n\n");
        printf("1 - Inserir inicio.\n");
        printf("2 - Remover inicio.\n");
        printf("3 - Buscar item chave.\n");
        printf("4 - Mostrar.\n");
        printf("5 - Ver o ultimo elemento.\n");
        printf("6 - Reverse.\n");
        printf("7 - Remove ocorrencias.\n");
        printf("8 - Sair.\n\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            
            printf("Insira o numero: ");
            scanf("%d", &num);
            insereInicio(l, num);
            break;
        
        case 2:
            removeInicio(l);
            break;
        
        case 3:
            printf("Insira o numero que busca: ");
            scanf("%d", &num);
            
            break;
        case 4:
            mostrar(l);
            break;
        case 5:
            x = buscarUltimo(l,&retorno);
            if(x == 2){
                printf("Lista nao criada!");
            }else if(x == 1){
                printf("Lista vazia!");
            }else{
                printf("O ultimo numero eh %d!", retorno);
            }
            break;
        case 6:
            reversa(l);
            break;
        case 7:
            removeocorrencia(l,1);
            break;
        case 8:
            break;
        default:
            break;
        }
    }while (escolha != 8);
    return 0;
}