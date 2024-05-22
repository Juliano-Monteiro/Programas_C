#include <stdio.h>
#include <string.h>
#include "biblioteca_para_jogo.h"

char str[] = "PARALELEPIPEDO"; //palavra
char array[];

int erros = 0,                 //conta os erros
    numL = 0,                  //conta o numero de letras
    fim=1;                     //determina o fim da execoção

void entradas(){
    char letra;
    printf("Digite a letra: ");
    scanf("%c",&letra);
    fflush(stdin);
    letra = uper(letra);                          //Transforma a letra em maiusculo
    char *ptr = strchr(str,letra);                //verifica se tem esse caracter na palavra
    analise(ptr,letra);

}
void analise(char *ptr,char letra){
    int posicao=0,cont=0;
    cont = quantLetra(str,letra);                //Saber quantas vezes ele aparece
    int i=0,j = 0,local[cont];                   //esse vetor armazena os locais das aparições dos caracteres
    for(i=0;str[i] != '\0';i++){                 //armazenando os locais  e encrementando o numero de letras descobertas
        if(letra == str[i]){
            local[j] = i;
            j++;
            numL++;
        }
    }

    if(ptr!=NULL){                               //se a letra existe
        humano(erros);
        for(i = 0; i<cont;i++){                  //ele armazena as letras em seus devidos locais
            posicao = local[i];
            array[posicao] = letra;
        }
    }
    else{
        erros++;
        printf("NEW = %d\n",erros);
        humano(erros);
    }
    exibir();
}
void exibir(){
    printf("Palavra: %s\n",array);
}
void humano(int erro){      //exibe o boneco e a forca
    system("cls || clear");
    printf("Erros  = %d/5\n",erro);
    if(erro<1){
        printf("\t__________\n");
        printf("\t|\t |\n");
        printf("\t|\t\n");
        printf("\t|\n");
        printf("\t|\n");
        printf("\t|\n");
        printf("=================================\n");
    }
    else{
        printf("\t__________\n");
        printf("\t|\t |\n");
        printf("\t|\t O\n");
        if(erros==2){
            printf("\t|\t |\n");
        }
        else if(erros==3){
            printf("\t|\t/|\n");
        }
        else if(erros ==4){
            printf("\t|\t/|\\\n");
        }
        else if(erros>4){
            printf("\t|\t/|\\\n");
            printf("\t|       / \\\n");
            fim = 2;
        }
        printf("\t|\n");
        printf("\t|\n");
        printf("\t|\n");
        printf("=================================\n");
        if(fim == 2){
            printf("\nFim do jogo -  | P E R D E U |\n\n");
            fim = 0;
        }
    }
}

int main(){
    zerandoArray(str,array); // imposrtado da biblioteca, ele zera o array, aloca "_" para todas as posições e da um printf para que exiba o array

    int n1,n2;
    while(fim){
            n1 = numL;              //armazena o numero de letras já achados
            n2 = strlen(str);       //armazena a quantidade de letras a palavra tem
            if(n1<n2){
                fim = 1;
                entradas();
            }
            else{
                printf("\nFim do jogo -  | V E N C E U |\n\n");
                fim = 0;
            }


    }
}
