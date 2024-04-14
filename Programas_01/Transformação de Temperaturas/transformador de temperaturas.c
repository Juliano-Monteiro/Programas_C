#include <stdio.h>
int menu();
int trasformacao(int opr);
int main()
{
    printf("App de convercao de Celsius e Fahrenheit");
    int opr=menu();
    float result=trasformacao(opr);
    printf("O resultado eh: %.2f",result);
    return 0;
}
int menu(){
    int operacao;
    printf("O que deseja fazer?\n1.Celsius para Fahrenheit\n2.Fahrenheit para Celsius\nOperacao: ");
    scanf("%d",&operacao);
    return(operacao);
}
int trasformacao(int opr){

    float c,f;
    switch(opr){
        case 1:
            //F= (9.C/5) + 32
            printf("Digite o valor em Celsius: ");
            scanf("%f",&c);
            f=((c*9/5)+32);
            return(f);
            break;
        case 2:
            //5.(F-32)/9
            printf("Digite o valor em Fahrenheit: ");
            scanf("%f",&f);
            c=(((f-32)*5)/9);
            return(c);
            break;
    }
}
