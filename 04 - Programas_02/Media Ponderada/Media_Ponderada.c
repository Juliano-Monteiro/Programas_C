#include<stdio.h>
int main()
{
    float n1, n2, n3, media;
    int p1, p2, p3;
    printf("Digite o primeiro numero:");
    scanf("%f",&n1);
    printf("Digite o valor do primeiro peso:");
    scanf("%d",&p1);
    printf("Diggite o segundo numero: ");
    scanf("%f",&n2);
    printf("Digite o valor do primeiro peso:");
    scanf("%d",&p2);
    printf("Digite o terceiro numero: ");
    scanf("%f",&n3);
    printf("Digite o valor do primeiro peso:");
    scanf("%d",&p3);
    media = (n1*p1+n2*p2+n3*p3)/(p1+p2+p3);
    printf("O valor da media eh: %.2f", media);
}
