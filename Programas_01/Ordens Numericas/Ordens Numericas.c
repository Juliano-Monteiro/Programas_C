#include <stdio.h>
void valores(int vetor[]);
int maiorN(int vetor[]);
int menorN(int vetor[]);
int meioN(int vetor[],int maior,int menor);
int mostraCrescente(int maior,int meio, int menor);
int mostraDecrescente(int maior,int meio, int menor);
int mostraMaiorMeio(int maior,int meio, int menor);
int main(){
    int vetor[3];
    valores(vetor);
    int maior = maiorN(vetor);
    int menor = menorN(vetor);
    int meio = meioN(vetor,maior,menor);
    int I;
    printf("\n\nDigite a operação que deseja fazer\n1.Ordem Crescente\n2.Ordem Decrscente\n3.Ordem Maior no meio\nOperacao: ");
    scanf("%d",&I);
    switch(I){
        case 1:
            mostraCrescente(maior,meio,menor);
        break;
        case 2:
            mostraDecrescente(maior,meio,menor);
        break;
        case 3:
            mostraMaiorMeio(maior,meio,menor);
        break;
        default:
            printf("\nOperacao invalida!\n");
    }
}
void valores(int vetor[]){
    int i;
    for(i=0;i<3;i++){
        vetor[i] = 0;
    }
    for(i=0;i<3;i++){
        printf("Digite o valor %d:",i);
        scanf("%d",&vetor[i]);
    }
}
int maiorN(int vetor[]){
    int i;
    int maior = vetor[0];
    for(i=0;i<3;i++){
        if(maior<vetor[i]){
            maior=vetor[i];
        }
    }
    return maior;
}
int menorN(int vetor[]){
    int i;
    int menor = vetor[0];
    for(i=0;i<3;i++){
        if(menor>vetor[i]){
            menor=vetor[i];
        }
    }
    return menor;
}
int meioN(int vetor[],int maior,int menor){
    int i;
    int meio = vetor[0];
    for(i=0;i<3;i++){
        if(vetor[i]!=maior&&vetor[i]!=menor){
            meio=vetor[i];
        }
    }
    return meio;
}
int mostraCrescente(int maior,int meio, int menor){
    int Omaior = maior;
    int Omeio = meio;
    int Omenor = menor;
    printf("\n\nOrdem decrescente: %d %d %d\n",Omenor,Omeio,Omaior);
}
int mostraDecrescente(int maior,int meio, int menor){
    int Omaior = maior;
    int Omeio = meio;
    int Omenor = menor;
    printf("\n\nOrdem crescente: %d %d %d\n",Omaior,Omeio,Omenor);
}
int mostraMaiorMeio(int maior,int meio, int menor){
    int Omaior = maior;
    int Omeio = meio;
    int Omenor = menor;
    printf("\n\nOrdem Maior no Meio: %d %d %d\n",Omeio,Omaior,Omenor);
}
