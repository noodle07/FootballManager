#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipa.h"
#include "listarEquipas.h"
#include "guardarDados.h"

void adicionarEquipa(Equipa *equipas, int *numEquipas){
    char nomeEquipa[MAX_STR];//armazenar nome equipa
    char localEquipa[MAX_STR];//armazenar localidade

    //funcao que imprimie a lista atual das equipas
    listarEquipas(equipas, *numEquipas);

    //inicializar nova equipe com valores padrão
    equipas[*numEquipas].vitorias = 0;
    equipas[*numEquipas].derrotas = 0;
    equipas[*numEquipas].empates = 0;
    equipas[*numEquipas].marcados = 0;
    equipas[*numEquipas].sofridos = 0;

    //obter o nome da equipa nova a adicionar
    fflush(stdin);//limpar o stdin
    printf("\nDigita o nome da equipa: ");

    //armazenar o nome escrita em stdin para a array char nomeEquipa[]
    fgets(nomeEquipa, MAX_STR , stdin);
    
    //remover os caracteres (\r ou \n) que possam estar presentes no final da string
    //strcspn() procura por qualquer ocorrencia dos caracteres \r ou \n na string nomeEquipa e retorna a posicao desses caracteres
    //nomeEquipa[posicao com \r ou \n] = 0
    nomeEquipa[strcspn(nomeEquipa, "\r\n")] = 0;

    //armazenar a string em nomeEquipa para a var nome da estrutura equipa
    //adicionar a struct equipas os novos dados
    sscanf(nomeEquipa, "%[^\n]", equipas[*numEquipas].nome);

    //o mesmo procedimento de obter o nome da equipa, mas para obter o nome da localidade
    //obter o nome do local da equipa nova a adicionar
    fflush(stdin);
    printf("\nDigita o nome da localidade: ");
    fgets(localEquipa, MAX_STR, stdin);
    localEquipa[strcspn(localEquipa, "\r\n")] = 0;
    sscanf(localEquipa, "%[^\n]", equipas[*numEquipas].localidade);
    
    
    //ajustar o vetor para garantir que não haja espaços vazios no meio
    for(int i = *numEquipas; i > 0; i--){
        if(strcmp(equipas[i].nome, equipas[i-1].nome) < 0){
            Equipa temp = equipas[i];
            equipas[i] = equipas[i-1];
            equipas[i-1] = temp;
        }
    }

    (*numEquipas)++;//prosseguir para a proxima equipa
    
    system("cls");
    printf("Equipa adicionada com sucesso.\n");
    guardarDados(equipas, *numEquipas);
    //imprimir a nova lista atual das equipas
    listarEquipas(equipas, *numEquipas);

}