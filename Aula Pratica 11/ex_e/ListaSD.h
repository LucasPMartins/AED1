#ifndef LISTASEMDESCRITOR_H_INCLUDED
#define LISTASEMDESCRITOR_H_INCLUDED

struct no {
    int data;
    struct no* next;
};

void displayBinary(struct no* head);

void incrementa(struct no** head);

struct no* criar_no(int data);

#endif // LISTASEMDESCRITOR_H_INCLUDED