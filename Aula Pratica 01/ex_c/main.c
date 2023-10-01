#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que recebe um operador aritmético
e dois operandos e calcule a operação indicada.
As operações possíveis são soma(+), subtração(-),
multiplicação(*)e divisão(/).*/

int main()
{
    char op;
    float num1,num2;
    float resultado;
    printf("Digite um operador aritmetico: (+,-,*,/)\n");
    scanf("%c",&op);
    printf("Digite um numero:");
    setbuf(stdin,NULL);
    scanf("%f",&num1);
    printf("Digite outro numero:");
    scanf("%f",&num2);
    switch (op){
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado =  num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                printf("Impossivel realizar operacao!");
                return 0;
            }
            resultado = num1 / num2;
            break;
        default:
            printf("Operador aritmetico desconhecido!");
            return 0;
    }
    printf("O resultado da operacao eh: %.2f",resultado);
    return 0;
}
