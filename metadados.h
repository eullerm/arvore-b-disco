#ifndef METADADOS_H
#define METADADOS_H

#include <stdio.h>

typedef struct Metadados {
	int d; //ordem da arvore
	int pont_raiz;
	int pont_prox_no_livre;
} TMetadados;

// Imprime metadados
void imprime_metadados(TMetadados *metadados);

// Cria metadados. Lembrar de usar free(metadados)
TMetadados *metadados(int d, int pont_raiz, int pont_prox_no_livre);

// Salva metadados no arquivo out, na posicao atual do cursor
void salva_metadados(TMetadados *metadados, FILE *out);

// Salva metadados no arquivo nome_arquivo
void salva_arq_metadados(char *nome_arquivo, TMetadados *metadados);

// Le um metadados do arquivo in na posicao atual do cursor
// Retorna um ponteiro para metadados lido do arquivo
TMetadados *le_metadados(FILE *in);

// Le metadados do arquivo nome_arquivo
TMetadados *le_arq_metadados(char *nome_arquivo);

// Compara dois metadados
// Retorna 1 se os valores dos atributos de ambos forem iguais
// e 0 caso contrario
int cmp_metadados(int d, TMetadados *c1, TMetadados *c2);

// Retorna tamanho do metadados em bytes
int tamanho_metadados();

#endif