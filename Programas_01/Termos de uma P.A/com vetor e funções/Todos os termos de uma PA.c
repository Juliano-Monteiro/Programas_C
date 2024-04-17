#include <stdio.h>
#define trm 10
void PA(int valores[]){
    int cont;
    int a1,r,calculo;
    printf("Ensira o termo inicial da PA: ");
    scanf("%d",&a1);
    printf("Ensira a razao da PA: ");
    scanf("%d",&r);
    calculo=a1;
    for(cont=0;cont<trm;cont++){
        valores[cont]=calculo;
        calculo*=r;
    }

}
void exibir(int valores[]){
    int cont;
    for(cont=0;cont<trm;cont++){
        printf(" | %d | ",valores[cont]);
    }
}
int main()
{
    int valores[trm];
    PA(valores);
    exibir(valores);
    return 0;
}

