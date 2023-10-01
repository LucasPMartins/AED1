 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringfun(char *str,char c,int tamanho){
    int ocorrencias = 0;
    for(int i = 0; i < tamanho;i++){
        if(str[i] == c){
            str[i] = '*';
            ocorrencias++;
        }
    }
    return ocorrencias;
}

int main()
{
    char caractere;
    int tamanhostr,r;
    char *string;
    string = (char *) malloc(30*sizeof(char));
    printf("Digite a string:");
    setbuf(stdin,NULL);
    fgets(string,30,stdin);
    tamanhostr = strlen(string);
    printf("Digite um caractere:");
    setbuf(stdin,NULL);
    scanf("%c",&caractere);
    r = stringfun(string,caractere,tamanhostr);
    printf("Nova string: %s",string);
    printf("Quantidade de substitucoes: %d",r);
    return 0;
}
