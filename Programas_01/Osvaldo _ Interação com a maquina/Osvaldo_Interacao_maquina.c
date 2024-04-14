#include<stdio.h>
void oi();
void tudobem();
void dia();
void sair();
int main()
{
        int opr=1;
        do{
            printf("\n\n\nFale com o Osvaldo escolhendo uma das alternativas:\n1. Oi Osvaldo!\n2. Bom dia Osvaldo, como foi o seu dia?\n3. Como voce ta?\n0. Tchau Osvaldo!\n\n");
            scanf("%d",&opr);
            system("cls || clear");
            switch(opr){
                case 1:
                    oi();
                    break;
                case 2:
                    dia();
                    break;
                case 3:
                    tudobem();
                    break;
                case 0:
                    sair();
                    opr=0;
                    break;
                default:
                    printf("Operacao invalida!\n\n\n");
                }
        }while(opr);



}
void oi(){
    char nome[15];
    printf("Ola!! prazer em conhecer voce... Qual eh seu nome mesmo?\n");
    scanf("%s",&nome);
    printf("Ahhh, que legal! prazem em conhecer voce entao %s. Meu nome eh Osvaldo :)\n",nome);
}
void tudobem(){
    int resposta;
    printf("Eu to otimo! E voce, como esta? :)\n");
    printf("1.Eu to bem!\n2.Estou mais ou menos bem:/\n3.Estou pessimo(a)\nResposta: ");

    scanf("%d",&resposta);
    switch(resposta){
    case 1:
        printf("\nQue bom!!\n");
        break;
    case 2:
        printf("\nBom as vezes a gente nao encherga o melhor caminho\nEstamos nele sem saber\nE caminhando por ele, conseguimos enxergar maravilhas! :)");
        break;
    case 3:
        printf("\nFazes ruins acontecem para nos deixar mais fortes!\n");
        break;
    default:
        resposta=0;
    }
}
void dia(){
    printf("\nMeu dia...... isso eh dificil de dizer, numca tive um dia, nunca vi o sol :(\n\n\n");
}
void sair(){
    printf("Vai me abandonar eh? Ate a proxima!! :)\n\n\n");
    printf("\n\n");
}
