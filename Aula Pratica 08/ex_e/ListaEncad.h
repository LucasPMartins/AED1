typedef struct Rota {
    char origem[4];
    char destino[4];
    float preco;
    struct Rota *proximo;
} Rota;

typedef struct Aeroporto {
    char nome[50];
    char sigla[4];
    struct Rota *inicio;
    struct Aeroporto *proximo;
} Aeroporto;

typedef struct Lista{
    Aeroporto *inicio;
}Lista;

Lista *criar();

int insere_Aeroporto(Lista *l,char *nome,char *sigla);

int insere_Rota(Lista *l,char *nome_cidade,char *origem,char *destino, float preco);

int listaVazia(Lista *l);

void formata_nome(char *nome);

int mais_barata(Lista *l,char *nome_cidade,Rota *retorno);

int mais_cara(Lista *l,char *nome_cidade,Rota *retorno);

void consulta(Lista *l,char *origem,char *destino);

void mostrar(Lista *l);