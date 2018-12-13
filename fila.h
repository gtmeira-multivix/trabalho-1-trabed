#define _FILA_H
#include "tokenizacao.h"

typedef struct fila Fila;

Fila* fila_criar();

void fila_add(Fila *f, Token t);

Token fila_remover(Fila *f);

int fila_vazia(Fila *f);

void fila_destruir(Fila *f);

void fila_impressao(Fila *f);
