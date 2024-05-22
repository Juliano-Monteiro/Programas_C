#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista
{
    char nome[40];
    struct lista *prox; // Esse elemento serve para apontar para o proximo elemento
}celula;
void exibir();//ele exibe as coisas
void push(char *);//ele é usado para adicionar um novo elemento na lista;
void pop();//serve para remover um elemento da lista
celula *topo = NULL; // temos que criar um ponteiro para apontar sempre para o topo da pilha
int main(){
    int opc;
    char Nome[40];
    do{
        printf("\n\nMenu\n1.Empilhar\n2.Desempilhar\n3.Exibir\n0.Sair\nOPC: ");
        scanf("%d",&opc);
        getchar();
        switch(opc){
        case 1:
            printf("Ensira o que deseja empilhar: ");
            fgets(Nome,sizeof(Nome),stdin);
            push(Nome);
        break;
        case 2:
            pop();
        break;
        case 3:
            exibir();
        break;
        case 0:
                printf("Saindo do programa...\n");
                break;
        default:
            printf("Operacao invalida!\n");
        }
    }while(opc!=0);
}
void push(char *Nome){
    system("cls || clear");
    printf("\n=======EMPILHADO======\n");
    celula *novo = malloc(sizeof(celula));//Aqui é criado um novo ponteiro que recebe um espaço na memoria com o mesmo tamanho que a celula
    strcpy(novo->nome,Nome);//aqui o campo de nome recebe um nome enserido pelo usuario
    novo->prox = topo;//o proximo elemento a ser alocado vai passar a apontar para onde o topo apontava antes
    topo = novo;//e o topo vai apontar para o novo elemento
    printf("\n%sfoi empilhado\n", novo->nome);
    printf("\n======================\n");
}
void pop(){
    system("cls || clear");
    printf("\n=====DESEMPILHADO=====\n");
    if(topo == NULL){ //Se for igual a nulo, então a pilha acabou pois está apontando para o fim
        printf("\n\nPilha vazia");
    }
    else{
        celula *temporario;//Aqui é criado uma variavel temporaria só para armazenar o elemento que o topo esta apontando para ser apagado
        temporario = topo;
        printf("%s",temporario->nome);
        topo = topo->prox;
        free(temporario);
    }
    printf("\n======================\n");
}
void exibir(){
    system("cls || clear");
    int count=0;
    celula *temp;
    temp = topo;
    printf("\n====== LISTA ======\n");
    while(temp!=NULL){
        count++;
        printf("%d.%s",count,temp->nome);
        temp = temp->prox;
    }

    printf("\n===================\n");
}
