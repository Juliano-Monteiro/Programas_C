#include <stdio.h>
#include <string.h>

#define TOP 3

typedef struct {
    char nome[40];
    char tipo[20];
    int integrantes;
    int rank;
} Banda;

char *uper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

void preenche(Banda *bandas) {
    for (int i = 0; i < TOP; i++) {
        bandas[i].rank=i+1;
        printf("======= TOP %d =======\n",bandas[i].rank);
        printf("Nome da Banda: ");
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);
        printf("Tipo de musica: ");
        uper(bandas[i].nome);
        fgets(bandas[i].tipo, sizeof(bandas[i].tipo), stdin);
        uper(bandas[i].tipo);
        printf("Numero de integrantes: ");
        scanf("%d", &bandas[i].integrantes);
        getchar(); // Captura o caractere de nova linha deixado pelo scanf
    }
}

int escolhas(Banda *bandas) {
    int opc,count;
    char pesquisa[40];
    printf("\nO que voce deseja fazer?\n1.Pesquisar uma posicao da lista\n2.Pesquisar por estilo musical\n3.Pesquisar por nome\n0.Sair\nOPC: ");
    scanf("%d", &opc);
    getchar(); // Captura o caractere de nova linha deixado pelo scanf
    switch(opc) {
        case 1:
            system("cls || clear");
            printf("\nPesquisar banda por rank [0 para sair]: ");
            scanf("%d", &count);
            getchar(); // Captura o caractere de nova linha deixado pelo scanf
            if (count != 0) {
                count--;
                printf("\n============= Top %d =============\n", bandas[count].rank);
                printf("Nome da Banda: %s\n", bandas[count].nome);
                printf("Tipo de Musica: %s\n", bandas[count].tipo);
                printf("Numero de Integrantes: %d\n\n", bandas[count].integrantes);
            } else {
                printf("Saindo da pesquisa...\n");
            }
            return 1;
        break;
        case 2:
            system("cls || clear");
            printf("Digite o tipo musical: ");
            fgets(pesquisa, sizeof(pesquisa), stdin);
            uper(pesquisa);
            for(int i = 0; i < TOP; i++){
                if(strcmp(pesquisa,bandas[i].tipo)==0){
                    printf("\n============= Top %d =============\n", bandas[i].rank);
                    printf("Nome da Banda: %s\n", bandas[i].nome);
                    printf("Tipo de Musica: %s\n", bandas[i].tipo);
                    printf("Numero de Integrantes: %d\n\n", bandas[i].integrantes);
                }
            }
            return 1;
        break;
        case 3:
            system("cls || clear");
            printf("Digite o nome: ");
            fgets(pesquisa, sizeof(pesquisa), stdin);
            uper(pesquisa);
            for(int i = 0; i < TOP; i++){
                if(strcmp(pesquisa,bandas[i].nome)==0){
                    printf("\n============= Top %d =============\n", bandas[i].rank);
                    printf("Nome da Banda: %s\n", bandas[i].nome);
                    printf("Tipo de Musica: %s\n", bandas[i].tipo);
                    printf("Numero de Integrantes: %d\n\n", bandas[i].integrantes);
                }
            }
            return 1;
        break;
        case 0:
            return 0;
        break;
        default:
            printf("Opcao invalida!\n");
            return 1;
    }
}

void exibir(Banda *bandas) {
    for (int i = 0; i < TOP; i++) {
        printf("============= Top %d =============\n", bandas[i].rank);
        printf("Nome da Banda: %s\n", bandas[i].nome);
        printf("Tipo de Musica: %s\n", bandas[i].tipo);
        printf("Numero de Integrantes: %d\n\n", bandas[i].integrantes);
    }
    int desejo;
    printf("\nDeseja realizar uma pesquisa?\n1.Sim\n0.Nao\nOpc: ");
    scanf("%d", &desejo);
    getchar(); // Captura o caractere de nova linha deixado pelo scanf
    if(desejo!=0){
        while (escolhas(bandas) == 1) {
            continue;
        }
    }

    printf("\nFim do programa!\n");
}

int main() {
    Banda bandas[TOP];
    preenche(bandas);
    exibir(bandas);

    return 0;
}
