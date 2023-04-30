#ifndef EQUIPA
#define EQUIPA

#define MAX_STR 50

typedef struct
{
    char nome[50];
    char localidade[50];
    int vitorias;
    int derrotas;
    int empates;
    int marcados;
    int sofridos;
} Equipa;

#endif