#include <stdio.h>
#include <stdlib.h>

typedef struct letras{
    int repeticao;
    char letra;
};

void texto(char *text,char *word,int *rep){
    struct letras *c;
    int existe;
    int i,j,count,k = 0;
    c = (struct letras *) malloc(127*sizeof(struct letras));
    for(i = 0;text[i] != '\0';i++){
        count = 1;
        for(j = i+1;text[j] != '\0';j++){
            if(text[i] == text[j]){
                count++;
            }
        }
        existe = 0;
        for(j = 0; j < k;j++){
            if(text[i] == c[j].letra){
                existe = 1;
            }
        }
        if(existe == 0){
            c[k].letra = text[i];
            c[k].repeticao = count;
            k++;
        }
    }
    rep = (int *) realloc(rep,(k)*sizeof(int));
    word = (char *) realloc(word,(k)*sizeof(char));
    for(i = 0;i < k;i++){
        word[i] = c[i].letra;
        rep[i] = c[i].repeticao;
    }
    word[k] = '\0';
}

int main()
{
    char *text;
    int *rep;
    char *word;
    int i,count = 0;
    printf("Digite um texto com ate 400 caracteres:");
    text = (char *) malloc(400*sizeof(char));
    fgets(text,400,stdin);
    for(i = 0;text[i] != '\0';i++){
        count++;
    }
    word = (char *) malloc(count*sizeof(char));
    rep = (int *) malloc(127*sizeof(int));
    texto(text,word,rep);
    printf("\nCaracteres presentes no texto e suas repeticoes:\n\n");
    for(i = 0;word[i] != '\0' && word[i] != '\n';i++){
        printf("Caracter:%c ",word[i]);
        printf("\tRepeticoes:%d\n",rep[i]);
    }
    free(text);
    free(rep);
    free(word);
    return 0;
}
