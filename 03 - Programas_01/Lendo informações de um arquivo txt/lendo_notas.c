#include <stdio.h>
int main (){
    char url[] = "notasv2.txt";
    char nome[25];
    float n1,n2,n3;
    FILE *arq;
    arq = fopen(url,"r");
    if(arq == NULL){
        printf("Nao foi possivel acessar o arquivo");
    }
    else{
        while((fscanf(arq,"%s %f %f %f \n",&nome,&n1,&n2,&n3))!=EOF){
            printf("----- %s -----\nMedia = %.2f\n",nome,((n1+n2+n3)/3));
        }
    }
    fclose(arq);
}
