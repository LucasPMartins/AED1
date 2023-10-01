#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char titulo[20];
    int ano;
    int numeros_pag;
    float preco;
}livro;

int main()
{
    livro vet[5];
    int j,i,media;
    printf("Digite os dados dos 5 livro:\n\n");
    for(i = 0;i < 5;i++){
        printf("Digite o titulo do livro:");
        setbuf(stdin,NULL);
        fgets(vet[i].titulo,20,stdin);
        for(j = 0;vet[i].titulo[j] != '\0';j++){
            if(vet[i].titulo[j] == '\n'){
                vet[i].titulo[j] = '\0';
                break;
            }
        }
        printf("Digite o ano de edicao do %s:",vet[i].titulo);
        setbuf(stdin,NULL);
        scanf("%d",&vet[i].ano);
        printf("Digite o numero de paginas:");
        setbuf(stdin,NULL);
        scanf("%d",&vet[i].numeros_pag);
        printf("Digite o preco:");
        setbuf(stdin,NULL);
        scanf("%f",&vet[i].preco);
    }
    for(i = 0;i < 5;i++){
        media += vet[i].numeros_pag;
    }
    media = media/5;
    printf("A media do numero de paginas do livro eh : %d\n",media);
    return 0;
}
