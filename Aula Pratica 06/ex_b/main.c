#include <stdio.h>
#include <stdlib.h>
#include "TAD_conjunto.h"

typedef struct Conjuntos_inteiros {
    int *numeros;
    int tamanho;
    char nome;
}conjunto;

conjunto *cria(int *vetor,int tamanho,char c){
    conjunto *conj;
    int i;
    conj = (conjunto *) malloc(sizeof(conjunto));
    conj->numeros = (int *) malloc(tamanho*sizeof(int));
    for(i = 0; i < tamanho;i++){
        conj->numeros[i] = vetor[i];
    }
    conj->tamanho = tamanho;
    conj->nome = c;
    return conj;
}

void membro(conjunto *a,int num){
    int i,teste = 1;
    for(i = 0;i < a->tamanho;i++){
        if(a->numeros[i] == num){
            printf("O numero %d eh membro do conjunto %c\n",num,a->nome);
            teste = 0;
            break;
        }
    }
    if(teste == 1)
        printf("O numero %d nao eh membro do conjunto %c\n",num,a->nome);
}

int *insere(conjunto *a,int num){
    int *vet;
    int i;
    for(i = 0;i < a->tamanho;i++){
        if(num == a->numeros[i]){
            printf("Numero ja exite no conjunto!\n");
            break;
            return a->numeros;
        }
    }
    vet = (int *) malloc((a->tamanho+1)*sizeof(int));
    for(i = 0;i < a->tamanho;i++){
        vet[i] = a->numeros[i];
    }
    vet[a->tamanho+1] = num;
    return vet;
}

void remover(conjunto *a,int num){
    int count = 0;
    for(int i = 0;i < a->tamanho;i++){
        if(num == a->numeros[i]){
            for(int j = i;j > a->tamanho;j++){
               a->numeros[j] = a->numeros[j+1]; 
            }
        }else
            count++;
    }
    if(count == a->tamanho){
        printf("Numero nao exite no conjunto!\n");
    }else
        a->tamanho--;
}

conjunto *uniao(conjunto *a,conjunto *b){
    conjunto *conj_uniao;
    int *vet_uniao;
    int tamanho = a->tamanho+b->tamanho;
    vet_uniao = (int *) malloc(tamanho*sizeof(int));
    int i = 0,j = 0;
    while(i < a->tamanho){
        vet_uniao[i] = a->numeros[i];
        i++;
    }
    while(i < tamanho){
        vet_uniao[i] = b->numeros[j];
        i++;
        j++;
    }
    conj_uniao = cria(vet_uniao,tamanho,'U');
    return conj_uniao;
}

conjunto *intersecao(conjunto *a,conjunto *b){
    conjunto *conj_inter;
    int *vet_inter;
    int count = 0,i,j;
    for(i = 0; i < a->tamanho;i++){
        for(j = i; j < b->tamanho;j++){
            if(a->numeros[i] == b->numeros[j]){
                count++;
            }
        }
    }
    if(count == 0){
        return NULL;
    }else{
        vet_inter = (int *) malloc(count*sizeof(int));
        int l = 0;
        for(i = 0; i < a->tamanho;i++){
            for(j = i; j < b->tamanho;j++){
                if(a->numeros[i] == b->numeros[j]){
                   vet_inter[l] = a->numeros[i];
                   l++;
                }
            }
        }
        cria(vet_inter,count,'I');
        return conj_inter;
    }
}

conjunto *diferenca(conjunto *a,conjunto *b){
    int *vet_dif;
    conjunto *conj_dif;
    int count,i,j;
    int tamanho = 0;
    vet_dif = (int *) malloc(sizeof(int));
    for(i = 0;i < a->tamanho;i++){
        count = 0;
        for(j = 0; j < b->tamanho;j++){
            if(a->numeros[i] != b->numeros[j]){
                count++;
            }
        }
        if(count == b->tamanho){
            vet_dif[tamanho] = a->numeros[i];
            tamanho++;
            vet_dif = (int *) realloc(vet_dif,(tamanho+1)*sizeof(int));
        }
    }
    if(tamanho == 0){
        return NULL;
    }else{
        conj_dif = cria(vet_dif,tamanho,'D');
        return conj_dif;
    }
}

