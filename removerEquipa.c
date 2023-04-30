#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipa.h"
#include "removerEquipa.h"
#include "listarEquipas.h"
#include "guardarDados.h"

void removerEquipa(Equipa* equipas, int *numEquipas) {
    char nomeEquipa[MAX_STR];
    int i, j;

    listarEquipas(equipas, *numEquipas);

    fflush(stdin);
    printf("\nInsira o nome da equipa que deseja remover: ");
    fgets(nomeEquipa, MAX_STR , stdin);
    nomeEquipa[strcspn(nomeEquipa, "\r\n")] = 0;

    for(i = 0; i < *numEquipas; i++){ //iterar por todas as equipas

        //a funcao strcmp() compara duas strings
        //Se as duas strings sao iguais, o valor retornado pela funcao strcmp() é 0 (zero).
        //comparar nome escrito no input com os nomes das equipas
        if(strcmp(equipas[i].nome, nomeEquipa) == 0){
            for(j = i; j < *numEquipas - 1; j++){
                //move cada elemento do vetor uma posicao para tras sobreescrevendo o elemento anterior
                equipas[j] = equipas[j+1];
            }
            //equipas[j+1].marcados = 0;
            //equipas[j+1].sofridos = 0;
            //decrementar a var numEquipas, removendo da "lista" a equipa, refletindo a eleminacao do elemento
            (*numEquipas)--;

            system("cls");
            printf("A equipa %s foi removida com sucesso.", nomeEquipa);
            
            guardarDados(equipas, *numEquipas);
            listarEquipas(equipas, *numEquipas); //listar a "nova lista" de equipas, porque uma equipa foi eliminada
            return; //voltar para o programa principal
        }
    }
    printf("A equipa %s nao foi encontrada.\n", nomeEquipa);
}