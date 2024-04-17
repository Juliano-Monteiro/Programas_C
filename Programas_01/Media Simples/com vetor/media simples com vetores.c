// media simples usando vetores
#include <stdio.h>

int main()
{
    float n[3];
    int indice;
    for(indice=0;indice<=1;indice++){
        printf("Nota %d: ",indice+1);
        scanf("%f",&n[indice]);
    }
    n[2]=(n[0]+n[1])/2;
    printf("A media eh: %.2f",n[2]);

    return 0;
}
