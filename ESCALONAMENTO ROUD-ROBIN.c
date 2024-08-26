#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Processo
struct Processo {
    int id; // ID do processo
    int tempo_execucao;
    int tempo_restante;
    char estado[50]; // Pronto, Executando ou Terminado
    struct Processo *prox;
};

typedef struct Processo Processo;

Processo *primeiro = NULL;

// inserir um processo na fila
void InserirProcesso(int tempo, int id) {
    if(primeiro == NULL){
        primeiro = malloc(sizeof(Processo));
        primeiro->id = id;
        primeiro->tempo_execucao = 0;
        primeiro->tempo_restante = tempo;
        strcpy(primeiro->estado, "Pronto");
        primeiro->prox = NULL;
    }
    else{
        Processo *aux = primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        Processo *novo = malloc(sizeof(Processo));
        novo->id = id;
        novo->tempo_execucao = 0;
        novo->tempo_restante = tempo;
        strcpy(novo->estado, "Pronto");
        novo->prox = NULL;
        aux->prox = novo;
    }
}

//Encadear a Fila
void EncadearFila(){
    Processo *aux = primeiro;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = primeiro;
}

// Simular o Escalonamento Round-Robin
void SimulaEscalonamento(int quantum, int qtd_processos) {
    int tempo = 0;
    int processos_terminados = 0;
    Processo *aux = primeiro;
    while (processos_terminados < qtd_processos) {
        if(aux->tempo_restante <= 0) {
            aux = aux->prox;
        }
        else{
            strcpy(aux->estado, "Executando");
            printf("Tempo %d: Processo %d (%s)\n", tempo, aux->id, aux->estado);
            if (aux->tempo_restante <= quantum) {
                tempo += aux->tempo_restante;
                aux->tempo_execucao += aux->tempo_restante;
                aux->tempo_restante = 0;
                strcpy(aux->estado, "Terminado");
                printf("Tempo %d: Processo %d (%s)\n", tempo, aux->id, aux->estado);
                processos_terminados++;
            } else {
                tempo += quantum;
                aux->tempo_execucao += quantum;
                aux->tempo_restante -= quantum;
                strcpy(aux->estado, "Pronto");
                printf("Tempo %d: Processo %d (%s)\n", tempo, aux->id, aux->estado);
            }
            aux = aux->prox;
        }
    }
}

void Desencadear(){
    Processo *aux = primeiro;
    while(aux->prox != primeiro){
        aux = aux->prox;
    }
    aux->prox = NULL; //Desencadeou
}

void LiberarMemoria(){
    Processo *aux = primeiro;
    while(aux->prox != NULL){
        primeiro = aux->prox;
        free(aux);
        aux = primeiro;
    }
    free(aux);
}

int main() {
    printf("==========================================================================================\n");
    printf("                           ESCALONAMENTO ROUND-ROBIN\n");
    printf(" Projeto Final de Laboratório de Estrutura de Dados\n");
    printf(" Professor Modesto\n");
    printf(" L.E.S.D. ALUNOS = GABRIEL CANDIDO; GABRIEL OLIVEIRA; GUSTAVO FROSSARD; NICOLAS CAMPOS\n");
    printf("==========================================================================================\n");

    int qtd_processos, quantum;
    printf("Digite a quantidade de processos: ");
    scanf("%d", &qtd_processos);
    int tempo_execucao[qtd_processos];
    for (int i = 0; i < qtd_processos; i++) {
        printf("Digite o tempo de execucao do processo %d: ", i + 1);
        scanf("%d", &tempo_execucao[i]);
        InserirProcesso(tempo_execucao[i], i + 1);
    }

    EncadearFila();

    printf("Digite o tempo de quantum da CPU: ");
    scanf("%d", &quantum);

    SimulaEscalonamento(quantum, qtd_processos);

    Desencadear();
    LiberarMemoria();

    return 0;
}
