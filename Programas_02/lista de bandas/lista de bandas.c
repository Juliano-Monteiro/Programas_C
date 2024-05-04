#include <stdio.h>

#define TOP 5

typedef struct {
    char nome[40];
    char tipo[20];
    int integrantes;
    int rank;
} Banda;

void preenche(Banda *bandas) {
    for(int i = 0; i < TOP; i++) {
        printf("Nome da Banda: ");
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);
        printf("Tipo de musica: ");
        fgets(bandas[i].tipo, sizeof(bandas[i].tipo), stdin);
        printf("Numero de integrantes: ");
        scanf("%d", &bandas[i].integrantes);
        printf("Posicao do rank: ");
        scanf("%d", &bandas[i].rank);
        getchar(); // Captura o caractere de nova linha deixado pelo scanf
    }
}

void exibir(Banda *bandas) {
    system("cls || clear");
    for(int i = 0; i < TOP; i++) {
        printf("============= Top %d =============\n",bandas[i].rank);
        printf("Nome da Banda: %s", bandas[i].nome);
        printf("Tipo de Musica: %s", bandas[i].tipo);
        printf("Numero de Integrantes: %d\n\n", bandas[i].integrantes);
    }
    int desejo;
    printf("\nDeseja pesquisar uma posicao do rank?\n1.Sim\n0.Nao\nOpc: ");
    scanf("%d",&desejo);
    while(desejo==1){
        int j=0;
        printf("\nPesquisar banda por rank [0 para sair]: ");
        scanf("%d",&j);
        if(j!=0){
            j--;
            printf("\n============= Top %d =============\n",bandas[j].rank);
            printf("Nome da Banda: %s", bandas[j].nome);
            printf("Tipo de Musica: %s", bandas[j].tipo);
            printf("Numero de Integrantes: %d\n\n", bandas[j].integrantes);
        }
        else{
            desejo=0;
        }

    }
        printf("\nFim do programa!");

}

int main() {
    system("cls || clear");
    Banda bandas[TOP];
    preenche(bandas);
    exibir(bandas);

    return 0;
}

