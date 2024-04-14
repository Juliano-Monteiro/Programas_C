#include<stdio.h>
int main()
{
    float n1, n2, n3,media;
    printf("Ola esse eh um progama que calcula a media de tres notas\n");
    printf("Digite a primeira nota: ");
    scanf("%f",&n1);
    printf("Digite o segundo numero: ");
    scanf("%f",&n2);
    media = ((n1+n2)/2);
    printf("A media dos numeros %.2f e %.2f eh %f",n1,n2,media);
    return 0 ;
}
