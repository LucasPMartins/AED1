#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int cpf;
    char estado[20];
    int filhos;
    char sobrenome[20];
}dados;

int main()
{
    int opcao,i,n,pos;
    int count = 0;
    dados *clientes;
    printf("Digite quantos clientes os dados serao manipulandos no programa:");
    scanf("%d",&n);
    clientes = (dados *) malloc(n*sizeof(dados));
    if(clientes ==  NULL){
        printf("Memoria insufiente!");
        return 0;
    }
    do{
        printf("\n--- MENU ---\n\n");
        printf("(1)inserir cliente no vetor\n(2)remover cliente do vetor\n(3)mostrar os CPFs dos clientes ja inseridos\n(4)sair\n\n");
        printf("Digite uma opcao:");
        scanf("%d",&opcao);
        if(opcao == 1){
            printf("Digite o CPF do cliente:");
            setbuf(stdin,NULL);
            scanf("%d",&clientes[count].cpf);
            printf("Digite o estado civil do cliente:");
            setbuf(stdin,NULL);
            fgets(clientes[count].estado,20,stdin);
            printf("Digite quantos filhos tem o cliente:");
            setbuf(stdin,NULL);
            scanf("%d",&clientes[count].filhos);
            if(clientes[count].filhos > 0){
                printf("Digite o sobrenome dos seus filhos:");
                setbuf(stdin,NULL);
                fgets(clientes[count].sobrenome,20,stdin);
            }
            printf("Dados do cliente salvos!\n\n");
            count++;
            opcao = 0;
        }
        if(opcao == 2){
            printf("Digite a posicao do vetor do cliente:");
            setbuf(stdin,NULL);
            scanf("%d",&pos);
            for(i = pos;i < count;i++){
                clientes[i].cpf = clientes[i+1].cpf;
                clientes[i].filhos = clientes[i+1].filhos;
                strcpy(clientes[i].estado, clientes[i+1].estado);
                strcpy(clientes[i].sobrenome, clientes[i+1].sobrenome);
            }
            printf("Cliente removido!\n\n");
            count--;
            opcao = 0;
        }
        if(opcao == 3){
            printf("CPFs dos clientes ja cadastrados:\n");
            for(i = 0;i < count;i++){
                printf("Cliente %d - CPF:%d\n",i,clientes[i].cpf);
            }
            opcao = 0;
        }
        if(opcao == 4){
            printf("Saindo...\n");
        }
    }while(opcao != 4 );
    free(clientes);
    return 0;
}
