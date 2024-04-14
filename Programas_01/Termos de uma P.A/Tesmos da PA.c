
#include <stdio.h>
int main(){
    int a1,r,n,an,cont,calculo;
    cont=1;
    printf("Digite o valor inicial: ");
    scanf("%d",&a1);
    printf("Digite a razao: ");
    scanf("%d",&r);
    printf("Digite o numero de termos da P.A: ");
    scanf("%d",&n);
    calculo=a1;
    while(cont<n){
        calculo*=r;
        cont++;
        printf("%d: %d\n",cont,calculo);
    }


}
