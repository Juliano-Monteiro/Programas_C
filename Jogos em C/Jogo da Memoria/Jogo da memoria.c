#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#define dim 4
char matriz[dim][dim];
int jogadas = 0;
int verifica = 0;

char matriz[dim][dim] = {                       //Esse é a matriz original das cartas - Parte da frente
        {'O','O','6','6'},
        {'C','C','B','B'},
        {'E','E','3','3'},
        {'8','8','R','R'},
};

char cartasCosta[dim][dim] = {                  //Aqui são as cartas de costas
        {'+','+','+','+'},
        {'+','+','+','+'},
        {'+','+','+','+'},
        {'+','+','+','+'},
};

void tabuleiro(){ //Exibe o tabuleiro
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf(" |%c| ",cartasCosta[i][j]);
        }
        printf("\n\n");
    }
}

void embaralharCartas(){                       //Gera numeros aleatorios
    srand(time(NULL));
    for(int i =dim-1;i>0;i--){                 //Começa do ultimo elemento e vai até o segundo:
        for(int j = dim-1;j>0;j--){
            char Novo_i = rand() %(i+1);       //Gera um indice aleatório entre 0 e i para o i;
            char Novo_j = rand() %(j+1);       //Gera um indice aleatório entre 0 e j para o j;
            trocar(i,j,Novo_i,Novo_j);         //Após gerar índices aleatórios para [i] e [j] e a gente também tem o [i][j] originais, basta trocar o conteúdo desses índices para haver o embaralhamento!
        }
    }
}

void trocar(int i,int j,int novoI,int novoJ){  //Troca padrão de valores de variáveis aplicado em matrizes
    int subistitui = matriz[i][j];             //o conteudo da matriz padrão fica toda vida armazenado nessa variavel [subistitui]
    matriz[i][j] = matriz[novoI][novoJ];       //Agora todas as coisas armazenadas nas posições da matriz original são subistituidos pelos valores da nova matriz
    matriz[novoI][novoJ] = subistitui;         //E a nova matriz recebe todas as coisas armazenadas nas posições da matriz original
}

void verifica_jogada(int linha,int coluna,int linha2,int coluna2){
        if(matriz[linha][coluna]==matriz[linha2][coluna2]){
            cartasCosta[linha][coluna] = matriz[linha][coluna];
            cartasCosta[linha2][coluna2] = matriz[linha2][coluna2];
            jogadas++;
            verifica+=2;
            system("cls || clear");
            printf("\n =-=-=-=-=-=-=-=-=-=-=-=  Jogo da Memoria  =-=-=-=-=-=-=-=-=-=-=-= \n                            Jogadas: %d Cartas: %d\n\n",jogadas,verifica);
            tabuleiro();
            jogar();
        }
        else{
            cartasCosta[linha][coluna] = matriz[linha][coluna];
            cartasCosta[linha2][coluna2] = matriz[linha2][coluna2];
            jogadas++;
            tabuleiro();
            Sleep(3000);
            system("cls || clear");
            printf("\n =-=-=-=-=-=-=-=-=-=-=-=  Jogo da Memoria  =-=-=-=-=-=-=-=-=-=-=-= \n                            Jogadas: %d Cartas: %d\n\n",jogadas,verifica);
            cartasCosta[linha][coluna]= '+';
            cartasCosta[linha2][coluna2]= '+';
            tabuleiro();
        }

}
void jogar(){
    if(verifica<dim*dim){          //Se o numero de cartas reveladas forem menores que o numero de cartas totais o jogo continua!!
        int linha,coluna,linha2,coluna2;
        printf("\n\nDigite a posicao da carta seguindo essa ordem [linha][espaco][coluna]\nCarta 1: ");
        scanf("%d%d",&linha,&coluna);
        printf("\nCarta 2: ");
        scanf("%d%d",&linha2,&coluna2);
        linha--;coluna--;linha2--;coluna2--;
        if(linha<=dim&&coluna<=dim&&linha2<=dim&&coluna2<=dim){     //Se as posicoes existirem na matriz
            if(cartasCosta[linha][coluna]!=matriz[linha][coluna]&&cartasCosta[linha2][coluna2]!=matriz[linha2][coluna2]){ //Se os dados inseridos forem diferentes então é possivel passar os argumentos
                verifica_jogada(linha,coluna,linha2,coluna2);
            }
            else{
                printf("\nCartas ja reveladas!\n");
            }
        }
    }
    else{
        system("cls || clear");
        printf(" ====== FIM DO JOGO ======\nJogadas: %d\nCartas: %d\n",jogadas,verifica);
    }
}

int main()
{
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=  Jogo da Memoria  =-=-=-=-=-=-=-=-=-=-=-= \n                            Jogadas: %d Cartas: %d\n\n",jogadas,verifica);
    tabuleiro();
    embaralharCartas();
    do{
    jogar();
    }while(verifica<dim*dim);
    return 0;
}

