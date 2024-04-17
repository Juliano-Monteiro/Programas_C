#include <stdio.h>
#define dim 3
char tabuleiro[dim][dim]; // matriz tipo char global, podendo ser acessado por todas as funções
void inicarTabuleiro(){//zera a matriz do jogo
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            tabuleiro[i][j] = ' ';
        }
    }
}
void exibir(){// exibe o tabuleiro do jogo
    int i,j;
    printf("\n");
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf(" %c ",tabuleiro[i][j]);
            if(j<2)printf("|");

        }
        printf("\n");
        if(i<2)printf("============\n");
    }
}
char verificaVitoria(){// verificação de vitoria
    int i;
    for(i=0;i<dim;i++){
        //verifica linhas
        if(tabuleiro[i][0]==tabuleiro[i][1]&&tabuleiro[i][0]==tabuleiro[i][2]&&tabuleiro[i][0]!=' '){
            return(tabuleiro[i][0]);
        }
        //verifica colunas
        if(tabuleiro[0][i]==tabuleiro[1][i]&&tabuleiro[0][i]==tabuleiro[2][i]&&tabuleiro[0][i]!=' '){
            return(tabuleiro[0][i]);
        }
    }
    //verifica diagonais
    if(tabuleiro[0][0]==tabuleiro[1][1]&&tabuleiro[0][0]==tabuleiro[2][2]&&tabuleiro[0][0]!=' '){
        return(tabuleiro[0][0]);
    }
    if(tabuleiro[0][2]==tabuleiro[1][1]&&tabuleiro[0][2]==tabuleiro[2][0]&&tabuleiro[0][2]!=' '){
        return(tabuleiro[0][2]);
    }
    //se nada for verdade ele só retorna o vazio
    return ' ';
}
int reinicio(){//serve para iniciar e reiniciar o jogo
    int opc;
    int reiniciar;
    printf("\nDeseja jogar?\n1. Sim\n0. Nao\nOpcao: ");
    scanf("%d",&opc);
    fflush(stdin);
    switch(opc){
        case 1:
            reiniciar = 1;
            break;
        case 0:
            reiniciar = 0;
            break;
        default:
            printf("\ncomando invalido!\n");
    }
    return(reiniciar);
}
int main()
{
    int reiniciar = reinicio();
    while(reiniciar==1){//executa o jogo enquanto reiniciar for verdade
        int i,j;
        char vencedor,jogador ='X';
        inicarTabuleiro();
        system("cls || clear");
        printf("\n================ Jogo Da Velha - JMS ================\n");
        do{

            exibir();
            if(jogador=='X'){
                printf("\n\nVEZ DO [ JOGADOR X ]| //// | exemplo: [linha] espaco [coluna]\n");
            }
            else{
                printf("\n\nVEZ DO [ JOGADOR O ]| //// | exemplo: [linha] espaco [coluna]\n");
            }
            printf("\n");
            printf("Ensira a posicao: ");
            scanf("%d%d",&i,&j);
            i--;j--;
            if(i>=0&&i<dim&&j>=0&&j<dim&&tabuleiro[i][j]==' '){
                system("cls || clear");
                tabuleiro[i][j] = jogador;
                vencedor=verificaVitoria();
                if(jogador=='X'){
                    jogador='O';
                }
                else{
                    jogador='X';
                }
            }
            else{
                printf("Posicao invalida!\n");
            }
        }while(vencedor==' '&&i>=0&&i<dim&&j>=0&&j<dim);
        exibir();
        if(vencedor!=' '){
            system("cls || clear");
            printf("\nVitoria do jogador %c !\n",vencedor);
            reiniciar = reinicio();
        }
    };
    return 0;
}
