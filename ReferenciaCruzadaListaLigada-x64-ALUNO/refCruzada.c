#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constantes.h"
#include "refCruzada.h"
#include "arquivo.h"    //Fun��es de leitura de arquivo texto
#include "stringaux.h"  //Fun��es auxiliares para tratar strings

/*----------------------------------------------------------------------------*/
/* alocaElemento()                                                            */
/* Aloca-se um elemento toda vez que uma nova palavra � encontrada, ou seja,  */
/* uma que ainda n�o existe na Lista de Refer�ncia Cruzada. Ent�o, ao criar   */
/* tome os seguintes cuidados nesta fun��o:                                   */
/* 1)                                                                         */
/* Deixe o campo contagem com 1, pois � a primeira ocorr�ncia desta palavra   */
/* 2)                                                                         */
/* Duplique a string novaPalavra com aloca��o din�mica para guardar no campo  */
/* palavra.                                                                   */
/* 3)                                                                         */
/* Deixe prox com NULL                                                        */
/* 4)                                                                         */
/* Deixe listaOcorrencia com NULL                                             */
/*----------------------------------------------------------------------------*/
struct elemento* alocaElemento(char* novaPalavra){
    struct elemento *novoEle = malloc(sizeof(struct elemento));
    if(novoEle == NULL){
        printf("Erro ao Alocar Elemento\n");
        exit(0);
    }
    novoEle->contagem = 1;
    novoEle->palavra = strdup(novaPalavra);
    novoEle->listaOcorrencia = NULL;
    novoEle->prox = NULL;
    return novoEle;
    //Implementado
}

/*----------------------------------------------------------------------------*/
/* removeElemento()                                                           */
/* Deve chamar a fun��o removeListaOcorrencia() para este elemento            */
/* Deve liberar a mem�ria da string palavra                                   */
/* Deve liberar a mem�ria da struct elemento                                  */
/*----------------------------------------------------------------------------*/
void removeElemento(struct elemento *el)
{
    struct elemento *aux = el;
    while(el != NULL){
        removeListaOcorrencia(el->listaOcorrencia);
        el = el->prox;
        free(aux);
        aux = el;
    }
    //Implementado
}

/*----------------------------------------------------------------------------*/
/* alocaOcorrencia()                                                          */
/* Ao alocar, j� recebe o n�mero da linha                                     */
/* Deixe prox em NULL                                                         */
/*----------------------------------------------------------------------------*/
struct ocorrencia* alocaOcorrencia(int numLinha)
{
    struct ocorrencia *novoOco = malloc(sizeof(struct ocorrencia));
    if(novoOco == NULL){
        printf("Erro ao Alocar Ocorrencia\n");
        exit(0);
    }
    novoOco->linha = numLinha;
    novoOco->prox = NULL;
    return novoOco;
    //Implementado
};

/*----------------------------------------------------------------------------*/
/* removeListaOcorrencia()                                                    */
/* Remove todos os n�s da lista.                                              */
/*----------------------------------------------------------------------------*/
void removeListaOcorrencia(struct ocorrencia *oc)
{
    struct ocorrencia *aux = oc;
    while(aux != NULL){
        oc = oc->prox;
        free(aux);
        aux = oc;
    }
    //Implementado
}

/*----------------------------------------------------------------------------*/
/* insereOcorrenciaNoFinal()                                                  */
/* oc � a lista atual de ocorr�ncias e pode ser NULL, quando est� vazia.      */
/* novo � o n� a ser inserido.                                                */
/* A inser��o sempre ocorre no final da lista.                                */
/* Depois de inserir um novo n�s, retorna o apontador para o primeiro da lista*/
/* Note que o primmeiro n� da lista s� muda quando a lista est� vazia         */
/*----------------------------------------------------------------------------*/
struct ocorrencia *insereOcorrenciaNoFinal(struct ocorrencia *oc, struct ocorrencia *novo)
{
    if (oc == NULL) {
        oc = novo;
        return oc;
    }
    struct ocorrencia *aux = oc;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = NULL;
    return oc;
    //implementado
}


