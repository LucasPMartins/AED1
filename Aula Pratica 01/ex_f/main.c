#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura,base,area;
    do{
        printf("Digite a altura do triangulo:");
        scanf("%f",&altura);
        printf("Digite a base do triangulo:");
        scanf("%f",&base);
        if(base <= 0 || altura <= 0){
            printf("Medidas invalidas!Digite novamente\n\n");
        }
    }while(base <= 0 || altura <= 0);
    area = (base*altura)/2;
    printf("A area do triangulo eh %.2f",area);
    return 0;
}
