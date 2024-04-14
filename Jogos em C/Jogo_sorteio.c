#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sorteio();
void dicas(int numero,int tentativas,int valor_sorteado);
int main()
{
    int loop = 1,numero,tentativas,valor_sorteado;
    tentativas=0;
    do{
        system("cls || clear");
        printf("Sorteando um numero de 1 a 1000...\n");
        valor_sorteado=sorteio();
        printf("Numero sorteado, comecou!\n");
        do{
            tentativas++;
            printf("Tentativa %d: ",tentativas);
            scanf("%d",&numero);
            dicas(numero,tentativas,valor_sorteado);

        }while(numero!=valor_sorteado);
        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &loop);
        if(loop!=0){
            tentativas=0;
        }
    }while(loop);
}
int sorteio(){
    srand((unsigned)time(NULL));
    return (1 + rand()%1000);
}
void dicas(int numero,int tentativas, int valor_sorteado){
    if(numero>valor_sorteado){
        printf("O numero sorteado eh menor que %d\n\n",numero);
    }
    else{
        if(numero<valor_sorteado){
            printf("O numero sorteado eh maior que %d\n\n",numero);
        }
        else{
            printf("PARABENS!!! Voce acertou o numero sorteado em %d tentativas\n\n",tentativas);
        }
    }
}
