#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSD.h"

int main() {
    struct no* lista = NULL;
    char string[32];
    int num;
    printf("Digite um numero binario : ");
    scanf("%s", string);
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != '0' && string[i] != '1') {
            printf("Entrada invalida. O numero deve ser binario.\n");
            return 1;
        }
        int digit = string[i] - '0';
        struct no* novo_no = criar_no(digit);
        novo_no->next = lista;
        lista = novo_no;
    }
    printf("Digite um numero inteiro para incrementar: ");
    scanf("%d", &num);
    while (num > 0) {
        incrementa(&lista);
        num--;
    }
    printf("Resultado em binario: ");
    displayBinary(lista);
    printf("\n");
    while (lista != NULL) {
        struct no* temp = lista;
        lista = lista->next;
        free(temp);
    }
    return 0;
}
