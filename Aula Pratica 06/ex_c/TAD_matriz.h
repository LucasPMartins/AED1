
typedef struct matriz Matriz;

Matriz criarMatriz(int linhas, int colunas);
void destruirMatriz(Matriz *matriz);
void atribuirElemento(Matriz *matriz, int linha, int coluna, float valor);
float acessarElemento(Matriz matriz, int linha, int coluna);
int numeroDeLinhas(Matriz matriz);
int numeroDeColunas(Matriz matriz);
void preencherComAleatorios(Matriz *matriz, float min, float max);
Matriz somarMatrizes(Matriz matriz1, Matriz matriz2);
void exibirMatriz(Matriz matriz);