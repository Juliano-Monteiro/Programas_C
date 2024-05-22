#include<stdio.h>
int main(){
    float salario, aumento, valorAdd, novoSalario;
    printf("Digite o valor do seu salario: ");
    scanf("%f", &salario);
    printf("Digite o valor do aumento percentual do salario: ");
    scanf("%f", &aumento);
    valorAdd = (salario*(aumento/100));
    novoSalario = (salario+valorAdd);
    printf("\nO salario antigo era de R$%.2f\nCom o aumento de %.2f foi acrecido R$%.2f\nResultando no novo salario de R$%.2f\n", salario,aumento,valorAdd,novoSalario);
}
