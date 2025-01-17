#ifndef ARVORE_B_H
#define ARVORE_B_H

// Executa busca em Arquivos utilizando Arvore B
// Assumir que ponteiro para proximo noh eh igual a -1 quando nao houver proximo noh
// cod_cli: chave do cliente que esta sendo buscado
// nome_arquivo_metadados: nome do arquivo que contem os metadados
// nome_arquivo_dados: nome do arquivo que contem a arvore B
// d: ordem da arvore
// Retorna endereço do nó onde a chave está ou deveria estar
int busca(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d);

// Executa insercao em Arquivos Indexados por Arvore B
// cod_cli: chave do cliente que esta sendo inserido
// nome_cli: nome do cliente a ser inserido
// nome_arquivo_metadados: nome do arquivo que contem os metadados
// nome_arquivo_dados: nome do arquivo que contem a arvore B
// d: ordem da arvore
// Retorna o endereco onde o cliente foi inserido, ou -1 se nao conseguiu inserir
int insere(int cod_cli, char *nome_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d);

// Executa exclusao em Arquivos Indexados por Arvores B
// cod_cli: chave do cliente a ser excluido
// nome_arquivo_metadados: nome do arquivo que contem os metadados
// nome_arquivo_dados: nome do arquivo que contem a arvore B
// d: ordem da arvore
// Retorna o endereco do cliente que foi excluido, ou -1 se cliente nao existe
int exclui(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d);

#endif