typedef struct caracter{
    char c;
    int count;
}caracter;

typedef struct lista Lista;

int tamanho(Lista *l);

int ocorrencias(Lista *l);

Lista *criar();

int listavazia(Lista *l);

void mostrar(Lista *l);

void liberar(Lista *l);
