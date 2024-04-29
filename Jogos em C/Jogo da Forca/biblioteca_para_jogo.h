char *uper(char caracter){
    int i = 0;
    if(caracter>='a'&&caracter<='z'){
        caracter-=32;
    }
    i++;
    return caracter;
}
void zerandoArray(char *str, char *array){
    for(int i =0;str[i]!='\0';i++){               //Para tirar o lixo
        array[i] = '_';
    }
    printf("%s\n",array);
}
int quantLetra(char *str,char letra){
    int cont=0;
    for(int i =0;str[i]!='\0';i++){              //Para saber quantas vezes esse caracter aparece na palavra
        if(letra == str[i]){
            cont++;
        }
    }
    return cont;
}
