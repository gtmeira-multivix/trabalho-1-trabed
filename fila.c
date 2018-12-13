#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct no {
  Token token;
  struct no *prox;
} No;
typedef struct fila {
  No *comeco;
  No *final;
};


Fila* fila_criar() {
	Fila *f = (Fila*) malloc(sizeof(Fila));
    f->comeco = NULL;
    f->final = NULL;
    return f;}
    
    
void fila_add(Fila *f, Token t) {
	No *tmp = (No *) malloc(sizeof(No));
    tmp->token = t;
    tmp->prox = NULL;
    if(f->final == NULL){
        f->comeco = tmp;
        f->final = tmp;
        return;
    }
    f->final->prox = tmp;
    f->final = tmp;}
    

Token fila_remover(Fila *f) {
    if(f->comeco == NULL){
        printf("A fila esta vazia.");
        return;
    }
    No *tmp;
    tmp = f->comeco;
    f->comeco = f->comeco->prox;
    if(f->comeco == NULL){
        f->final == NULL;
    }
    Token tmpToken;
    tmpToken = tmp->token;
    free(tmp);
    return(tmpToken);}


int fila_vazia(Fila *f) {
	if(f->comeco == NULL){
        return 1;
    }
    else{
        return 0;}}


void fila_destruir(Fila *f) {
	free(f);}


void fila_impressao(Fila *f) {
	No *tmp;
    tmp = f->comeco;
    while(tmp != NULL){
        token_imprimir(tmp->token);
        tmp = tmp->prox;}}
