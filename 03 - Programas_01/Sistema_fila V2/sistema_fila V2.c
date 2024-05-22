#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[40], tipo[15];
    int num;
    struct no *prox;
}No;

typedef struct {
    No *prim;
    No *ultimo;
    int tam;
} Fila;

void criar_fila(Fila *fila) {
    fila->prim = NULL;
    fila->ultimo = NULL;
    fila->tam = 0;
}

void inserir(Fila *fila, char *nome, char *tipo, int num) {
    printf("\n================ Inserido ===================\n");
    No *novo = malloc(sizeof(No));
    if (novo) {
        strcpy(novo->nome, nome);
        strcpy(novo->tipo, tipo);
        novo->num = num;
        novo->prox = NULL;
        if (fila->prim == NULL) {
            fila->prim = novo;
            fila->ultimo = novo;
        } else {
            fila->ultimo->prox = novo;
            fila->ultimo = novo;
        }
        fila->tam++;
    } else {
        printf("\nErro na alocacao de memoria!");
    }
    printf("\n=============================================\n");
}

No *remover(Fila *fila) {
    No *remove = NULL;
    if (fila->prim) {
        remove = fila->prim;
        fila->prim = remove->prox;
        fila->tam--;
    } else {
        printf("\nFila esta vazia");
    }
    return remove;
}

void exibir(Fila *fila) {
    No *aux = fila->prim;
    printf("\n================ Itens ===================\n");
    while (aux) {
        printf("\n __________________\n");
        printf("| Nome: %s", aux->nome);
        printf("| Tipo: %s", aux->tipo);
        printf("| Numero: %d", aux->num);
        printf("\n|__________________\n");
        aux = aux->prox;
    }
    printf("\n==========================================\n");
}

int main() {
    Fila fila;
    char nome[40], tipo[15];
    int num, opr;
    No *apagar = NULL;
    do {
        printf("Escolha uma das opcoes:\n1.Inserir\n2.Remover\n3.Exibir\n0.Sair\nOPR: ");
        scanf("%d", &opr);
        getchar();
        switch (opr) {
            case 1:
                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Digite o tipo musical: ");
                fgets(tipo, sizeof(tipo), stdin);
                printf("Numero de integrantes da equipe: ");
                scanf("%d", &num);
                getchar();
                inserir(&fila, nome, tipo, num);
                break;
            case 2:
                apagar = remover(&fila);
                if (apagar != NULL) {
                    printf("\n================ Apagado ===================\n");
                    printf("Nome: %s\n", apagar->nome);
                    printf("Tipo: %s\n", apagar->tipo);
                    printf("Integrantes: %d\n", apagar->num);
                    free(apagar);
                    printf("\n============================================\n");
                }
                break;
            case 3:
                exibir(&fila);
                break;
            case 0:
                break;
            default:
                printf("\nOperacao invalida");
                break;
        }
    } while (opr);

    return 0;
}
