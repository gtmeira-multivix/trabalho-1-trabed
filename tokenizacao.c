#include <stdio.h>
#include <ctype.h>
#include "tokenizacao.h"

Token token_proximo() {
  Token t;
  
  //Obter pr�imo caractere da entrada:
  int digito = getchar();

  //Avan�ar enquanto houver espa�os vazios na entrada:
  while(isspace(digito) && digito != '\n') {
    digito = getchar();
  }
  
  //Se chegamos ao fim da linha, nossa express�o terminou:
  if(digito == '\n') {
    t.tipo = FIM;
    return t;
  }
  
  if(isdigit(digito)) {
    //Se for n�mero, vamos colocar o caractere de volta na stream, para ler com scanf:
    ungetc(digito, stdin);
    double valor;
    scanf(" %lf", &valor);
    t.tipo = NUMERO;
    t.valor = valor;
    return t;
  } else {
    //Se n�o for n�mero, � operador ou par�nteses:
    switch(digito) {
      case '+':
        t.tipo = OPERADOR;
        t.operador = SOMA;
        t.precedencia = 1;
        t.associatividade = ESQUERDA;
        break;
      
      case '-':
        t.tipo = OPERADOR;
        t.operador = SUB;
        t.precedencia = 1;
        t.associatividade = ESQUERDA;
        break;
      
      case '*':
        t.tipo = OPERADOR;
        t.operador = MULT;
        t.precedencia = 2;
        t.associatividade = ESQUERDA;
        break;
      
      case '/':
        t.tipo = OPERADOR;
        t.operador = DIV;
        t.precedencia = 2;
        t.associatividade = ESQUERDA;
        break;
      
      case '^':
        t.tipo = OPERADOR;
        t.operador = POT;
        t.precedencia = 3;
        t.associatividade = DIREITA;
        break;
      
      case '(':
        t.tipo = OPENPRT;
        break;
      
      case ')':
        t.tipo = CLOSEPRT;
        break;
      
      default:
        t.tipo = ERRO;
        break;
    }
    
    return t;
  }
}

void token_imprimir(Token t) {
  switch(t.tipo) {
    case OPERADOR:
      switch(t.operador) {
        case SOMA:
          printf("+ ");
          break;
        
        case SUB:
          printf("- ");
          break;
        
        case MULT:
          printf("* ");
          break;
        
        case DIV:
          printf("/ ");
          break;
        
        case POT:
          printf("^ ");
          break;
      }
      break;
    
    case OPENPRT:
      printf("( ");
      break;
    
    case CLOSEPRT:
      printf(") ");
      break;
    
    case NUMERO:
      printf("%.2lf ", t.valor);
      break;
    
    case FIM:
      printf("[Fim]\n");
      break;
    
    case ERRO:
      printf("[Erro!]\n");
      break;
  }
}

Token token_criar_numero(double valor) {
  Token t;
  t.tipo = NUMERO;
  t.valor = valor;
  return t;
}
