#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipa.h"
#include "listarEquipas.h"
#include "guardarDados.h"

void editarEquipa(Equipa *equipas, int numEquipas){
    
    char nomeEquipa[MAX_STR];
    char localEquipa[MAX_STR];
    int i;

    listarEquipas(equipas, numEquipas);

    fflush(stdin);//limpar stdin
    printf("\nInsira o nome da equipa que deseja editar: ");
    fgets(nomeEquipa, MAX_STR , stdin);
    nomeEquipa[strcspn(nomeEquipa, "\r\n")] = 0;

    for(i = 0; i < numEquipas; i++){
        if (strcmp(equipas[i].nome, nomeEquipa) == 0) {
            printf("Equipas encontrada: %s\n", equipas[i].nome);

            //obter novo nome da equipa
            fflush(stdin);
            printf("\nInsira o novo nome da equipa: ");
            fgets(nomeEquipa, MAX_STR, stdin);
            nomeEquipa[strcspn(nomeEquipa, "\r\n")] = 0;
            
            //obter novo nome do local
            fflush(stdin);
            printf("Insira o nove nome do local da equipa: ");
            fgets(localEquipa, MAX_STR, stdin);

            //modificar
            sscanf(nomeEquipa, "%[^\n]", equipas[i].nome);
            sscanf(localEquipa, "%[^\n]", equipas[i].localidade);
            system("cls");
            printf("A edicao teve sucesso.", nomeEquipa);
            guardarDados(equipas, numEquipas);
            listarEquipas(equipas, numEquipas);
            return;
        }
    }
    printf("A equipa %s nao foi encontrada.\n", nomeEquipa);
}
