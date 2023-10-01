#include <stdio.h>
#include <stdlib.h>

//Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual,calcule e mostre a idade desta pessoa,equantos anos essa pessoa terá em 2030.

int main(){

    int ano_nasc,ano_atual,idade;

    printf("Digite o seu ano de nascimento:");
    scanf("%d",&ano_nasc);
    printf("Digite o ano atual:");
    scanf("%d",&ano_atual);
    idade =  ano_atual - ano_nasc;
    printf("Sua idade eh %d\n",idade);
    idade = 2030 - ano_nasc;
    printf("Sua idade em 2030 eh %d",idade);

    return 0;
}
