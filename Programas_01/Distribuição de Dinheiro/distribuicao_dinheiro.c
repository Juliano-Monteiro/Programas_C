#include <stdio.h>
#include <math.h>

int main() {
    double valor,c100,c50,c20,c10,c5,c2,m1,m050,m025,m010,m05,m01,z;
    printf("Digite um valor:");
    scanf("%lf", &valor);
    z = fmod(valor,100.0);
    c100=(valor-z)/100.0;
    valor=z;
    z = fmod(valor,50.0);
    c50=(valor-z)/50.0;
    valor=z;
    z = fmod(valor,20.0);
    c20=(valor-z)/20.0;
    valor=z;
    z = fmod(valor,10.0);
    c10=(valor-z)/10.0;
    valor=z;
    z = fmod(valor,5.0);
    c5=(valor-z)/5.0;
    valor=z;
    z = fmod(valor,2.0);
    c2=(valor-z)/2.0;
    valor=z;
    z = fmod(valor,1.0);
    m1=(valor-z)/1.0;
    valor=z;
    z = fmod(valor,0.50);
    m050=(valor-z)/0.50;
    valor=z;
    z = fmod(valor,0.25);
    m025=(valor-z)/0.25;
    valor=z;
    z = fmod(valor,0.10);
    m010=(valor-z)/0.10;
    valor=z;
    z = fmod(valor,0.05);
    m05=(valor-z)/0.05;
    valor=z;
    m01=valor/0.01;

    printf("NOTAS:\n");
    printf("%.0lf nota(s) de R$ 100.00\n", c100);
    printf("%.0lf nota(s) de R$ 50.00\n", c50);
    printf("%.0lf nota(s) de R$ 20.00\n", c20);
    printf("%.0lf nota(s) de R$ 10.00\n", c10);
    printf("%.0lf nota(s) de R$ 5.00\n", c5);
    printf("%.0lf nota(s) de R$ 2.00\n", c2);
    printf("MOEDAS:\n");
    printf("%.0lf moeda(s) de R$ 1.00\n", m1);
    printf("%.0lf moeda(s) de R$ 0.50\n", m050);
    printf("%.0lf moeda(s) de R$ 0.25\n", m025);
    printf("%.0lf moeda(s) de R$ 0.10\n", m010);
    printf("%.0lf moeda(s) de R$ 0.05\n", m05);
    printf("%.0lf moeda(s) de R$ 0.01\n", m01);


    return 0;
}
