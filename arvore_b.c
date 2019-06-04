#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdio.h>

#include "arvore_b.h"
#include "metadados.h"
#include "no.h"


void insereNo(TNo *no, int cod_cli, TCliente *cli, TNo *novo){

    novo->pont_pai = no->pont_pai;

    //Guarda todos clientes de forma ordenada no nó
    int j=0;
    while (j < no->m && cod_cli > no->clientes[j]->cod_cliente) {
        novo->clientes[j] = no->clientes[j];
        j++;
    }

    novo->clientes[j] = cli;
    novo->m = no->m+1;

    while(j+1 < no->m+1) {
        novo->clientes[j+1] = no->clientes[j];
        j++;
    }
    //------------------------------------------------------//

}

void insereNoPai(){

}


int busca(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d)
{
    FILE *arq_Dados = fopen(nome_arquivo_dados, "rb");

    TMetadados *metadados = le_arq_metadados(nome_arquivo_metadados);

    fseek(arq_Dados, metadados->pont_raiz, SEEK_SET);
    //posição do no.
    int pos = 0;
    TNo *no = le_no(d, arq_Dados);
    int i;
    while(no) {
        for (i = 0 ; i < no->m; i++) {
            if(cod_cli <= no->clientes[i]->cod_cliente) break;
        }

        if(i == no->m) i--;
        if (cod_cli > no->clientes[i]->cod_cliente){
            if(no->p[i+1] == -1){
                return pos;
            }else {
                fseek(arq_Dados, no->p[i + 1], SEEK_SET);
                pos = no->p[i+1];
            }
        }else if (cod_cli < no->clientes[i]->cod_cliente) {
            if (no->p[i] == -1) {
                return pos;
            }
            else{
                fseek(arq_Dados, no->p[i], SEEK_SET);
                pos = no->p[i];
            }

        }else return pos;

        no = le_no(d, arq_Dados);
    }
}

