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

Token token_criar_numero(double valor);

Token token_proximo();

void token_imprimir(Token t);


