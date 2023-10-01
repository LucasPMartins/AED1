#include <stdio.h>
#include <stdlib.h>

int potencia(int x,int y){
    int temp = x;
    if(y == 1){
        return x;
    }
    for(int i = 1;i < y;i++){
        x = x*temp;
    }
    return x;
}
int fatorial(int x){
    if( x == 1){
        return 1;
    }
    for(int i = x-1;i != 1;i--){
        x = x*i;
    }
    return x;
}

int main()
{
    int n = 10,i,e = 1,x;
    printf("Digite um numero para euler elevado a x:");
    scanf("%d",&x);
    for(i = 1;i <= n;i++){
        e += potencia(x,i)/ fatorial(i);
    }
    printf("A serie de Taylor de %d eh: %d",x,e);
    return 0;
}
