#include <stdio.h>
#include <stdlib.h>
#include "Equipa.h"

void guardarDados(Equipa *equipas, int numEquipas)
{
    FILE *file = fopen("equipas.csv", "w");

    if (file == NULL)
    {
        printf("Erro ao abrir o ficheiro para escrita.\n");
        exit(0);
    }

    for (int i = 0; i < numEquipas; i++)
    {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d\n",
            equipas[i].nome,
            equipas[i].localidade,
            equipas[i].vitorias,
            equipas[i].derrotas,
            equipas[i].empates,
            equipas[i].marcados,
            equipas[i].sofridos);
    }

    printf("\nDados gravados com sucesso.\n");

    fclose(file);
}
