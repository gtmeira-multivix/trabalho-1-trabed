#ifndef _TOKENIZACAO_H
#define _TOKENIZACAO_H

typedef enum tipo_token {
  NUMERO, OPERADOR, OPENPRT, CLOSEPRT
} TipoToken;

typedef enum tipo_operador {
  SOMA, SUB, MULT, DIV, POT, FIM, ERRO
} TipoOperador;

typedef enum associatividade {
  ESQUERDA, DIREITA
} Associatividade;

typedef struct token {
  TipoToken tipo;
  TipoOperador operador;
  Associatividade associatividade;
  double valor;
  int precedencia;
} Token;

/*
 * Cria um token do tipo n�mero, armazenando o valor passado
 * como par�metro.
 */
Token token_criar_numero(double valor);

/*
 * L� o pr�ximo token a partir da entrada padr�o.
 */
Token token_proximo();

/*
 * Imprime o token na sa�da padr�o.
 */
void token_imprimir(Token t);

#endif
