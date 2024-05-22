#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    char Onome[50], email[50];
    char emprego[25];
    int rg, cpf, codigo_conta, telefone, senha, salario;
} conta;

void interface();
void criarConta();

int main(void) {
    interface();
    return 0;
}

void interface() {
    system("cls || clear");
    int opr;
    char url[] = "Dados.txt";
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("+|\t\tBANCO JMS\n");
    printf("+|\n");
    printf("+|\t1. Entrar\n");
    printf("+|\t2. Criar Conta\n");
    printf("+|\t0. Sair\n");
    printf("+|\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\nOperacao = ");
    scanf("%d", &opr);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    switch (opr) {
        case 1:
            printf("\nOperacao de entrar\n");
            break;
        case 2:
            criarConta(url);
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOPERACAO INVALIDA!!!\n");
            break;
    }
}

void criarConta(char *url) {
    system("cls || clear");
    conta Conta;
    FILE *novaConta;
    novaConta = fopen(url,"a");
    srand( (unsigned)time(NULL) );
    printf("Digite seu nome: ");
    fgets(Conta.Onome, sizeof(Conta.Onome), stdin);
    Conta.Onome[strcspn(Conta.Onome, "\n")] = '\0'; // Remove o caracter de nova linha \n

    printf("Digite seu email: ");
    fgets(Conta.email, sizeof(Conta.email), stdin);
    Conta.email[strcspn(Conta.email, "\n")] = '\0'; // Remove o caracter de nova linha \n

    printf("Digite seu emprego: ");
    fgets(Conta.emprego, sizeof(Conta.emprego), stdin);
    Conta.emprego[strcspn(Conta.emprego, "\n")] = '\0'; // Remove o caracter de nova linha \n

    printf("Digite seu RG: ");
    scanf("%d", &Conta.rg);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu CPF: ");
    scanf("%d", &Conta.cpf);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu telefone: ");
    scanf("%d", &Conta.telefone);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite sua senha: ");
    scanf("%d", &Conta.senha);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu salario: ");
    scanf("%d", &Conta.salario);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    Conta.codigo_conta = rand();
    // Exibindo os valores dos membros da estrutura conta
    printf("\nNome: %s\n", Conta.Onome);
    printf("Email: %s\n", Conta.email);
    printf("Emprego: %s\n", Conta.emprego);
    printf("RG: %d\n", Conta.rg);
    printf("CPF: %d\n", Conta.cpf);
    printf("Codigo da Conta: %d\n", Conta.codigo_conta);
    printf("Telefone: %d\n", Conta.telefone);
    printf("Senha: %d\n", Conta.senha);
    printf("Salario: %d\n", Conta.salario);
    if(novaConta == NULL){
        printf("\nArquivo nao encontrado!!\n");
    }
    else{
        fprintf(novaConta,"%s %s %s %d %d %d %d %d %d \n",Conta.Onome,Conta.emprego,Conta.email,Conta.rg,Conta.cpf,Conta.telefone,Conta.salario,Conta.senha,Conta.codigo_conta);
    }
    interface();
}
