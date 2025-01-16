#ifndef REFCRUZADA_H_INCLUDED
#define REFCRUZADA_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include <regex.h>      //Para usar Expressões Regulares Posix

struct refCruzada {
    char *nomeArqEntrada;
    char *nomeArqRelatorio;
    FILE *arqEntrada;
    FILE *arqRelatorio;
    int totalPalavras;
    int numeroLinha;
    struct elemento *listaPalavras;
};

struct elemento {
  int contagem;
  char* palavra;
  struct ocorrencia* listaOcorrencia;
  struct elemento* prox;
};

struct ocorrencia {
    int linha;
    struct ocorrencia *prox;
};

struct ocorrencia* alocaOcorrencia(int numeroLinha);
void removeListaOcorrencia(struct ocorrencia *oc);
struct ocorrencia *insereOcorrenciaNoFinal(struct ocorrencia *oc, struct ocorrencia *novo);
struct elemento* alocaElemento(char* palavra);
void removeElemento(struct elemento *el);
struct refCruzada* alocaRefCruzada(char* nomeArqEntrada, char* nomeArqRelatorio);
void removeRefCruzada(struct refCruzada *rc);
void insereAtualiza(struct refCruzada *rc, char* palavra);
void geraReferenciaCruzada(char* nomeArquivoEntrada, char* nomeArquivoSaida);

#endif // REFCRUZADA_H_INCLUDED
