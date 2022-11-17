#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "restaurante.h"


typedef struct restaurante{
    char localizacao[100];
    char horario_a[50];
    char horario_f[50];
    int total_m;
    int total_r;
}Restaurante;

struct No {
    Restaurante cadastro;
    struct No *prox;
};

typedef struct lista {
    struct No * inicio;
}Lista;

void LerCadastro(Restaurante *h) {
    scanf("%s %s %s", h->localizacao, h-> horario_a, h->horario_f);
    return;
    }

void inserirInicio (Lista *lista, Restaurante cadastro) {
    struct No * novo = (struct No*) malloc (sizeof(struct No));
    novo->cadastro = cadastro;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}


