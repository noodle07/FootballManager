#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipa.h"
#include "lerDados.h"
#include "listarEquipas.h"
#include "adicionarEquipa.h"
#include "removerEquipa.h"
#include "editarEquipa.h"
#include "pesquisarEquipa.h"
#include "registarResultado.h"
#include "classificacao.h"
#include "guardarDados.h"

//comando compilar terminal
/* gcc main.c equipa.h adicionarEquipa.c editarEquipa.c guardarDados.c lerDados.c listarEquipas.c pesquisarEquipa.c registarResultado.c removerEquipa.c classificacao.c -o programa */

#define MAX_EQUIPAS 20

int main()
{
    //para tabela de equipas e iterar pelos elementos da estrutura equipa
    int numEquipas = 0; //inicializar a variavel a zero
    //criar array de structs equipas
    Equipa equipas[MAX_EQUIPAS];
    //Inicializar a struct equipa a 0 para nao haver valores indesejados
    memset(&equipas, 0, sizeof(equipas));
   
    //ler os dados das equipas
    lerDados(equipas, &numEquipas); 
    system("cls");//comando cmd/ms-dos que limpa ecra, clear screen
    //Menu do programa
    int opcao = 0;
    do
    { 
        printf("\n========================================\n");
        printf("|         FOOTBALL MANAGER MENU        |\n");
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|         1. Adicionar equipa          |\n");
        printf("|         2. Remover equipa            |\n");
        printf("|         3. Editar equipa             |\n");
        printf("|         4. Listar equipas            |\n");
        printf("|         5. Pesquisar equipa          |\n");
        printf("|         6. Registar resultados       |\n");
        printf("|         7. Tabela de Classificacao   |\n");
        printf("|         8. Guardar e Sair            |\n");
        printf("|                                      |\n");
        printf("|(C)SoccerSoft               1984-1993 |\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) //utilizador escolhe a opcao do programa a usar
        {
            case 1:
                system("cls");
                adicionarEquipa(equipas, &numEquipas); //Adicionar equipas
                break;
            case 2:
                system("cls");
                removerEquipa(equipas, &numEquipas); //Remover equipas
                break;
            case 3:
                system("cls");
                editarEquipa(equipas, numEquipas); //Editar as equipas
                break;   
            case 4:
                system("cls");
                listarEquipas(equipas, numEquipas);//Imprimir Lista de Equipas
                break; 
            case 5:
                system("cls");
                pesquisarEquipa(equipas, numEquipas); //Pesquisar por equipas
                break;
            case 6:
                system("cls");
                registarResultado(equipas, numEquipas); //Registrar resultados do campeonato
                break;
            case 7:
                system("cls");
                classificacao(equipas, numEquipas); //Imprimir Tabela de Classificacoes
                break; 
            case 8:
                system("cls");
                guardarDados(equipas, numEquipas);  //Guardar dados e sair do programa
                printf("\nPrograma terminado.\n");
                return 0;
            default:
                printf("Opcao invalida.\n"); //Se a opcao nao fizer parte do Menu
                break;
        }        
    }
    while(opcao>=1 && opcao <=8); //opcao de 1 a 8, se nao, a opcao é invalida  
}