#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipa.h"
#include "listarEquipas.h"

void pesquisarEquipa(Equipa *equipas, int numEquipas){
    char nome_ou_local_Equipa[MAX_STR];
    int i;
    fflush(stdin);
    listarEquipas(equipas, numEquipas);

    //pesquisar pelo nome ou equipa
    printf("\nDigita o nome ou a localidade da equipa: ");
    fgets(nome_ou_local_Equipa, MAX_STR , stdin);
    nome_ou_local_Equipa[strcspn(nome_ou_local_Equipa, "\r\n")] = 0;
    
    for (i = 0; i < numEquipas; i++) {
        if (strcmp(equipas[i].nome, nome_ou_local_Equipa) == 0 || strcmp(equipas[i].localidade, nome_ou_local_Equipa) == 0) {
            system("cls");
            printf("\nNome da Equipa: %s\n", equipas[i].nome);
            printf("Localidade: %s\n", equipas[i].localidade);
            printf("Vitorias: %d\n", equipas[i].vitorias);
            printf("Derrotas: %d\n", equipas[i].derrotas);
            printf("Empates: %d\n", equipas[i].empates);
            printf("Golos Marcados: %d\n", equipas[i].marcados);
            printf("Golos Sofridos: %d\n", equipas[i].sofridos);
            return;
        }
    }
    
    printf("A equipa %s nao foi encontrada.\n", nome_ou_local_Equipa);
}