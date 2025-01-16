#include <string.h>
#include "arquivo.h"
#include "constantes.h"
#include "refCruzada.h"


/*----------------------------------------------------------------------------*/
/* abreArquivo()                                                              */
/* Se sucesso, retorna o apontador do arquivo                                 */
/* Se falhar, retorna NULL                                                    */
/*----------------------------------------------------------------------------*/
FILE* abreArquivo(char* nome)
{
    FILE *pFile = NULL;
    pFile = fopen(nome, "r");
    return pFile;
}

/*----------------------------------------------------------------------------*/
/* fechaArquivo()                                                             */
/* Se sucesso, retorna true                                                   */
/* Se falhar, retorna false                                                   */
/* A função fclose() retorna 0 se sucesso e EOF se falhar                     */
/*----------------------------------------------------------------------------*/
bool fechaArquivo(FILE *pFile)
{
    if (fclose(pFile) == 0)
        return true;
    else
        return false;
}

/*----------------------------------------------------------------------------*/
/* leLinha()                                                                  */
/* Se sucesso, retorna true e a linha lida em buffer                          */
/* Se falhar, retorna false                                                   */
/* Se a linha termina com '\n', esse caractere será suprimido da string lida  */
/*----------------------------------------------------------------------------*/
bool leLinha(FILE *pFile, char* buffer, int size)
{
    int length = 0;
    char *aux = NULL;
    aux = fgets(buffer, size, pFile);
    if (aux != NULL) {
        length = strlen(buffer);
        if (length > 0 && (buffer[length-1] == '\n') )
            buffer[length-1] = '\0';
        return true;
    }
    else {
        buffer[0] = '\0'; //Deixa buffer com string vazia ""
        return false;
    }
}

/*----------------------------------------------------------------------------*/
/* gravaOcorrenciasPalavra()                                                  */
/* Grava no arquivo de relatório a lista de ocorrências de uma certa palavra. */
/* Cada ocorrência é o número da linha em que a palavra foi encontrada no     */
/* arquivo TXT.                                                               */
/* Por exemplo, já foi gravada no início da linha a palavra com a quantidade  */
/* de ocorrências: 'ELFO;6'.                                                  */
/* A linha no arquivo estará assim:                                           */
/* ELFO;6                                                                     */
/* Após a execução desta função, estará assim:                                */
/* ELFO;6;358;1248;1299;4518;4621;5164                                        */
/*----------------------------------------------------------------------------*/
void gravaOcorrenciasPalavra(FILE* pFile, struct ocorrencia* lista)
{
    while(lista != NULL){
        fprintf(pFile, ";%d",lista->linha);
        lista = lista->prox;
    }
   // Implementado
}



/*----------------------------------------------------------------------------*/
/* geraRelatorio()                                                            */
/* Se sucesso, retorna true                                                   */
/* Se falhar, retorna false                                                   */
/* Grava todas as palavras e suas ocorrências em um arquivo CSV               */
/* Em cada linha grava uma palavra, depois a quantidade de ocorrências, depois*/
/* a lista de ocorrências (números das linhas em que a palavra aparece).      */
/* Cada dado deve vir separdo por ponto-e-vírgula                             */
/* Usa a função gravaOcorrenciasPalavra() como auxiliar                       */
/* Exemplo do resultado final do relatório num arquivo CSV:                   */
/* Note que a palavra HOBBIT aparece duas vezes, nas linhas 1 e 3.            */
/* A;1;3                                                                      */
/* ARENOSA;1;3                                                                */
/* CHEIA;1;2                                                                  */
/* CHEIRO;1;2                                                                 */
/* CHÃO;1;1                                                                   */
/* COM;1;2                                                                    */
/* COMER;1;3                                                                  */
/* CONFORTO;1;4                                                               */
/* DE;4;2;2;2;3                                                               */
/* DESAGRADÁVEL;1;1                                                           */
/* DIZER;1;4                                                                  */
/* E;4;1;2;2;3                                                                */
/* EM;1;3                                                                     */
/* ERA;1;3                                                                    */
/* HOBBIT;2;1;3                                                               */
/*----------------------------------------------------------------------------*/
bool geraRelatorio(struct refCruzada* rc)
{
    rc->arqRelatorio = fopen(rc->nomeArqRelatorio, "w");
    if (rc->arqRelatorio == NULL)
        return false;

    struct elemento* atual = rc->listaPalavras;
    while (atual != NULL) {
        fprintf(rc->arqRelatorio, "%s;%d", atual->palavra, atual->contagem);
        gravaOcorrenciasPalavra(rc->arqRelatorio, atual->listaOcorrencia);
        fprintf(rc->arqRelatorio,"\n");
        atual = atual->prox;
    }
    fclose(rc->arqRelatorio);
    return true;
}
