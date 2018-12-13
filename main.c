#include <stdio.h>
#include <math.h>
#include "pilha.h"
#include "fila.h"
#include "tokenizacao.h"
#include "string.h"

int main() 
{
char opcaoMenu[100];
	do {
	system ("cls");
    Fila *filaT = fila_criar();
    Fila *filaSaida = fila_criar();
    Pilha *pilhaOp = pilha_criar();
    Pilha *pilhaCalc = pilha_criar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n                              # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n");
	printf("                              # # # # #   C A L C U L A D O R A    R P N    # # # # #\n\n");
	printf("                              # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n\n\n");
	printf(" Digite uma expressao matematica: ");
	Token t = token_proximo();
	
	while(t.tipo != FIM && t.tipo != ERRO) {fila_add(filaT, t);
		t = token_proximo();}
    Token tmpToken;
    Token cima;
    cima.precedencia = 0;
    while(!fila_vazia(filaT))	{ 
        tmpToken = fila_remover(filaT);
        switch(tmpToken.tipo){
            case NUMERO:
                fila_add(filaSaida, tmpToken);
                break;
            case OPERADOR:
                while((cima.precedencia > tmpToken.precedencia || (cima.precedencia == tmpToken.precedencia && cima.associatividade == ESQUERDA)) && cima.tipo != OPENPRT)
				{fila_add(filaSaida, pilha_pop(pilhaOp));
                    if(pilha_vazia(pilhaOp))
					{cima.precedencia = 0;
                        continue;}
                    cima = pilha_primeiro(pilhaOp);}
                pilha_push(pilhaOp, tmpToken);
                cima = pilha_primeiro(pilhaOp);
                break;
            case OPENPRT:
                pilha_push(pilhaOp, tmpToken);
                cima = pilha_primeiro(pilhaOp);
                break;
            case CLOSEPRT:
                if (pilha_vazia(pilhaOp) && fila_vazia(filaT)){
                    printf("\n ### Expressao invalida.\n");
                    return 0;}
                while (cima.tipo != OPENPRT)
				{fila_add(filaSaida, pilha_pop(pilhaOp));
                    cima = pilha_primeiro(pilhaOp);
                    if (pilha_vazia(pilhaOp))
					{printf("\n ### Expressao invalida.\n");
                        return 0;}
                }
                pilha_pop(pilhaOp);
                break;
            default:
                printf("\n ### Expressao invalida.\n");}
    } while(!pilha_vazia(pilhaOp))
	{fila_add(filaSaida, pilha_pop(pilhaOp));}
    fila_destruir(filaT);
    pilha_destruir(pilhaOp);

    printf("\n\n Expressao dos caracteres em RPN: ");
    fila_impressao(filaSaida);

    while(!fila_vazia(filaSaida))
	{
        tmpToken = fila_remover(filaSaida);
        if(tmpToken.tipo == NUMERO)
		{
            pilha_push(pilhaCalc, tmpToken);
        }
        else{
            float res, num1, num2;
            num2 = pilha_pop(pilhaCalc).valor;
            num1 = pilha_pop(pilhaCalc).valor;

            switch(tmpToken.operador)
			{
                case SOMA:
                    res = num1 + num2;
                    pilha_push(pilhaCalc, token_criar_numero(res));
                    break;
                case SUB:
                    res = num1 - num2;
                    pilha_push(pilhaCalc, token_criar_numero(res));
                    break;
                case DIV:
                    res = num1 / num2;
                    pilha_push(pilhaCalc, token_criar_numero(res));
                    break;
                case MULT:
                    res = num1 * num2;
                    pilha_push(pilhaCalc, token_criar_numero(res));
                    break;
                case POT:
                    res = pow(num1, num2);
                    pilha_push(pilhaCalc, token_criar_numero(res));
                    break;
                default:
                    printf("\n ### Erro ao calcular expressao.\n");
                    return 0;
            }
        }
    }
    printf("\n\n\n Resultado do calculo: %.4f\n\n", pilha_pop(pilhaCalc).valor);
    printf("\n Digite 'S' para sair ou qualquer digito para calcular novamente: ");
	gets(opcaoMenu);
	} while ((opcaoMenu[0] != 'S' && opcaoMenu[0] != 's') || strlen(opcaoMenu)>1);
		
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                     ENCERRANDO...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
		
	return 0;
}

