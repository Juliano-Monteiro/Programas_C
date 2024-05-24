#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
  // Necessario para usar Sleep()

// Definição da estrutura de uma conta
typedef struct {
    char Onome[50], email[50];
    char emprego[25];
    long int rg, cpf, telefone, senha, salario;
    float saldo;
    long int codigo_conta;
} conta;

// Declaração das fun��es
void Pagina_interface();
void criarConta(const char *url);
void loginConta(const char *url);
void IndexConta(const char *url, const char *nome, float saldo, long int codigo_conta);
void sacar(const char *url, long int codigo);
void depositarConta(const char *url, long int codigo);
void transferir(const char *url,long int codigo);
int main(void) {
    Pagina_interface();  // Chama a Pagina_interface principal
    return 0;
}

// Fun��o que exibe a Pagina_interface principal do banco
void Pagina_interface() {
    system("cls || clear");  // Limpa a tela do console
    int opr;
    char url[] = "Dados.txt";  // Arquivo que armazena os dados das contas
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

    // Chama a fun��o apropriada com base na entrada do usu�rio
    switch (opr) {
        case 1:
            loginConta(url);
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

// Fun��o para criar uma nova conta
void criarConta(const char *url) {
    system("cls || clear");  // Limpa a tela do console
    conta Conta;
    FILE *novaConta;
    novaConta = fopen(url, "a");  // Abre o arquivo para adi��o de dados
    srand((unsigned)time(NULL));  // Inicializa a semente do gerador de n�meros aleat�rios

    // Coleta de dados do usu�rio
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
    scanf("%ld", &Conta.rg);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu CPF: ");
    scanf("%ld", &Conta.cpf);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu telefone: ");
    scanf("%ld", &Conta.telefone);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite sua senha: ");
    scanf("%ld", &Conta.senha);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    printf("Digite seu salario: ");
    scanf("%ld", &Conta.salario);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    // Gera um c�digo de conta aleat�rio
    Conta.codigo_conta = rand();
    Conta.saldo = 0.0;  // Inicializa o saldo da conta como 0.0

    // Verifica se o arquivo foi aberto corretamente
    if (novaConta == NULL) {
        printf("\nArquivo nao encontrado!!\n");
    } else {
        // Escreve os dados da nova conta no arquivo
        fprintf(novaConta, "%s %s %s %ld %ld %ld %ld %ld %ld %.2f\n",
                Conta.Onome, Conta.email, Conta.emprego, Conta.rg, Conta.cpf,
                Conta.telefone, Conta.senha, Conta.salario, Conta.codigo_conta, Conta.saldo);
        fclose(novaConta);  // Fecha o arquivo
    }
}

// Fun��o para fazer login na conta
void loginConta(const char *url) {
    system("cls || clear");  // Limpa a tela do console
    FILE *logar;
    logar = fopen(url, "r");  // Abre o arquivo para leitura
    char linha[300], email[50];
    long int senha;
    int autenticado = 0;
    conta Conta;

    // Solicita os dados de login do usu�rio
    printf("E-mail: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove o caracter de nova linha \n

    printf("Senha: ");
    scanf("%ld", &senha);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    // Verifica se o arquivo foi aberto corretamente
    if (logar == NULL) {
        printf("\nArquivo nao encontrado!!\n");
    } else {
        // L� cada linha do arquivo
        while (fgets(linha, sizeof(linha), logar) != NULL) {
            // Converte a linha para uma estrutura de conta
            sscanf(linha, "%49s %49s %24s %ld %ld %ld %ld %ld %ld %f",
                   Conta.Onome, Conta.email, Conta.emprego, &Conta.rg, &Conta.cpf,
                   &Conta.telefone, &Conta.senha, &Conta.salario, &Conta.codigo_conta, &Conta.saldo);

            // Verifica se o email e senha correspondem
            if (strcmp(Conta.email, email) == 0 && Conta.senha == senha) {
                autenticado = 1;  // Marca que a autentica��o foi bem-sucedida
                break;
            }
        }
        fclose(logar);  // Fecha o arquivo

        // Se autenticado, chama a fun��o IndexConta, sen�o exibe mensagem de erro
        if (autenticado) {
            IndexConta(url, Conta.Onome, Conta.saldo, Conta.codigo_conta);
        } else {
            printf("E-mail ou senha incorretos.\n");
        }
    }
}

// Fun��o que exibe o menu principal da conta ap�s login
void IndexConta(const char *url, const char *nome, float saldo, long int codigo_conta) {
    system("cls || clear");  // Limpa a tela do console
    int opr;
    do {
        system("cls || clear");  // Limpa a tela do console
        printf("\nSeja Bem-vinda %s!!!\n", nome);  // Sauda��o ao usu�rio
        printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
        printf("+|\t\tBANCO JMS\n");
        printf("+|\n");
        printf("+|\t1. Saldo\n");
        printf("+|\t2. Sacar\n");
        printf("+|\t3. Depositar\n");
        printf("+|\t4. Transferir\n");
        printf("+|\t0. Sair\n");
        printf("+|\n");
        printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\nOperacao = ");
        scanf("%d", &opr);
        getchar(); // Para consumir o '\n' deixado pelo scanf

        // Chama a fun��o apropriada com base na entrada do usu�rio
        switch (opr) {
            case 1:
                printf("Saldo atual: R$ %.2f\n", saldo);
                Sleep(2000);
                break;
            case 2:
                sacar(url, codigo_conta);
                Sleep(800);
                Pagina_interface();
                break;
            case 3:
                depositarConta(url,codigo_conta);
                Sleep(800);
                break;
            case 4:
                transferir(url,codigo_conta);
                Sleep(800);
                break;
            case 0:
                Pagina_interface();
                break;
            default:
                printf("\nOperacao invalida!!!\n");
                break;
        }
    } while (opr != 0);  // Continua exibindo o menu at� que o usu�rio escolha sair
}

// Fun��o para realizar um saque
void sacar(const char *url, long int codigo) {
    system("cls || clear");  // Limpa a tela do console
    float valor;
    char linha[300];
    FILE *arquivo = fopen(url, "r");  // Abre o arquivo original para leitura
    FILE *temp = fopen("temp.txt", "w");  // Cria um arquivo tempor�rio para escrita
    if (arquivo == NULL || temp == NULL) {
        printf("\nArquivo nao encontrado\n");
        return;
    }

    conta Conta;
    printf("Valor do saque: ");
    scanf("%f", &valor);
    getchar();  // Para consumir o '\n' deixado pelo scanf

    int contaEncontrada = 0;  // Flag para verificar se a conta foi encontrada

    // L� cada linha do arquivo original
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Converte a linha para uma estrutura de conta
        sscanf(linha, "%49s %49s %24s %ld %ld %ld %ld %ld %ld %f", Conta.Onome, Conta.email, Conta.emprego, &Conta.rg, &Conta.cpf,
               &Conta.telefone, &Conta.senha, &Conta.salario, &Conta.codigo_conta, &Conta.saldo);

        // Verifica se o c�digo da conta corresponde ao c�digo passado
        if (codigo == Conta.codigo_conta) {
            contaEncontrada = 1;  // Marca que a conta foi encontrada
            if (valor > Conta.saldo) {
                printf("Saldo insuficiente\n");
            } else {
                Conta.saldo -= valor;  // Deduz o valor do saldo
                printf("Saque realizado com sucesso. Saldo atual: R$ %.2f\n", Conta.saldo);
            }
        }

        // Escreve os dados (atualizados ou n�o) no arquivo tempor�rio
        fprintf(temp, "%s %s %s %ld %ld %ld %ld %ld %ld %.2f\n",
                Conta.Onome, Conta.email, Conta.emprego, Conta.rg, Conta.cpf,
                Conta.telefone, Conta.senha, Conta.salario, Conta.codigo_conta, Conta.saldo);
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temp);

    // Se a conta foi encontrada e atualizada, substitui o arquivo original pelo tempor�rio
    if (contaEncontrada) {
        remove(url); // ele apaga o arquivo "Dados.txt" que � o antigo;
        rename("temp.txt", url); //Ele renomeia o arquivo "temp.txt" pelo nome armazenado na variavel url = "Dados.txt", fazendo assim uma atualiza��o dos dados
    } else {
        remove("temp.txt");  // Se a conta n�o foi encontrada, remove o tempor�rio
        printf("Conta n�o encontrada.\n");
    }
}
void depositarConta(const char *url,long int codigo){
    system("cls || clear");
    float valor;
    FILE *arquivo = fopen(url,"r");
    FILE *temp = fopen("temp.txt","w");
    char linha[300];
    if (arquivo == NULL || temp == NULL) {
        printf("\nArquivo nao encontrado\n");
        return;
    }
    conta Conta;
    printf("Valor do Deposito: ");
    scanf("%f", &valor);
    getchar();  // Para consumir o '\n' deixado pelo scanf
    int encontrada = 0;
    while((fgets(linha,sizeof(linha),arquivo))!=NULL){
        sscanf(linha, "%49s %49s %24s %ld %ld %ld %ld %ld %ld %f", Conta.Onome, Conta.email, Conta.emprego, &Conta.rg, &Conta.cpf,
               &Conta.telefone, &Conta.senha, &Conta.salario, &Conta.codigo_conta, &Conta.saldo);
        if(codigo == Conta.codigo_conta){
            encontrada = 1;  // Marca que a conta foi encontrada
            Conta.saldo+=valor;
            printf("\nDepositado!\n");
        }
        fprintf(temp, "%s %s %s %ld %ld %ld %ld %ld %ld %.2f\n",
                Conta.Onome, Conta.email, Conta.emprego, Conta.rg, Conta.cpf,
                Conta.telefone, Conta.senha, Conta.salario, Conta.codigo_conta, Conta.saldo);
    }
    fclose(arquivo);
    fclose(temp);
    if(encontrada){
        remove(url); // ele apaga o arquivo "Dados.txt" que � o antigo;
        rename("temp.txt", url); //Ele renomeia o arquivo "temp.txt" pelo nome armazenado na variavel url = "Dados.txt", fazendo assim uma atualiza��o dos dados
    } else {
        remove("temp.txt");  // Se a conta n�o foi encontrada, remove o tempor�rio
        printf("Conta n�o encontrada.\n");
    }
}
void transferir(const char *url,long int codigo){
    system("cls || clear");
    float valor;
    FILE *arquivo = fopen(url,"r");
    FILE *temp = fopen("temp.txt","w");
    char linha[300],nome[50];
    long int codigo_transferir,cpf;

    if (arquivo == NULL || temp == NULL) {
        printf("\nArquivo nao encontrado\n");
        return;
    }

    conta Conta;

    printf("Digite o nome da pessoa que deseja transferir o dinheiro: ");
    scanf("%s",&nome);
    printf("CPF: ");
    scanf("%ld",&cpf);
    printf("Codigo da conta da pessoa que deseja transferir: ");
    scanf("%ld",&codigo_transferir);
    printf("Valor da transferencia: ");
    scanf("%f", &valor);
    getchar();  // Para consumir o '\n' deixado pelo scanf
    int encontrada = 0;
    while((fgets(linha,sizeof(linha),arquivo))!=NULL){
        sscanf(linha, "%49s %49s %24s %ld %ld %ld %ld %ld %ld %f", Conta.Onome, Conta.email, Conta.emprego, &Conta.rg, &Conta.cpf,
               &Conta.telefone, &Conta.senha, &Conta.salario, &Conta.codigo_conta, &Conta.saldo);
        if(codigo == Conta.codigo_conta){ //primeiro vai ser descontado o valor da conta em que a transferencia esta sendo feita
            encontrada = 1;  // Marca que a conta foi encontrada
            Conta.saldo-=valor;
        }
        if(codigo_transferir == Conta.codigo_conta){//Depois eh adicionado o valor transferido na conta de destino
                encontrada = 1;
                Conta.saldo+=valor;
        }
        fprintf(temp, "%s %s %s %ld %ld %ld %ld %ld %ld %.2f\n",
                Conta.Onome, Conta.email, Conta.emprego, Conta.rg, Conta.cpf,
                Conta.telefone, Conta.senha, Conta.salario, Conta.codigo_conta, Conta.saldo);
    }
    fclose(arquivo);
    fclose(temp);
    if(encontrada){
        remove(url); // ele apaga o arquivo "Dados.txt" que � o antigo;
        rename("temp.txt", url); //Ele renomeia o arquivo "temp.txt" pelo nome armazenado na variavel url = "Dados.txt", fazendo assim uma atualiza��o dos dados
    } else {
        remove("temp.txt");  // Se a conta n�o foi encontrada, remove o tempor�rio
        printf("Conta n�o encontrada.\n");
    }




}
