#include <stdio.h>
#include <stdlib.h>
#include "ListaSD.h"

struct no* criar_no(int data) {
    struct no* novo_no = (struct no*)malloc(sizeof(struct no));
    novo_no->data = data;
    novo_no->next = NULL;
    return novo_no;
}

void incrementa(struct no** head) {
    if (*head == NULL) {
        *head = criar_no(1);
        return;
    }

    if ((*head)->data == 0) {
        (*head)->data = 1;
    } else {
        (*head)->data = 0;
        incrementa(&((*head)->next));
    }
}

void displayBinary(struct no* head) {
    if (head == NULL) {
        return;
    }
    displayBinary(head->next);
    printf("%d", head->data);
}