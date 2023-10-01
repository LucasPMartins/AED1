#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_string.h"

struct TAD_string 
{
    int tamanho; //tamanho da string
    char *string; // string
};

//cria uma string 
TAD_STRING criacao(char *str){
    TAD_STRING strnova;
    strnova.tamanho = strlen(str);
    strnova.string = (char *) malloc((strnova.tamanho+1)*sizeof(char)); 
    if(strnova.string == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(strnova.string,str);
    return strnova;
}

//Associação de valor para a String
void valor(TAD_STRING str,int num){
    printf("Letra na posicao %d: %c",num,str.string[num-1]);
}

//Retorno do tamanho (número de caracteres) da String
int tamanho(TAD_STRING str){
    return str.tamanho;
}

//Contagem do número de ocorrências de um caractere na String
int contagem(TAD_STRING *str,char caractere){
    int count = 0;
    for(int i = 0;i < str->tamanho;i++){
        if(str->string[i] == caractere){
            count++;
        }
    }
    return count;
}

//exibe a string
void exibe(TAD_STRING *str){
    printf("String: %s",str->string);
}

int main()
{
    TAD_STRING c;
    int num;
    char caractere;
    c = criacao("STRING bla bla bla");
    exibe(&c);
    printf("\nDigite um numero:");
    scanf("%d",&num);
    valor(c,num);
    num = tamanho(c);
    printf("\nTamanho da string: %d\n",num);
    printf("Digite um caractere:");
    setbuf(stdin,NULL);
    scanf("%c",&caractere);
    num = contagem(&c,caractere);
    printf("O %c aparece %d vezes na string\n",caractere,num);

    return 0;
}
