#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define BEFORE_TEST before();

#define NOME_ARQUIVO_DADOS "clientes.dat"
#define NOME_ARQUIVO_METADADOS "metadados.dat"
#define D 2

#include <limits.h>
#include <stdlib.h>

#include "ufftest.h"
#include "lista_clientes.h"
#include "cliente.h"
#include "lista_nos.h"
#include "no.h"
#include "metadados.h"
#include "arvore_b.h"


void before()
{
	remove(NOME_ARQUIVO_DADOS);
	remove(NOME_ARQUIVO_METADADOS);
}

// Arvore B de altura H = 1, ordem d = 2, com apenas 1 noh (raiz eh uma folha) que tem 2 registros
// Ver arquivo ArvoreTesteDOJO.pdf para o desenho da arvore
void monta_arvore_h1()
{
	TMetadados *tabMetadados = metadados(D, 0, 1*tamanho_no(D));
	salva_arq_metadados(NOME_ARQUIVO_METADADOS, tabMetadados);
	// Estrutura do No: d, m, pont_pai, 2m + 1, lista de ponteiros, lista de clientes
	// Atencao: os ponteiros sao absolutos

	TListaNos *tabDados = cria_nos(D, 1,
		cria_no(D, 2, -1, 2 * 2 + 1,
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")));
	salva_nos(D, NOME_ARQUIVO_DADOS, tabDados);
	free(tabMetadados);
	libera_nos(D, tabDados);
}

// Arvore B de altura H = 1, ordem d = 2, com apenas 1 noh (raiz eh uma folha) que tem 4 registros
// Ver arquivo ArvoreTesteDOJO.pdf para o desenho da arvore
void monta_arvore_h1_cheia()
{
	TMetadados *tabMetadados = metadados(D, 0, 1*tamanho_no(D));
	salva_arq_metadados(NOME_ARQUIVO_METADADOS, tabMetadados);
	// Estrutura do No: d, m, pont_pai, 2m + 1, lista de ponteiros, lista de clientes
	// Atencao: os ponteiros sao absolutos

	TListaNos *tabDados = cria_nos(D, 1,
		cria_no(D, 4, -1, 4 * 2 + 1,
			-1,
			-1,
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria"),
			cliente(15, "Bianca"),
			cliente(26, "Clara")
		));
	salva_nos(D, NOME_ARQUIVO_DADOS, tabDados);
	free(tabMetadados);
	libera_nos(D, tabDados);
}

// Arvore B de altura H = 2, ordem d = 2, com raiz e mais 3 folhas
// Ver arquivo ArvoreTesteDOJO.pdf para o desenho da arvore
void monta_arvore_h2()
{
	TMetadados *tabMetadados = metadados(D, 0, 4*tamanho_no(D));
	salva_arq_metadados(NOME_ARQUIVO_METADADOS, tabMetadados);
	// Estrutura do No: d, m, pont_pai, 2m + 1, lista de ponteiros, lista de clientes
	// Atencao: os ponteiros sao absolutos

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	salva_nos(D, NOME_ARQUIVO_DADOS, tabDados);
	free(tabMetadados);
	libera_nos(D, tabDados);
}

// Arvore B de altura H = 2, com raiz e mais 3 folhas, 1 delas cheia
// Ver arquivo ArvoreTesteDOJO.pdf para o desenho da arvore
void monta_arvore_h2_cheia()
{
	TMetadados *tabMetadados = metadados(D, 0, 4*tamanho_no(D));
	salva_arq_metadados(NOME_ARQUIVO_METADADOS, tabMetadados);
	// Estrutura do No: m, pont_pai, 2m + 1, lista de ponteiros, lista de clientes
	// Atencao: os ponteiros sao absolutos

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 4, 0, 4 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana"),
			cliente(21, "Deia"),
			cliente(23, "Bruno")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	salva_nos(D, NOME_ARQUIVO_DADOS, tabDados);
	free(tabMetadados);
	libera_nos(D, tabDados);
}

// Arvore B de altura H = 3, com raiz que aponta para 2 nohs internos, e mais 6 folhas
// Ver arquivo ArvoreTesteDOJO.pdf para o desenho da arvore
void monta_arvore_h3()
{
	TMetadados *tabMetadados = metadados(D, 0, 9*tamanho_no(D));
	salva_arq_metadados(NOME_ARQUIVO_METADADOS, tabMetadados);
	// Estrutura do No: m, pont_pai, 2m + 1, lista de ponteiros, lista de clientes
	// Atencao: os ponteiros sao absolutos

	TListaNos *tabDados = cria_nos(D, 9,
		cria_no(D, 1, -1, 1 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			cliente(37, "Ricardo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1 da raiz
			3 * tamanho_no(D),
			4 * tamanho_no(D),
			5 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2 da raiz
			6 * tamanho_no(D),
			7 * tamanho_no(D),
			8 * tamanho_no(D),
			cliente(40, "Joao"),
			cliente(55, "Catarina")
		),
		cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 2
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 3
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela")
		),
		cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Folha 4
			-1,
			-1,
			-1,
			cliente(38, "Adriana"),
			cliente(39, "Fabio")
		),
		cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Folha 5
			-1,
			-1,
			-1,
			cliente(43, "Larissa"),
			cliente(50, "Tatiana")
		),
		cria_no(D, 3, 2 * tamanho_no(D), 3 * 2 + 1, // Folha 6
			-1,
			-1,
			-1,
			-1,
			cliente(57, "Alice"),
			cliente(60, "JC"),
			cliente(70, "Lucas")
		)
	);
	salva_nos(D, NOME_ARQUIVO_DADOS, tabDados);
	free(tabMetadados);
	libera_nos(D, tabDados);
}

