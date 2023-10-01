#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    float **dados; 
    int linhas;    
    int colunas;  
} Matriz;

Matriz criarMatriz(int linhas, int colunas) {
    Matriz novaMatriz;
    novaMatriz.linhas = linhas;
    novaMatriz.colunas = colunas;
    novaMatriz.dados = (float **)malloc(linhas * sizeof(float *));
    if (novaMatriz.dados == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    for (int i = 0; i < linhas; i++) {
        novaMatriz.dados[i] = (float *)malloc(colunas * sizeof(float));
        if (novaMatriz.dados[i] == NULL) {
            printf("Erro: Falha na alocação de memória.\n");
            exit(1);
        }
    }
    return novaMatriz;
}

void destruirMatriz(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    matriz->linhas = 0;
    matriz->colunas = 0;
}

void atribuirElemento(Matriz *matriz, int linha, int coluna, float valor) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        matriz->dados[linha][coluna] = valor;
    } else {
        printf("Erro: Índices fora dos limites da matriz.\n");
    }
}

float acessarElemento(Matriz matriz, int linha, int coluna) {
    if (linha >= 0 && linha < matriz.linhas && coluna >= 0 && coluna < matriz.colunas) {
        return matriz.dados[linha][coluna];
    } else {
        printf("Erro: Índices fora dos limites da matriz.\n");
        return 0.0;
    }
}

int numeroDeLinhas(Matriz matriz) {
    return matriz.linhas;
}

int numeroDeColunas(Matriz matriz) {
    return matriz.colunas;
}

void preencherComAleatorios(Matriz *matriz, float min, float max) {
    srand(time(NULL));
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            matriz->dados[i][j] = min + ((float)rand() / RAND_MAX) * (max - min);
        }
    }
}

Matriz somarMatrizes(Matriz matriz1, Matriz matriz2) {
    if (matriz1.linhas != matriz2.linhas || matriz1.colunas != matriz2.colunas) {
        printf("Erro: As matrizes têm dimensões diferentes e não podem ser somadas.\n");
        exit(1);
    }
    Matriz resultado = criarMatriz(matriz1.linhas, matriz1.colunas);
    for (int i = 0; i < matriz1.linhas; i++) {
        for (int j = 0; j < matriz1.colunas; j++) {
            resultado.dados[i][j] = matriz1.dados[i][j] + matriz2.dados[i][j];
        }
    }
    return resultado;
}

void exibirMatriz(Matriz matriz) {
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            printf("%.2f\t", matriz.dados[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Matriz matriz1 = criarMatriz(3, 3);
    preencherComAleatorios(&matriz1, 1.0, 10.0);
    printf("Matriz 1:\n");
    exibirMatriz(matriz1);
    atribuirElemento(&matriz1, 1, 1, 99.0);
    float valor = acessarElemento(matriz1, 1, 1);
    printf("Valor na posicao (1, 1): %.2f\n", valor);
    Matriz matriz2 = criarMatriz(3, 3);
    preencherComAleatorios(&matriz2, 1.0, 10.0);
    printf("Matriz 2:\n");
    exibirMatriz(matriz2);
    Matriz matrizSoma = somarMatrizes(matriz1, matriz2);
    printf("Matriz Soma:\n");
    exibirMatriz(matrizSoma);
    destruirMatriz(&matriz1);
    destruirMatriz(&matriz2);
    destruirMatriz(&matrizSoma);
    return 0;
}
