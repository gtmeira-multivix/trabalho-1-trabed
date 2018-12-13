#define _PILHA_H
#include "tokenizacao.h"

typedef struct pilha Pilha;

Pilha* pilha_criar();

void pilha_push(Pilha *p, Token t);

Token pilha_pop(Pilha *p);

Token pilha_comeco(Pilha *p);

int pilha_vazia(Pilha *p);

void pilha_destruir(Pilha *p);

void pilha_imprimir(Pilha *p);

