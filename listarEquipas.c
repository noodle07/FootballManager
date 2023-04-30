#include <stdio.h>
#include "Equipa.h"
#include "listarEquipas.h"

void listarEquipas(Equipa* equipas, int numEquipas){
    printf("\n\t  Lista das Equipas:\n\n");
    printf("Index      Equipa          Localidade\n\n");

    //print cada array of structs da struct equipa
    for(int i = 0; i < numEquipas; i++){
        //printf("%d\t%s\t\t%s\n", i, equipas[i].nome, equipas[i].localidade);
        printf("%-8d %-20s %s\n", i+1, equipas[i].nome, equipas[i].localidade);
        printf("-------------------------------------------------\n");
    }
}

