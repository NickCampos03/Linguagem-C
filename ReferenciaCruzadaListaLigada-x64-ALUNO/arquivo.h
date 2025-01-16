#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include "refCruzada.h"

FILE* abreArquivo(char* nome);
bool fechaArquivo(FILE *pFile);
bool leLinha(FILE *pFile, char* buffer, int size);
void gravaOcorrenciasPalavra(FILE* pFile, struct ocorrencia* lista);
bool geraRelatorio(struct refCruzada* rc);

#endif // ARQUIVO_H_INCLUDED
