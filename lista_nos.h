#ifndef LISTA_NOS_H
#define LISTA_NOS_H

#include "no.h"

/***
 * ESSE ARQUIVO EH USADO APENAS NOS TESTES AUTOMATIZADOS
 */

typedef struct ListaNos {
	TNo **lista;
	int qtd;
} TListaNos;

// Imprime nohs
void imprime_nos(int d, TListaNos *lc);

// Cria lista de nohs. Lembrar de usar libera_nos(lista_nos)
TListaNos *cria_nos(int d, int qtd, ...);

// Salva lista de nohs no arquivo nome_arquivo
void salva_nos(int d, char *nome_arquivo, TListaNos *lc);

// Le lista de nohs do arquivo nome_arquivo
TListaNos *le_nos(int d, char *nome_arquivo);

// Compara duas listas de nohs
// Retorna 1 se os nohs das duas listas forem iguais
// e 0 caso contrario
int cmp_nos(int d, TListaNos *n1, TListaNos *n2);

// Desaloca lista de nohs
void libera_nos(int d, TListaNos *lc);

#endif