BEGIN_TESTS();

TEST("Busca 1 -- chave procurada esta na raiz. Raiz eh folha");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h1();

	pont = busca(13, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(0, pont);
}

TEST("Busca 2 -- chave procurada nao esta na arvore. Raiz eh folha");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h1();

	pont = busca(6, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(0, pont);
}

TEST("Busca 3 -- chave esta na arvore");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

	pont = busca(20, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(2 * tamanho_no(D), pont);
}

TEST("Busca 4 -- chave nao esta na arvore");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

	pont = busca(16, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(2 * tamanho_no(D), pont);
}

TEST("Busca 5 -- chave esta na arvore");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h3();

	pont = busca(50, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(7 * tamanho_no(D), pont);
}

TEST("Busca 6 -- chave nao esta na arvore");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h3();

	pont = busca(26, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(5 * tamanho_no(D), pont);
}

TEST("Busca 7 -- chave esta a esquerda");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

	pont = busca(13, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(1 * tamanho_no(D), pont);
}

TEST("Insercao 1 em arvore de altura H = 1, sem particionamento");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h1();

    pont = insere(11, "Vanessa", NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(0, pont);

	TListaNos *tabDados = cria_nos(D, 1,
		cria_no(D, 3, -1, 3 * 2 + 1,
			-1,
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(11, "Vanessa"),
			cliente(13, "Ana Maria")));
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Insercao 2 em arvore de altura H = 2, sem particionamento");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

    pont = insere(11, "Vanessa", NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(1 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(11, "Vanessa"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Insercao 3 em arvore de altura H = 2. Exige particionamento de uma pagina folha");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2_cheia();

    pont = insere(16, "Vanessa", NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(2 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 5,
		cria_no(D, 3, -1, 3 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			4 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(20, "Mariana"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			cliente(16, "Vanessa"),
			cliente(17, "Joice")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Novo Filho
			-1,
			-1,
			-1,
			cliente(21, "Deia"),
			cliente(23, "Bruno")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Insercao 4 em arvore de altura H = 2, chave de registro ja existe -- nao inserir");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

    pont = insere(13, "Vanessa", NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(-1, pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Insercao 5 em arvore de altura H = 1 cheia, que causa aumento na altura da arvore");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h1_cheia();

    pont = insere(11, "Vanessa", NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(0, pont);

	TListaNos *tabDados = cria_nos(D, 3,
		cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Antigo noh raiz
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(11, "Vanessa")),
		cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Novo noh folha
			-1,
			-1,
			-1,
			cliente(15, "Bianca"),
			cliente(26, "Clara")),
		cria_no(D, 1, -1, 1 * 2 + 1, // Novo noh raiz
			0 * tamanho_no(D),
			1 * tamanho_no(D),
			cliente(13, "Ana Maria")));
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);

	TMetadados *tabMetadados = metadados(D, 2 * tamanho_no(D), 3 * tamanho_no(D));
	TMetadados *tabMetadadosSaida = le_arq_metadados(NOME_ARQUIVO_METADADOS);
	ASSERT_EQUAL_CMP(D, tabMetadados, tabMetadadosSaida, cmp_metadados);
	free(tabMetadados);
	free(tabMetadadosSaida);
}

TEST("Exclusao 1 em arvore de altura H = 2 cheia, nao eh necessario concatenacao");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2_cheia();

    pont = exclui(20, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(2 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 2
			-1,
			-1,
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(21, "Deia"),
			cliente(23, "Bruno")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Exclusao 2 em arvore de altura H = 2, nao eh necessario concatenacao");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2_cheia();

    pont = exclui(15, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(0 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(17, "Joice"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 2 atualizado
			-1,
			-1,
			-1,
			-1,
			cliente(20, "Mariana"),
			cliente(21, "Deia"),
			cliente(23, "Bruno")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Exclusao 3 em arvore de altura H = 2, eh necessario redistribuicao");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

    pont = exclui(17, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(2 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(15, "Jose"),
			cliente(30, "Bruna")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(13, "Ana Maria")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2 atualizado
			-1,
			-1,
			-1,
			cliente(20, "Mariana"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 3 atualizado
			-1,
			-1,
			-1,
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Exclusao 4 em arvore de altura H = 2 cheia, eh necessario redistribuicao");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2_cheia();

    pont = exclui(13, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(1 * tamanho_no(D), pont);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 2, -1, 2 * 2 + 1, // No raiz atualizado
			1 * tamanho_no(D),
			2 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(17, "Joice"),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 1 atualizado
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(15, "Jose")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 2 atualizado
			-1,
			-1,
			-1,
			-1,
			cliente(20, "Mariana"),
			cliente(21, "Deia"),
			cliente(23, "Bruno")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);

	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

TEST("Exclusao 5 em arvore de altura H = 2 cheia, eh necessario concatenacao");
if (!skip) {
	int pont = INT_MAX;
	monta_arvore_h2();

    pont = exclui(13, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
	ASSERT_EQUAL(1 * tamanho_no(D), pont);

	//Proximo no livre agora deveria apontar para o no que foi excluido pela concatenacao
	//para evitar que o arquivo fique cheio de buracos com o passar do tempo

	TMetadados *tabMetadados = metadados(D, 0, 2 * tamanho_no(D));
	TMetadados *tabMetadadosSaida = le_arq_metadados(NOME_ARQUIVO_METADADOS);
	ASSERT_EQUAL_CMP(D, tabMetadados, tabMetadadosSaida, cmp_metadados);
	free(tabMetadados);
	free(tabMetadadosSaida);

	TListaNos *tabDados = cria_nos(D, 4,
		cria_no(D, 1, -1, 1 * 2 + 1, // No raiz atualizado
			1 * tamanho_no(D),
			3 * tamanho_no(D),
			cliente(25, "Ronaldo")
		),
		cria_no(D, 4, 0, 4 * 2 + 1, // Filho 1 atualizado
			-1,
			-1,
			-1,
			-1,
			-1,
			cliente(10, "Joao"),
			cliente(15, "Jose"),
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2 agora eh lixo.
			-1,              // Ficou como estava originalmente, mas nao ha ninguem apontando para ele
			-1,
			-1,
			cliente(17, "Joice"),
			cliente(20, "Mariana")
		),
		cria_no(D, 3, 0, 3 * 2 + 1, // Filho 3 nao sofreu modificacoes
			-1,
			-1,
			-1,
			-1,
			cliente(30, "Bruna"),
			cliente(35, "Marcela"),
			cliente(37, "Leonardo")
		)
	);
	TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);
	ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
	libera_nos(D, tabDados);
	libera_nos(D, tabDadosSaida);
}

	TEST("Exclusao 6 em arvore de altura H = 3, eh necessario concatenacao, e ha propagacao");
	if (!skip) {
		int pont = INT_MAX;
		monta_arvore_h3();

		pont = exclui(10, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);
		ASSERT_EQUAL(3 * tamanho_no(D), pont);

		//Proximo no livre agora deveria apontar para o no que foi excluido pela concatenacao
		//para evitar que o arquivo fique cheio de buracos com o passar do tempo
		//Como ha propagacao, a ultima operacao é a exclusao do noh raiz, e eh ele
		//que vai ficar gravado como proximo no livre
		//a nova raiz da arvore é 1 * t

		TMetadados *tabMetadados = metadados(D, 1 * tamanho_no(D), 0);
		TMetadados *tabMetadadosSaida = le_arq_metadados(NOME_ARQUIVO_METADADOS);
		ASSERT_EQUAL_CMP(D, tabMetadados, tabMetadadosSaida, cmp_metadados);
		free(tabMetadados);
		free(tabMetadadosSaida);

		TListaNos *tabDados = cria_nos(D, 9,
									   cria_no(D, 1, -1, 1 * 2 + 1, // No raiz ficou como lixo -- nao tem mais ninguem apontando para esse noh
											   1 * tamanho_no(D),
											   2 * tamanho_no(D),
											   cliente(37, "Ricardo")
									   ),
									   cria_no(D, 4, -1, 2 * 4 + 1, // essa eh a nova raiz da arvore
											   3 * tamanho_no(D),
											   5 * tamanho_no(D),
											   6 * tamanho_no(D),
											   7 * tamanho_no(D),
											   8 * tamanho_no(D),

											   cliente(25, "Ronaldo"),
											   cliente(37, "Ricardo"),
											   cliente(40, "Joao"),
											   cliente(55, "Catarina")
									   ),
									   cria_no(D, 2, 0, 2 * 2 + 1, // Filho 2 da raiz ficou como lixo -- nao tem mais ninguem apontando para esse noh
											   6 * tamanho_no(D),
											   7 * tamanho_no(D),
											   8 * tamanho_no(D),
											   cliente(40, "Joao"),
											   cliente(55, "Catarina")
									   ),
									   cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 1
											   -1,
											   -1,
											   -1,
											   cliente(13, "Ana Maria"),
											   cliente(15, "Jose"),
											   cliente(17, "Joice"),
											   cliente(20, "Mariana")
									   ),
									   cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 2 ficou como lixo -- nao tem mais ninguem apontando para esse noh
											   -1,
											   -1,
											   -1,
											   cliente(17, "Joice"),
											   cliente(20, "Mariana")
									   ),
									   cria_no(D, 2, 1 * tamanho_no(D), 2 * 2 + 1, // Folha 3
											   -1,
											   -1,
											   -1,
											   cliente(30, "Bruna"),
											   cliente(35, "Marcela")
									   ),
									   cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Folha 4
											   -1,
											   -1,
											   -1,
											   cliente(38, "Adriana"),
											   cliente(39, "Fabio")
									   ),
									   cria_no(D, 2, 2 * tamanho_no(D), 2 * 2 + 1, // Folha 5
											   -1,
											   -1,
											   -1,
											   cliente(43, "Larissa"),
											   cliente(50, "Tatiana")
									   ),
									   cria_no(D, 3, 2 * tamanho_no(D), 3 * 2 + 1, // Folha 6
											   -1,
											   -1,
											   -1,
											   -1,
											   cliente(57, "Alice"),
											   cliente(60, "JC"),
											   cliente(70, "Lucas")
									   )
		);
		TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);
		ASSERT_EQUAL_CMP(D, tabDados, tabDadosSaida, cmp_nos);
		libera_nos(D, tabDados);
		libera_nos(D, tabDadosSaida);
	}


END_TESTS();