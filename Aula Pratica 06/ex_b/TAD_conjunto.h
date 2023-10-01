
typedef struct Conjuntos_inteiros conjunto;

conjunto *cria(int *vetor,int tamanho,char c);
void membro(conjunto *a,int num);
int *insere(conjunto *a,int num);
void remover(conjunto *a,int num);
conjunto *uniao(conjunto *a,conjunto *b);
conjunto *intersecao(conjunto *a,conjunto *b);
conjunto *diferenca(conjunto *a,conjunto *b);
