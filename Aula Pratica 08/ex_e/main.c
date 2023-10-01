#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncad.h"

Lista *criar() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int insere_Aeroporto(Lista *l, char *nome, char *sigla) {
    if (l == NULL)
        return 1;
    Aeroporto *a = (Aeroporto *)malloc(sizeof(Aeroporto));
    strcpy(a->nome, nome);
    strcpy(a->sigla, sigla);
    a->inicio = NULL;
    a->proximo = l->inicio;
    l->inicio = a;
    return 0;
}

int insere_Rota(Lista *l, char *nome_cidade, char *origem, char *destino, float preco) {
    if (l == NULL)
        return 1;
    Aeroporto *a = l->inicio;
    while (a != NULL) {
        if (strcmp(a->nome, nome_cidade) == 0) {
            Rota *r = (Rota *)malloc(sizeof(Rota));
            strcpy(r->destino, destino);
            strcpy(r->origem, origem);
            r->preco = preco;
            r->proximo = a->inicio;
            a->inicio = r;
            return 0;
        }
        a = a->proximo;
    }
    return 2;
}

int listaVazia(Lista *l) {
    if (l == NULL)
        return 1;
    if (l->inicio == NULL)
        return 0;
    else
        return 2;
}

void formata_nome(char *nome) {
    int i;
    for (i = 0; nome[i] != '\0'; i++)
        if (nome[i] == '\n' && nome[i + 1] == '\0')
            nome[i] = '\0';
}

int mais_barata(Lista *l, char *nome_cidade, Rota *retorno) {
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    Aeroporto *no = l->inicio;
    while (no != NULL) {
        if (strcmp(no->nome, nome_cidade) == 0) {
            Rota *no2 = no->inicio;
            if (no->inicio == NULL)
                return 4; // rota vazia
            float menor = no2->preco;
            while (no2->proximo != NULL) {
                if (no2->preco < menor) {
                    menor = no2->preco;
                }
                no2 = no2->proximo;
            }
            strcpy(retorno->destino, no2->destino);
            strcpy(retorno->origem, no2->origem);
            retorno->preco = menor;
            retorno->proximo = NULL;
            return 0;
        }
        no = no->proximo;
    }
    return 3; // nome da cidade nao encontrado
}

int mais_cara(Lista *l, char *nome_cidade, Rota *retorno) {
    if (l == NULL)
        return 1;
    if (listaVazia(l) == 0)
        return 2;
    Aeroporto *no = l->inicio;
    while (no != NULL) {
        if (strcmp(no->nome, nome_cidade) == 0) {
            Rota *no2 = no->inicio;
            if (no->inicio == NULL)
                return 4; // rota vazia
            float maior = no2->preco;
            while (no2->proximo != NULL) {
                if (no2->preco > maior) {
                    maior = no2->preco;
                }
                no2 = no2->proximo;
            }
            strcpy(retorno->destino, no2->destino);
            strcpy(retorno->origem, no2->origem);
            retorno->preco = maior;
            retorno->proximo = NULL;
            return 0;
        }
        no = no->proximo;
    }
    return 3; // nome da cidade nao encontrado
}

void consulta(Lista *l, char *origem, char *destino) {
    if (l == NULL)
        printf("Lista nao criada!\n");
    if (listaVazia(l) == 0)
        printf("Lista vazia!\n");
    Aeroporto *no = l->inicio;
    while (no != NULL) {
        Rota *no2 = no->inicio;
        while (no2 != NULL) {
            if (strcmp(no2->destino, destino) == 0 && strcmp(no2->origem, origem) == 0) {
                printf("Cidade: %s\n",no->nome);
                printf("Origem: %s\n", no2->origem);
                printf("Destino: %s\n", no2->destino);
                printf("Preco: %.2f\n", no2->preco);
            }
            no2 = no2->proximo;
        }
        no = no->proximo;
    }
}

void mostrar(Lista *l) {
    if (l == NULL)
        printf("Lista nao criada!\n");
    if (listaVazia(l) == 0)
        printf("Lista vazia!");
    Aeroporto *no = l->inicio;
    Rota *r;
    while (no != NULL) {
        printf("----======----\n");
        printf("Nome: %s\n", no->nome);
        printf("Sigla: %s\n", no->sigla);
        r = no->inicio;
        while (r != NULL) {
            printf("\nOrigem: %s -> ", r->origem);
            printf("Destino: %s\n", r->destino);
            printf("Preco: %.2f\n", r->preco);
            r = r->proximo;
        }
        printf("\n");
        no = no->proximo;
    }
    printf("----======----\n");
}

int main() {
    Lista *l = criar();
    char nome[50];
    char origem[4], destino[4];
    insere_Aeroporto(l, "Sao Paulo", "SPA");
    insere_Aeroporto(l, "Minas Gerais", "MGA");
    insere_Aeroporto(l, "Rio de Janeiro", "RJA");
    insere_Rota(l, "Sao Paulo", "GRU", "GIG", 500);
    insere_Rota(l, "Minas Gerais", "GAU", "BSB", 300);
    insere_Rota(l, "Rio de Janeiro", "GIG", "BSB", 400);

    int opcao;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Mostrar a rota mais barata\n");
        printf("2. Mostrar a rota mais cara\n");
        printf("3. Consultar o preco de um trecho\n");
        printf("4. Mostrar lista\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: {
            Rota rotaMaisBarata;
            printf("Nome da cidade:");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            formata_nome(nome);
            printf("\n");
            if (mais_barata(l, nome, &rotaMaisBarata) == 0) {
                printf("Rota mais barata: %s -> %s (Preco: %.2f)\n",
                       rotaMaisBarata.origem, rotaMaisBarata.destino, rotaMaisBarata.preco);
            } else {
                printf("Nenhuma rota encontrada.\n");
            }
        } break;
        case 2: {
            Rota rotaMaisCara;
            printf("Nome da cidade:");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            formata_nome(nome);
            printf("\n");
            if (mais_cara(l, nome, &rotaMaisCara) == 0) {
                printf("Rota mais cara: %s -> %s (Preco: %.2f)\n",
                       rotaMaisCara.origem, rotaMaisCara.destino, rotaMaisCara.preco);
            } else {
                printf("Nenhuma rota encontrada.\n");
            }
        } break;
        case 3: {
            printf("Digite a sigla de origem: ");
            setbuf(stdin, NULL);
            scanf("%s", origem);
            formata_nome(origem);
            printf("Digite a sigla de destino: ");
            setbuf(stdin, NULL);
            scanf("%s", destino);
            formata_nome(destino);
            printf("\n");
            consulta(l, origem, destino);
        } break;
        case 4:
            mostrar(l);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 5);

    // Libere a memória alocada
    Aeroporto *no = l->inicio;
    while (no != NULL) {
        Rota *rota = no->inicio;
        while (rota != NULL) {
            Rota *temp = rota;
            rota = rota->proximo;
            free(temp);
        }
        Aeroporto *temp = no;
        no = no->proximo;
        free(temp);
    }
    free(l);

    return 0;
}
