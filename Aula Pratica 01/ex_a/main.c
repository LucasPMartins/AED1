#include<stdio.h>

int main(){
    int i,acc,n;
    printf("Entre com o valor:");
    scanf("%d",&n);
    for(i=n-1,acc=n;i>0;i--)
        acc=acc*i;
    printf("O valor do fatorial de %d eh %d",n,acc);
    return 0;
}
