#include <stdio.h>
#include <math.h>
int main(){
    long int a1,an,n,cont,r,num;
    cont = 1;
    printf("Digite o valor iniciald a P.G: ");
    scanf("%d",&a1);
    printf("Digite a razao: ");
    scanf("%d",&r);
    printf("Digite o numero de termos da P.G: ");
    scanf("%d",&n);
    while(cont<=n){
        num = a1*(pow(r,(cont-1)));
        printf("%d: %d\n",cont,num);
        cont++;
    }

}

