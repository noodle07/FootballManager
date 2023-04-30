#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registarResultado.h"
#include "listarEquipas.h"
#include "guardarDados.h"

void registarResultado(Equipa *equipas, int numEquipas){
    char nomeEquipa1[MAX_STR], nomeEquipa2[MAX_STR];
    int golosMarcados1, golosMarcados2;

    listarEquipas(equipas, numEquipas);

    fflush(stdin);
    printf("\nDigite o nome da primeira equipa: ");
    fgets(nomeEquipa1, MAX_STR , stdin);
    nomeEquipa1[strcspn(nomeEquipa1, "\r\n")] = 0;
    printf("\nDigite o numero de golos marcados pela primeira equipa: ");
    scanf("%d", &golosMarcados1);

    
    fflush(stdin);
    printf("\nDigite o nome da segunda equipa: ");
    fgets(nomeEquipa2, MAX_STR , stdin);
    nomeEquipa2[strcspn(nomeEquipa2, "\r\n")] = 0;
    printf("\nDigite o numero de golos marcados pela segunda equipa: ");
    scanf("%d", &golosMarcados2);


     // Procurar as equipes no array de equipas
   for (int i = 0; i < numEquipas; i++) {
  if (strcmp(equipas[i].nome, nomeEquipa1) == 0) {
    equipas[i].marcados += golosMarcados1;
    equipas[i].sofridos += golosMarcados2;
    if (golosMarcados1 > golosMarcados2) {
      equipas[i].vitorias++;
    } else if (golosMarcados1 < golosMarcados2) {
      equipas[i].derrotas++;
    } else {
      equipas[i].empates++;
    }
    break;
  }
}

for (int i = 0; i < numEquipas; i++) {
  if (strcmp(equipas[i].nome, nomeEquipa2) == 0) {
    equipas[i].marcados += golosMarcados2;
    equipas[i].sofridos += golosMarcados1;

    if (golosMarcados2 > golosMarcados1) {
      equipas[i].vitorias++;
    } else if (golosMarcados2 < golosMarcados1) {
      equipas[i].derrotas++;
    } else {
      equipas[i].empates++;
    }

    break;
  }
}
    system("cls");
    printf("Resultado registado com sucesso.");
    golosMarcados1 = 0;//reset
    golosMarcados2 = 0;
    guardarDados(equipas, numEquipas);
}
