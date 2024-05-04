#include <stdio.h>
#include <string.h>
void exibe(int numA,Alunos alunos[]){
    int i;
    for(i=0;i<numA;i++){
        printf("=========================\n+ Nome: %s\t\t+\n+ Nota 1: %.2f\t\t+\n+ Nota 2: %.2f\t\t+\n+ Media: %.2f\t\t+\n=========================\n\n",alunos[i].nome,alunos[i].n1,alunos[i].n2,alunos[i].media);

    }
}
int main()
{
    system("cls || clear");
    int numA;
    printf("Digite quantos alunos deseja registrar: ");
    scanf("%d",&numA);
    typedef struct Aluno{
        char nome[30];
        float n1,n2,media;
    }Alunos;
    Alunos alunos[numA];
    int i;
    for(i=0;i<numA;i++){
        fflush(stdin);
        printf("\nNome do aluno %d: ", i+1);
        gets(alunos[i].nome);
        printf("\nNota 1: ");
        scanf("%f", &alunos[i].n1);
        printf("\nNota 2: ");
        scanf("%f", &alunos[i].n2);
        alunos[i].media = (alunos[i].n1+alunos[i].n2)/2;
    }
    system("cls || clear");
    exibe(numA,alunos[numA]);
    return 0;
}
