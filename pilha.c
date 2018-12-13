#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
  Token token;
  struct no *prox;
} No;

struct pilha {
  No *comeco;
};

Pilha* pilha_criar() {
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->comeco = NULL;
    return p;}


void pilha_push(Pilha *p, Token t) {
	No *tmp = (No *)malloc(sizeof(No));
    tmp->token = t;
    tmp->prox = p->comeco;
    p->comeco = tmp;}


Token pilha_pop(Pilha *p) {
    if(p->comeco == NULL){
        return;}
	Token tmpToken = p->comeco->token;
    No *tmp = p->comeco;
    p->comeco = p->comeco->prox;
    free(tmp);
    return(tmpToken);}


Token pilha_comeco(Pilha *p) {
    if(p->comeco == NULL){
        return;}
    Token tmpToken = p->comeco->token;
	return(tmpToken);}


int pilha_vazia(Pilha *p) {
	if (p->comeco == NULL){
        return(1);}
    else{
        return(0);}}


void pilha_destruir(Pilha *p) {
	No *tmp = p->comeco;
    while(tmp != NULL){
        No *excluir = tmp;
        tmp = tmp->prox;
        free(excluir);}
        free(p);}


void pilha_imprimir(Pilha *p) {
	if(p->comeco == NULL){
        return;}
    No *tmp = p->comeco;
    while(tmp != NULL){
        Token tmpToken = tmp->token;
        token_imprimir(tmpToken);
        tmp = tmp->prox;}}

