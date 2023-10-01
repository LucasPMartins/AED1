#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota[3];
    float media;
    float nota_exame;
    int i;
    printf("Digite as tres notas do aluno:\n\n");
    for(i = 0; i < 3; i++){
        printf("Digite a nota %d:",i+1);
        scanf("%f",&nota[i]);
    }
    media = (nota[0] + nota[1] + nota[2])/3;
    printf("\n\nMedia do aluno %.2f\n\n",media);
    if(media >= 0 && media <= 3){
        printf("Aluno reprovado!");
    }else if(media > 3 && media < 7){
        printf("Aluno deve fazer exame final!\n");
        nota_exame = 12 - media;
        printf("Para que o aluno seja aprovado com media igual 6.0\neh necessario que o proprio atinja %.2f de nota no exame final\n",nota_exame);
    }else if(media >= 7 && media <= 10){
        printf("Aluno aprovado!");
    }
    return 0;
}
