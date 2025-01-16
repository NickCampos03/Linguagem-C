#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <locale.h>     //Para ajustar para PT_BR
#include "refCruzada.h" //Manipulação da Estrutura de Dados
#include "arquivo.h"
#include "constantes.h"

/*----------------------------------------------------------------------------*/
/* testaArquivo()                                                             */
/*----------------------------------------------------------------------------*/
void testaArquivo(char* nomeArquivo) {
    char buffer[BUFFER_SIZE];
    FILE* pFile = abreArquivo(nomeArquivo);
    assert(pFile != NULL);

    int linha = 1;
    while (leLinha(pFile, buffer, BUFFER_SIZE)) {
        printf("[%4d]  %s\n", linha, buffer);
        linha++;
    }
    bool ret = fechaArquivo(pFile);
    assert (ret == true);
}

/*----------------------------------------------------------------------------*/
/* main()                                                                     */
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");

	if (argc != 3) {
		fprintf(stderr,"Uso: %s <ARQUIVO_ENTRADA.TXT> <ARQUIVO SAÍDA.CSV>\n", argv[0]);
		return 1;
	}

	//testaArquivo(argv[1]);
    geraReferenciaCruzada(argv[1],argv[2]);
	return 0;
}
