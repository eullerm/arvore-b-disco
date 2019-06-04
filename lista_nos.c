#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdarg.h>

#include "lista_nos.h"


void imprime_nos(int d, TListaNos *lc)
{
	int i;
	for (i = 0; i < lc->qtd; i++) {
		imprime_no(d, lc->lista[i]);
	}
}

TListaNos *cria_nos(int d, int qtd, ...)
{
	va_list ap;
	TListaNos *lc = (TListaNos *)  malloc(sizeof(TListaNos));
	lc->qtd = qtd;
	lc->lista = (TNo **) malloc(sizeof(TNo *) * (qtd));
	int i;
	va_start(ap, qtd);
	for (i = 0; i < qtd; i++) {
        lc->lista[i] = va_arg(ap, TNo *);
    }
    va_end(ap);
    return lc;
}

void salva_nos(int d, char *nome_arquivo, TListaNos *lc)
{
	FILE *out = fopen(nome_arquivo, "wb");
	int i;
	for (i = 0; i < lc->qtd; i++) {
		salva_no(d, lc->lista[i], out);
	}
	fclose(out);
}

TListaNos * le_nos(int d, char *nome_arquivo)
{
	int qtd = 0;
	TListaNos *lc = (TListaNos *)  malloc(sizeof(TListaNos));
	FILE *in = fopen(nome_arquivo, "rb");
	if (in != NULL) {
		TNo *no = NULL;
		while((no = le_no(d, in)) != NULL) {
			qtd += 1;
			libera_no(d, no);
		}
		fseek(in, 0, SEEK_SET);
		lc->qtd = qtd;
		lc->lista = (TNo **) malloc(sizeof(TNo *) * (qtd));
		qtd = 0;
		while((no = le_no(d, in)) != NULL) {
			lc->lista[qtd++] = no;
		}
		fclose(in);
	} else {
		lc->qtd = 0;
		lc->lista = NULL;
	}
	return lc;
}

int cmp_nos(int d, TListaNos *n1, TListaNos *n2)
{
	if (n1->qtd != n2->qtd) {
		return 0;
	}
	int i;
	for (i = 0; i < n1->qtd; i++) {
		if (!cmp_no(d, n1->lista[i], n2->lista[i])) {
			return 0;
		}
	}
	return 1;
}

void libera_nos(int d, TListaNos *lc)
{
	int i;
	for (i = 0; i < lc->qtd; i++) {
		libera_no(d, lc->lista[i]);
	}
	free(lc->lista);
	free(lc);
}