int main(){
    int opcao,i,tamanho,count = 0,num,teste = 0;
    char letra;
    conjunto *a,*b,*c;
    int *vet;
    do{
        printf("        ----- CONJUNTOS -----\n");
        printf("\t1 - Cria conjunto\n");
        printf("\t2 - Verificar membro\n");
        printf("\t3 - Inserir numero\n");
        printf("\t4 - remover numero\n");
        printf("\t5 - Conjunto Uniao \n");
        printf("\t6 - Conjunto Intersecao\n");
        printf("\t7 - Conjunto Diferenca\n");
        printf("\t8 - Sair\n");
        printf("Digite a opcao:");
        setbuf(stdin,NULL);
        scanf("%d",&opcao);
        if(opcao == 1){//cria conjunto
            printf("Digite o tamanho do conjunto:");
            setbuf(stdin,NULL);
            scanf("%d",&tamanho);
            if(count == 0){
                printf("Conjunto A:\n");
            }
            if(count == 1){
                printf("Conjunto B:\n");
            }
            printf("Digite os valores:\n");
            for(i = 0;i < tamanho;i++){
                printf("Numero %d:",i+1);
                setbuf(stdin,NULL);
                scanf("%d",&vet[i]);
            }
            if(count == 1){
                b = cria(vet,tamanho,'B');
                count--;
            }
            else{
                a = cria(vet,tamanho,'A');
                count++;
            }
            opcao = 0;
        }
        if(opcao == 2){//verificar membro
            printf("Digite o numero:");
            setbuf(stdin,NULL);
            scanf("%d",&num);
            printf("Digite a letra do conjunto:");
            setbuf(stdin,NULL);
            scanf("%c",&letra);
            if(letra == 'A'){
                membro(a,num);
            }
            if(letra == 'B'){
                membro(b,num);
            }
            if(teste == 1){
                if(letra == 'D'){
                    membro(c,num);
                }
                if(letra == 'I'){
                    membro(c,num);
                }
                if(letra == 'U'){
                    membro(c,num);
                }
            }else{
                printf("Conjunto nao existente!\n");
            }
            opcao = 0;
        }
        if(opcao == 3){//inserir
            printf("Digite um numeros:");
            scanf("%d",&num);
            printf("Escolha o conjunto:\n1 - A\n2- B\n");
            scanf("%d",&opcao);
            if(opcao == 1){
                a->numeros = insere(a,num);
                opcao = 0;
            }
            if(opcao == 2){
                b->numeros = insere(b,num);
                opcao = 0;
            }else{
                printf("Opcao invalida!\n");
            }
        }
        if(opcao == 4){//remover
            printf("Digite um numeros:");
            scanf("%d",&num);
            printf("Escolha o conjunto:\n1 - A\n2- B\n");
            scanf("%d",&opcao);
            if(opcao == 1){
                remover(a,num);
                opcao = 0;
            }
            if(opcao == 2){
                remover(b,num);
                opcao = 0;
            }else{
                printf("Opcao invalida!\n");
            }
        }
        if(opcao == 5){//conjunto uniao;
            c = uniao(a,b);
            printf("Conjunto Uniao de A e B:\n");
            for(i = 0;i < c->tamanho;i++){
                printf("%c ",c->numeros[i]);
            }
            teste = 1;
            opcao = 0;
        }
        if(opcao == 6){//conjunto intersecao
            c = intersecao(a,b);
            printf("Conjunto Intersecao de A e B:\n");
            for(i = 0;i < c->tamanho;i++){
                printf("%c ",c->numeros[i]);
            }
            teste = 1;
            opcao = 0;
        }
        if(opcao == 7){//conjunto diferenca
            c = diferenca(a,b);
            printf("Conjunto Diferenca de A e B:\n");
            for(i = 0;i < c->tamanho;i++){
                printf("%c ",c->numeros[i]);
            }
            teste = 1;
            opcao = 0;
        }
        if(opcao == 8){//sair
            break;
        }
    }while(opcao < 1 || opcao > 8);
    free(a);
    free(b);
    free(c);
    return 0;
}