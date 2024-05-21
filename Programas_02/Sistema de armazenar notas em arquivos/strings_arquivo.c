#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char url[] = "notas.txt";
    float nota, media = 0.0;
    FILE *arq;

    arq = fopen(url, "w");  // Abre o arquivo no modo de escrita
    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return 1;  // Retorna um valor não zero para indicar erro
    }
    else{
        printf("Primeira Nota: ");
        scanf("%f", &nota);
        fprintf(arq, "Nota [1]: %.2f\n", nota);
        media += nota;

        printf("Segunda Nota: ");
        scanf("%f", &nota);
        fprintf(arq, "Nota [2]: %.2f\n", nota);
        media += nota;

        printf("Terceira Nota: ");
        scanf("%f", &nota);
        fprintf(arq, "Nota [3]: %.2f\n", nota);
        media += nota;

        media /= 3;
        fprintf(arq, "Media = %.2f", media);
    }

    fclose(arq);
    return 0;
}
