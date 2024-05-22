typedef struct
{
    char modelo[30];
    float potenciaMotor;
    int anoFabricacao,
        numPortas;
}CARRO;

void Exibe(CARRO car)
{
    printf("\n\tExibindo carro\n");
    printf("Modelo: %s\n", car.modelo);
    printf("Motor: %.1f\n", car.potenciaMotor);
    printf("Ano: %dn", car.anoFabricacao);
    printf("%d portas\n", car.numPortas);
}

void Preenche(CARRO *car)
{
    printf("Modelo do carro: ");
    gets( car->modelo );

    printf("Motor: ");
    scanf("%f", &car->potenciaMotor);

    printf("Ano: ");
    scanf("%d", &car->anoFabricacao);

    printf("Numero de portas: ");
    scanf("%d", &car->numPortas);
}

int main(void)
{
    system("cls || clear");
    CARRO fusca;
    Preenche(&fusca);
    Exibe(fusca);

    return 0;
}
