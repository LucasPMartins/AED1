#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia;
    char mes[20];
    int ano;
};

int datafun(struct data a){
    int nummes;
    if(strcmp(a.mes,"Janeiro") == 0){
        nummes = 1;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Fevereiro") == 0){
        nummes = 2;
        if(a.dia > 28 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Marco") == 0){
        nummes = 3;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Abril ") == 0){
        nummes = 4;
        if(a.dia > 30 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Maio") == 0){
        nummes = 5;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Junho ") == 0){
        nummes = 6;
        if(a.dia > 30 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Julho") == 0){
        nummes = 7;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Agosto") == 0){
        nummes = 8;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Setembro") == 0){
        nummes = 9;
        if(a.dia > 30 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Outubro") == 0){
        nummes = 10;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Novembro") == 0){
        nummes = 11;
        if(a.dia > 30 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else
    if(strcmp(a.mes,"Dezembro") == 0){
        nummes = 12;
        if(a.dia > 31 || a.dia < 1){
            printf("Dia invalido");
            return 0;
        }
    }else{
        printf("Mes invalido");
        return 0;
    }
    printf("Data: %d/%d/%d",a.dia,nummes,a.ano);
}

int main()
{
    struct data c;
    printf("Digite uma data:\n");
    printf("Dia:");
    scanf("%d",&c.dia);
    printf("Digite o mes:");
    setbuf(stdin,NULL);
    fgets(c.mes,20,stdin);
    for(int i = 0;c.mes[i] != '\0';i++){
        if(c.mes[i] == '\n')
            c.mes[i] = '\0';
    }
    printf("Ano:");
    setbuf(stdin,NULL);
    scanf("%d",&c.ano);
    datafun(c);
    return 0;
}
