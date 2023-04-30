#include <stdio.h>
#include "Equipa.h"
#include "classificacao.h"

void classificacao(Equipa* equipas, int numEquipas){
    printf("\n\t\t\t  Tabela de Classificacao:\n\n");
    printf("Index     Equipa        Vitorias  Derrotas  Empates  Marcados  Sofridos\n\n");

    //print cada elemento da array of structs equipa
    for(int i = 0; i < numEquipas; i++){
        printf("%-8d %-20s %-8d %-8d %-8d %-8d %-8d\n", i+1, equipas[i].nome, equipas[i].vitorias, equipas[i].derrotas, equipas[i].empates, equipas[i].marcados, equipas[i].sofridos);
        printf("------------------------------------------------------------------------\n");
    }
}