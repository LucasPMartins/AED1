#include <stdio.h>
#include <stdlib.h>

int divisao(int a,int b,int *resto,int *quociente){
    if(b == 0){
        return -1;
    }else{
        *quociente = a/b;
        *resto = a%b;
        return 0;
    }
}

int main()
{
    int a,b,r;
    int quociente,resto;
    printf("Digite a e b:");
    scanf("%d %d",&a,&b);
    r = divisao(a,b,&resto,&quociente);
    if(r == -1){
        printf("Impossivel fazer divisao!\n");
    }
    if(r == 0){
        printf("O quociente de a e b eh %d\n",quociente);
        printf("O resto de a e b eh %d\n",resto);
    }
    return 0;
}
