#include <stdio.h>
#include <math.h>
int delta(int a,int b, int c);
int equacao(int deltaA,int b,int a);
int main()
{
    system("cls || clear");
    int a,b,c;
    printf("Informe o valor de a:");
    scanf("%d",&a);
    printf("Informe o valor de b:");
    scanf("%d",&b);
    printf("Informe o valor de c:");
    scanf("%d",&c);
    int deltaA=delta(a,b,c);
    printf("O valor do delta eh: %d\n", deltaA);
    equacao(deltaA,b,a);
}
int delta(int a,int b, int c){
    int calculo = (b*b)-(4*a*c);
    return(calculo);
}
int equacao(int deltaA,int b,int a){
    deltaA=sqrt(deltaA);
    if(deltaA>0){
        int x1 = (((-1)*b)-deltaA)/(2*a);
        int x2 = (((-1)*b)+deltaA)/(2*a);
        printf("O valor de x1 = %d\nO valor de x2 = %d\n",x1,x2);
    }
    if(deltaA==0){
            int x=((-1)*b)/(2*a);
        printf("O valor de x = %d\n",x);
    }
    if(deltaA<0){
        printf("O delta nao pode ser negativo!");
    }
}
