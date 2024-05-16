#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[40];
    char tipo[15];
    int rank;
    int integrantes;
    struct no *prox;
} No;

void inserir(No **fila, char *nome, char *tipo, int integrantes, int rank) {
    printf("\n=+=+=+=+=+=+= Inserido =+=+=+=+=+=+=\n");
    No *temp, *novo = malloc(sizeof(No));
    if (novo) {
        strcpy(novo->nome, nome);
        strcpy(novo->tipo, tipo);
        novo->integrantes = integrantes;
        novo->rank = rank;
        novo->prox = NULL;
        if (*fila == NULL) {
            *fila = novo;
        } else {
            temp = *fila;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
        }
    } else {
        printf("Erro na alocacao de memoria");
    }
    printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
}

No* remover(No **fila) {
    if (*fila == NULL) {
        printf("\nA fila esta vazia!\n");
        return NULL;
    }
    No *remover = *fila;
    *fila = (*fila)->prox;
    remover->prox = NULL; // Desconecta o nó removido da fila
    return remover;
}

void imprimir(No *fila) {
    printf("\n=+=+=+=+=+=+= Inserido =+=+=+=+=+=+=\n");
    while (fila != NULL) {
        printf("\n========== TOP %d ==========\n", fila->rank);
        printf("Nome: %s\n", fila->nome);
        printf("Estilo Musical: %s\n", fila->tipo);
        printf("Integrantes: %d\n", fila->integrantes);
        fila = fila->prox;
    }
    printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
}

int main() {
    No *fila =  NULL;
    char nome[40], tipo[15];
    int integrantes, rank = 0;
    int opr;
    do {
        printf("\nEscolha uma operacao:\n1.Inserir\n2.Remover\n3.Exibir\n0.Sair\nOpc:");
        scanf("%d", &opr);
        getchar(); // Limpa o buffer do teclado
        switch (opr) {
            case 1:
                rank++;
                printf("\nDigite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("\nDigite o estilo musical:");
                fgets(tipo, sizeof(tipo), stdin);
                printf("\nDigite o numero de integrantes:");
                scanf("%d", &integrantes);
                getchar(); // Limpa o buffer do teclado
                inserir(&fila, nome, tipo, integrantes, rank);
                break;
            case 2: {
                No *removido = remover(&fila);
                if (removido != NULL) {
                    printf("\nElemento removido:\n");
                    printf("Rank: %d\n", removido->rank);
                    printf("Nome: %s\n", removido->nome);
                    printf("Estilo Musical: %s\n", removido->tipo);
                    printf("Integrantes: %d\n", removido->integrantes);
                    free(removido); // Libera a memória alocada para o nó removido
                }
                break;
            }
            case 3:
                imprimir(fila);
                break;
            case 0:
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        }
    } while (opr != 0);

    return 0;
}
