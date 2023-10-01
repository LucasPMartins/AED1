#define MAX 100

typedef struct aluno
{
    int mat;
    char nome[30];
    float n1;
} Aluno;

typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it);
int inserirFim(Lista *l, Aluno it);
int inserirPosicao(Lista *l, Aluno it, int pos);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l, int pos);
int removerItem(Lista *l, Aluno it);

int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao(Lista *l,int posicao, int *retorno);

int listaVazia(Lista *l);
int listaCheia(Lista *l);

int tamanho(Lista *l);
void mostrar(Lista *l);

void maior_nota(Lista *l);

int inserirmatricula(Lista *l,Aluno it);

int troca(Lista *l,int pos1,int pos2);

int aluno_rep(Lista *l1,Lista *l2,Aluno it);