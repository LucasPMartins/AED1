#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDupla.h"

int main()
{
    int op, op2;
    int ret, pos;
    Aluno it;
    Lista *l = criar();
    printf("--- MENU ---\n");
    do
    {
        printf("1 - Cadastrar aluno\n2 - Remover aluno\n3 - Listar alunos cadastrados\n4 - Trocar alunos\n5 - Remover todos os alunos\n6 - Sair\n");
        printf("Digite uma opcao:");
        setbuf(stdin, NULL);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o nome:");
            setbuf(stdin, NULL);
            fgets(it.nome, 30, stdin);
            it.nome[strcspn(it.nome,"\n")] = '\0';
            printf("Digite a matricula:");
            setbuf(stdin, NULL);
            scanf("%d", &it.mat);
            printf("Digite a nota:");
            setbuf(stdin, NULL);
            scanf("%f", &it.n1);
            ret = inserirmatricula(l,it);
            if(ret == 0) printf("Cadatrado!\n");
            else printf("Erro!\n");
            break;
        case 2:
            printf("\n\n1 - Remover Inicio\n2 - \nRemover Fim\n3 - Remover Posicao\n4 - Remover Item\n");
            printf("Digite uma opcao:");
            setbuf(stdin, NULL);
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                ret = removerInicio(l);
                break;
            case 2:
                ret = removerFim(l);
                break;
            case 3:
                printf("\nDigite a posicao:");
                setbuf(stdin, NULL);
                scanf("%d", &pos);
                ret = removerPosicao(l, pos);
                break;
            case 4:
                printf("Digite a matricula:");
                setbuf(stdin, NULL);
                scanf("%d", &it.mat);
                ret = removerItem(l, it);
            default:
                break;
            }
            break;
        case 3:
            mostrar(l);
            break;
        case 4:
            printf("Posicao 1:");
            fflush(stdin);
            scanf("%d",&pos);
            int pos2;
            printf("Posicao 2:");
            fflush(stdin);
            scanf("%d",&pos2);
            ret = troca(l,pos,pos2);
            if(ret == 0) printf("Operacao realizada com sucesso!\n");
            break;
        case 5:
            limpar(l);
            break;
        default:
            break;
        }
    } while (op != 6);
    return 0;
}