/*----------------------------------------------------------------------------*/
/* insereOcorrenciaNoInicio() //retirada                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* alocaRefCruzada()                                                          */
/* Guarda os nomes dos arquivos de entrada e do relat�rio de sa�da:           */
/* nomeArqEntrada e nomeArqRelatorio                                          */
/* Inicialmente listaPalavras fica vazia (NULL)                               */
/* Os apontadores de arquivo de entrada e sa�da ficam em NULL                 */
/* totalPalavras come�a com ZERO                                              */
/* numeroLinha come�a com ZERO                                                */
/*----------------------------------------------------------------------------*/
struct refCruzada* alocaRefCruzada(char* nomeArqEntrada, char* nomeArqRelatorio)
{
    struct refCruzada *rc = (struct refCruzada*) malloc(sizeof(struct refCruzada));
    if (rc == NULL) {
        fprintf(stderr, "Mem�ria esgotada na fun��o %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }

    rc->nomeArqEntrada   = strdup(nomeArqEntrada);
    rc->nomeArqRelatorio = strdup(nomeArqRelatorio);
    if( rc->nomeArqEntrada == NULL || rc->nomeArqRelatorio == NULL ){
        free(rc->nomeArqEntrada);
        free(rc->nomeArqRelatorio);
        free(rc);
        fprintf(stderr, "Mem�ria esgotada na fun��o %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }

    //Inicialmente n�o h� nenhuma palavra
    rc->totalPalavras = 0;
    rc->numeroLinha   = 0;
    rc->listaPalavras    = NULL;
    rc->arqEntrada       = NULL;
    rc->arqRelatorio     = NULL;
    return rc;
}

/*----------------------------------------------------------------------------*/
/* removeRefCruzada()                                                         */
/* Remove todas as palavras de listaPalavras.                                 */
/* Percorre a lista do in�cio ao fim e para cada elemento, invoca a fun��o    */
/* removeElemento() que remove struct elemento e a lista de ocorr�ncias.      */
/* Depois que todas as palavras forem removidas, libera a mem�ria das strings */
/* nomeArqEntada e nomeArqRelatorio.                                          */
/* Finalmente remove a struct refCruzada rc.                                  */
/*----------------------------------------------------------------------------*/
void removeRefCruzada(struct refCruzada *rc)
{
    if (rc != NULL) {
        free(rc->nomeArqEntrada);
        free(rc->nomeArqRelatorio);
        struct elemento* atual = rc->listaPalavras;
        while (atual != NULL) {
            struct elemento* prox = atual->prox;
            removeElemento(atual);
            atual = prox;
        }
        free(rc);
    }
}

/*----------------------------------------------------------------------------*/
/* insereAtualiza()                                                           */
/* A inser��o deve manter ordenada a lista de palavras.                       */
/* A inser��o da primeira palavra exige um tratamento especial, pois          */
/* listaPalavras est� em NULL.                                                */
/* Inserir uma palavra que passa a ser a primeira da lista, tamb�m � um caso  */
/* especial, pois atualiza para onde aponta rc->listaPalavras.                */
/* Se a palavra j� estiver na lista, apenas a nova ocorr�ncia � registrada,   */
/* caso contr�rio, a palavra deve ser inserida na posi��o correta com a       */
/* primeira ocorr�ncia associada.                                             */
/* O n�mero da linha da ocorr�ncia estar� em rc->numeroLinha                  */
/*----------------------------------------------------------------------------*/
void insereAtualiza(struct refCruzada *rc, char* palavra) {
    struct elemento *aux = rc->listaPalavras;
    struct elemento *novaPalavra = NULL;
    struct ocorrencia *novaOcorrencia = NULL;
    struct elemento *prev = NULL;

    if (aux == NULL){
        novaPalavra = alocaElemento(palavra);
        novaOcorrencia = alocaOcorrencia(rc->numeroLinha);
        novaPalavra->listaOcorrencia = insereOcorrenciaNoFinal(novaPalavra->listaOcorrencia, novaOcorrencia);
        novaPalavra->prox = aux;
        rc->listaPalavras = novaPalavra;
        return ;
    }
    else if (strcmp(aux->palavra, palavra) > 0) {
        novaPalavra = alocaElemento(palavra);
        novaOcorrencia = alocaOcorrencia(rc->numeroLinha);
        novaPalavra->listaOcorrencia = insereOcorrenciaNoFinal(novaPalavra->listaOcorrencia, novaOcorrencia);
        novaPalavra->prox = aux;
        rc->listaPalavras = novaPalavra;
        return ;
    }
    else{
        prev = aux;
        aux = aux->prox;
        while (aux != NULL) {
            if (strcmp(aux->palavra, palavra) == 0) {
                novaOcorrencia = alocaOcorrencia(rc->numeroLinha);
                aux->listaOcorrencia = insereOcorrenciaNoFinal(aux->listaOcorrencia, novaOcorrencia);
                aux->contagem = aux->contagem + 1;
                return ;
            }
            else if (strcmp(aux->palavra, palavra) > 0) {
                novaPalavra = alocaElemento(palavra);
                novaOcorrencia = alocaOcorrencia(rc->numeroLinha);
                novaPalavra->listaOcorrencia = insereOcorrenciaNoFinal(novaPalavra->listaOcorrencia, novaOcorrencia);
                novaPalavra->prox = aux;
                prev->prox = novaPalavra;
                return ;
            }
            prev = aux;
            aux = aux->prox;
        }
        novaPalavra = alocaElemento(palavra);
        novaOcorrencia = alocaOcorrencia(rc->numeroLinha);
        novaPalavra->listaOcorrencia = insereOcorrenciaNoFinal(novaPalavra->listaOcorrencia, novaOcorrencia);
        prev->prox = novaPalavra;
        novaPalavra->prox = NULL;
    }
    //implementado
}


/*----------------------------------------------------------------------------*/
/* geraReferenciaCruzada()                                                    */
/* nomeArquivoEntrada   --> O arquivo precisa ser .TXT                        */
/* nomeArquivoSaida     --> O arquivo de sa�da � do tipo csv                  */
/*----------------------------------------------------------------------------*/
void geraReferenciaCruzada(char* nomeArquivoEntrada, char* nomeArquivoSaida)
{
    struct refCruzada *rc = NULL;
    regex_t reg;                     //Guarda a ER compilada
    regmatch_t match;                //Guarda info sobre um casamento da ER
    char buffer[BUFFER_SIZE];        //Mant�m uma linha do arquivo texto de origem
    char palavra[MAX_WORD_SIZE];     //Guarda uma palavra surgida do casamento com a ER
    char errorMessage[BUFFER_SIZE];  //Caso a ER seja mal formada, mant�m dica sobre o erro
    int start = 0;                   //Controla o ponto a partir de buffer em que procura casar a ER
    int errCode = 0;                 //C�digo de erro, caso a ER seja mal formada
    char *expReg  = "[a-zA-Z����������������������������]{1,}"; //A ER propriamente dita

    //Essa express�o regular casa uma letra de a-z ou A-Z, incluindo as acentua��es
    //E permite repeti��es {1,} ou seja, um ou mais caracteres.
    printf("ER = \"%s\"\n", expReg); //Imprime a express�o regular

	rc = alocaRefCruzada(nomeArquivoEntrada, nomeArquivoSaida);

    rc->arqEntrada = abreArquivo(rc->nomeArqEntrada);
    if (rc->arqEntrada == NULL) {
        printf("N�o conseguiu abrir o arquivo %s\n", rc->nomeArqEntrada);
        exit(0);
    }

    //Trata todas as linhas do arquivo de entrada
    while (leLinha(rc->arqEntrada, buffer, BUFFER_SIZE)) {
        //printf("%s\n", buffer);
        rc->numeroLinha++;

        //Compila a express�o regular 'expReg' na estrutura 'reg' e considera
        //a sintaxe pr�pria de Express�es Regulares Estendidas
        if ( (errCode = regcomp(&reg , expReg, REG_EXTENDED)) != 0) {
		    regerror (errCode, &reg, errorMessage, BUFFER_SIZE);
		    fprintf(stderr, "H� UM ERRO DE CONSTRU��O NA ER\n");
		    fprintf(stderr,"%s\n",errorMessage);
		    exit(1);
	    }

	    start = 0; //O primeiro casamento � procurada a partir do in�cio de buffer
	    //match pode ser um array que recebe v�rios casamentos, mas queremos
	    //realizar os casamentos de um em um, da� o par�metro 1.
	    //O par�metro zero indica que n�o estamos sinalizando nem in�cio nem fim de linha
	    //REG_NOTBOL, REG_NOTEOL
	    errCode = regexec(&reg, buffer, 1, &match, 0); //Retorna 0 (sucesso) ou REG_NOMATCH (sem casamento)
	    //Tenta casar a ER mais vezes na string
	    while (errCode == 0) {
		       //printf("in�cio da string de pesquisa atual no caractere %d\n",start);
		       //printf("string de pesquisa = \"%s\"\n",buffer+start);
		       //printf("casou do caractere = %d ao %d\n",match.rm_so,match.rm_eo-1);

		       // match.rm_so � o �ndice do caractere em que inicia a string que casou
		       // match.rm_eo � o �ndice do caractere seguinte ao que termina a string que casou,
		       // ent�o (match.rm_eo-match.rm_so) � o exato tamanho da string. Sem considerar terminador.
		       // Somar a start match.rm_eo oferece o novo ponto de in�cio da busca.
		       subString(buffer+start, match.rm_so, (match.rm_eo-match.rm_so), palavra, MAX_WORD_SIZE );
		       printf("Palavra encontrada = %s\n\n", palavra); //Comente esta linha para ter desempenho
		       start +=match.rm_eo; //Atualiza o in�cio do buffer.
		       strupper(palavra);
               insereAtualiza(rc, palavra);
		       errCode = regexec(&reg, buffer+start, 1, &match, REG_NOTBOL); //Faz o pr�ximo casamento
	    }
	    regfree(&reg);
    }
    if (fechaArquivo(rc->arqEntrada) == false){
        printf("N�o conseguiu fechar o arquivo de entrada\n");
        exit(0);
    }
    geraRelatorio(rc);
    removeRefCruzada(rc);

}
