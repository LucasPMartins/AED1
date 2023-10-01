#include <stdio.h>
#include <stdlib.h>

int soma(int num){
    int i;
    int somar;
    for(i = 1;i <= num;i++){
        somar += i;
    }
    return somar;
}

int main(){

    int n,result;
    printf("Digite um numero:");
    scanf("%d",&n);
    result = soma(n);
    printf("Soma dos numeros = %d",result);
    return 0;
}
