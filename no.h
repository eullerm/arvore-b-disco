#ifndef NO_H
#define NO_H

#include <stdio.h>

#include "cliente.h"

typedef struct No {
	int m;
	int pont_pai;
	int *p;
	TCliente **clientes;
} TNo;

// Imprime noh
void imprime_no(int d, TNo *no);

// Cria noh. Lembrar de usar libera_no(no)
TNo *no(int d, int m, int pont_pai);

// Cria noh folha vazio. Lembrar de usar libera_no(no)
TNo *no_vazio(int d);

// Cria noh com dados. Lembrar de usar libera_no(no)
// Size deve ser 2m + 1
TNo *cria_no(int d, int m, int pont_pai, int size, ...);

// Grava uma pagina (noh) no arquivo em disco
void salva_no(int d, TNo *no, FILE *out);

// Le uma pagina (noh) do disco
TNo *le_no(int d, FILE *in);

// Compara dois nohs
// Retorna 1 se os valores dos atributos de ambos forem iguais
// e 0 caso contrario
int cmp_no(int d, TNo *n1, TNo *n2);

// Retorna tamanho do noh em bytes
int tamanho_no(int d);

// Libera noh e clientes
void libera_no(int d, TNo *no);

#endif