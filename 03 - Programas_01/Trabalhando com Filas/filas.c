#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila {
    char nome[40];
    struct fila *prox;
} celula;

void inserir(celula **fila, char *Nome) {
    printf("\n=====Inserido=====\n");
    celula *aux, *novo = malloc(sizeof(celula));
    if (novo) {
        strcpy(novo->nome, Nome);
        novo->prox = NULL;
        if (*fila == NULL) {
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } else {
        printf("\n\nErro de alocacao de memoria");
    }
}

celula *remover(celula **fila) {
    celula *remover = NULL;
    if (*fila != NULL) {
        remover = *fila;
        *fila = (*fila)->prox;
    } else {
        printf("\nFila vazia!\n");
    }
    return remover;
}

void imprimir(celula *fila) {
    printf("\n------FILA------\n");
    while (fila != NULL) {
        printf("%s\n", fila->nome);
        fila = fila->prox;
    }
    printf("\n----------------\n");
}

int main() {
    int opc;
    char nome[40];
    celula *r, *fila = NULL;
    do {
        printf("\n======Menu=====\n1.Inserir\n2.Remover\n3.Exibir\n0.Sair\nOpc: ");
        scanf("%d", &opc);
        getchar();
        switch (opc) {
            case 1:
                printf("Insira um nome para a fila: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remover o caractere de nova linha
                inserir(&fila, nome);
                break;
            case 2:
                r = remover(&fila);
                if (r) {
                    printf("Removido: %s\n", r->nome);
                    free(r);
                }
                break;
            case 3:
                imprimir(fila);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!!\n");
        }
    } while (opc != 0);
    return 0;
}
