#include <stdio.h>
void menu();
void soma(float a, float b);
void sub(float a, float b);
void multi(float a, float b);
void divisa(float a, float b);
void calculadora (float a,float b,char operador);
int main()
{
    float n1,n2;
    char oper;
    do{

        menu();
        scanf("%f", &n1);
        fflush(stdin);
        scanf(" %c",&oper);
        fflush(stdin);
        scanf("%f", &n2);
        fflush(stdin);
        calculadora(n1,n2,oper);
    }while(n1 != 0 && oper != '0' && n2 != 0);


}
void menu(){
        printf("\t\t============ Calculadora em C JMS: ============\n\n");
        printf("Operacoes disponiveis:\tExemplo:\n\n");
        printf("|\t+    -\t     |\t    2\n");
        printf("|\t*    /\t     |\t    +\n");
        printf("\t\t     |      3\n");
        printf("Para sair digite: 0 0 0\n");
}
void soma(float a, float b){
    printf("%.2f )\n",a+b);
}
void sub(float a, float b){
    printf("%.2f )\n",a-b);
}
void multi(float a, float b){
    printf("%.2f )\n",a*b);
}
void divisa(float a, float b){
    if(b!=0){
        printf("%.2f )\n",a/b);
    }else{
        printf("Não pode dividir por 0.\n");
    }
}
void calculadora (float a,float b,char operador){
    system("cls || clear");
        printf("%.2f %c %.2f = ( ",a,operador,b);
        switch(operador){
            case '+':
                soma(a,b);
                break;
            case '-':
                sub(a,b);
                break;
            case '*':
                multi(a,b);
                break;
            case '/':
                divisa(a,b);
                break;
            default:
                if(a!=0&&operador!='0'&&b!=0){
                    printf("Operacao invalida!! )\n");
                }
                else{
                    printf("Fim do programa )\n");
                }
        }
}
