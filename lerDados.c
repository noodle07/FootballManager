#include <stdio.h>
#include <stdlib.h>
#include "Equipa.h"

void lerDados(Equipa *equipas, int *numEquipas)
{
    //abrir ficheiro com fopen() em modo "read"
    FILE *file = fopen("equipas.csv", "r");
    if (file == NULL) //se nao for aberto
    {
        printf("Erro ao abrir o fcheiro.\n");
        return;
    }

    char line[MAX_STR];//array de chars para onde as strings sao copiadas e armazenadas

    for(;fgets(line, sizeof(line), file); (*numEquipas)++ ){
        /* %[^,] indica que o proximo valor a ser lido é uma string que pode conter
        qualquer caracter execto virgula (,) e (^) significa que o conjunto de caracteres a serem lidos deve
        ser o oposto da virgula.  */
        //sscanf é usado para ler valores de uma string formatada e armazenar em variaveis especificas
        //sscanf(source, format, storage)
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%d,%d", 
            equipas[*numEquipas].nome,
            equipas[*numEquipas].localidade,
            &equipas[*numEquipas].vitorias,
            &equipas[*numEquipas].derrotas,
            &equipas[*numEquipas].empates,
            &equipas[*numEquipas].marcados,
            &equipas[*numEquipas].sofridos);

    }
    //fechar ficheiro
    fclose(file);
}