int insere(int cod_cli, char *nome_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d)
{

    FILE *arq_Dados = fopen(nome_arquivo_dados, "rb+");

    TCliente *cli = cliente(cod_cli, nome_cli);

    int pos = busca(cod_cli, nome_arquivo_metadados, nome_arquivo_dados, d);

    TMetadados *metadados = le_arq_metadados(nome_arquivo_metadados);

    fseek(arq_Dados, pos, SEEK_SET);

    TNo *no = le_no(d, arq_Dados);

    int i;
    for(i = 0; i < no->m; i++){
        if(cod_cli <= no->clientes[i]->cod_cliente) break;
    }

    if(i == no->m) i--;

    //Caso já exista o codigo
    if(cod_cli == no->clientes[i]->cod_cliente) return -1;


    else{
        //Se couber mais um cliente no no folha
        if(no->m < 2*d){

            TNo *novo = no_vazio(d);

            insereNo(no, cod_cli, cli, novo);

            fseek(arq_Dados, pos, SEEK_SET);

            salva_no(d, novo, arq_Dados);
            fclose(arq_Dados);
            return pos;

        //Caso o no folha esteja cheio.
        }else{

            TCliente *guardaCli[(2*d)+1];
            int j = 0;
            //Guarda todos os clientes em um vetor
            while (j < no->m && cod_cli > no->clientes[j]->cod_cliente) {
                guardaCli[j] = no->clientes[j];
                j++;
            }

            guardaCli[j]= cli;

            while(j+1 < no->m+1) {
                guardaCli[j+1] = no->clientes[j];
                j++;
            }
            //-------------------------------------------------------------------//

            //Se não for um no pai
            if(no->pont_pai!=-1) {
                fseek(arq_Dados, no->pont_pai, SEEK_SET);
                TNo *noPai = le_no(d, arq_Dados);


                int meio;
                if (j % 2 == 0) meio = j / 2;
                else meio = j / 2 + 1;

                TNo *novo = no_vazio(d);
                novo->pont_pai = no->pont_pai;
                TNo *novo2 = no_vazio(d);
                novo2->pont_pai = no->pont_pai;

                //Se couber no nó pai
                if (noPai->m < 2 * d) {
                    TNo *novoPai = no_vazio(d);
                    novoPai->pont_pai = noPai->pont_pai;

                    int k = 0;
                    novoPai->p[k] = noPai->p[k];
                    while (k < no->m && guardaCli[meio]->cod_cliente > noPai->clientes[k]->cod_cliente) {
                        novoPai->clientes[k] = noPai->clientes[k];
                        novoPai->p[k + 1] = noPai->p[k + 1];
                        k++;
                    }

                    novoPai->clientes[k] = guardaCli[meio];
                    novoPai->m = noPai->m + 1;
                    novoPai->p[k + 1] = metadados->pont_prox_no_livre;

                    while (k + 1 < noPai->m + 1) {
                        novoPai->clientes[k + 1] = noPai->clientes[k];
                        novoPai->p[k + 2] = noPai->p[k + 1];
                        k++;
                    }

                    fseek(arq_Dados, pos, SEEK_SET);

                    int k1;
                    int k2 = 0;
                    for (k1 = 0; k1 < no->m + 1; k1++) {
                        if (k1 < meio) {
                            novo->clientes[k1] = guardaCli[k1];
                            novo->m++;
                        } else if (k1 > meio) {
                            novo2->clientes[k2] = guardaCli[k1];
                            novo2->m++;
                            k2++;
                        }
                    }


                    fseek(arq_Dados, pos, SEEK_SET);
                    salva_no(d, novo, arq_Dados);
                    fseek(arq_Dados, metadados->pont_prox_no_livre, SEEK_SET);
                    salva_no(d, novo2, arq_Dados);
                    //imprime_no(d, novo2);
                    fseek(arq_Dados, no->pont_pai, SEEK_SET);
                    salva_no(d, novoPai, arq_Dados);
                    metadados->pont_prox_no_livre = fseek(arq_Dados, 0, SEEK_END);
                    //pos = busca(cod_cli, nome_arquivo_metadados, nome_arquivo_dados, d);

                    /*rewind(arq_Dados);
                    no = le_no(d, arq_Dados);
                    while (no) {
                        imprime_no(d, no);
                        no = le_no(d, arq_Dados);
                    }*/

                    fclose(arq_Dados);
                    salva_arq_metadados(nome_arquivo_metadados, metadados);
                    return pos;

                //Caso nao caiba no nó pai
                } else {

                }
            //Caso não haja um nó pai
            }else{
                TNo *novoPai = no_vazio(d);
                int meio;
                if (j % 2 == 0) meio = j / 2;
                else meio = j / 2 + 1;

                novoPai->clientes[0] = guardaCli[meio];
                novoPai->m = 1;

                //Guarda nos novos nós
                TNo *novo = no_vazio(d);
                TNo *novo2 = no_vazio(d);
                int k1;
                int k2 = 0;
                for (k1 = 0; k1 < no->m + 1; k1++) {
                    if (k1 < meio) {
                        novo->clientes[k1] = guardaCli[k1];
                        novo->m++;
                    } else if (k1 > meio) {
                        novo2->clientes[k2] = guardaCli[k1];
                        novo2->m++;
                        k2++;
                    }
                }
                //------------------------------------------------//
                fseek(arq_Dados, metadados->pont_prox_no_livre, SEEK_SET);
                salva_no(d, novo, arq_Dados);
                novoPai->p[0] = metadados->pont_prox_no_livre;
                metadados->pont_prox_no_livre = fseek(arq_Dados, 0, SEEK_END);

                fseek(arq_Dados, metadados->pont_prox_no_livre, SEEK_SET);
                salva_no(d, novo2, arq_Dados);
                novoPai->p[1] = metadados->pont_prox_no_livre;
                metadados->pont_prox_no_livre = fseek(arq_Dados, 0, SEEK_END);

                fseek(arq_Dados, novo->pont_pai, SEEK_SET);
                salva_no(d, novoPai, arq_Dados);

                //fclose(arq_Dados);
                salva_arq_metadados(nome_arquivo_metadados, metadados);


                return pos;
            }



        }

    }



}

int exclui(int cod_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}
