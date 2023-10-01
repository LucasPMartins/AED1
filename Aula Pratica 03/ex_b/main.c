#include <stdio.h>
#include <stdlib.h>

float elevado(int x,int y){
    int temp = x;
    int verifica;
    float tempx;
    if(y == 1){
        return x*1.00;
    }
    if(y == 0){
        return 1;
    }
    if(y < 0){
        verifica = y;
        while(y != 0){
            if(y == verifica){
                x = x*temp;
                y = y+2;
            }
            else{
                x = x*temp;
                y++;
            }
        }
        tempx = 1/x;
        return tempx;
    }
    if(y > 0){
        verifica = y;
        while(y != 0){
            if(y == verifica){
                x = x*temp;
                y = y-2;
            }
            else{
                x = x*temp;
                y--;
            }
        }
        return x*1.00;
    }
}

int main()
{
    int x,y;
    float r;
    printf("Digite um valor para X:");
    scanf("%d",&x);
    printf("Digite um valor para Y:");
    scanf("%d",&y);
    r = elevado(x,y);
    printf("O numero %d elevado a %d eh %f",x,y,r);
    return 0;
}
