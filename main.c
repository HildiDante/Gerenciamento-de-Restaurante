#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>


#define TITULO_OPCAO1 "  ADICIONAR RESERVA "
#define TITULO_OPCAO2 "  EXCLUIR RESERVA "
#define TITULO_OPCAO3 "  LISTAR RESERVA MARCADA "
#define TITULO_OPCAO4 "  BUSCAR RESERVA "
#define TITULO_OPCAO5 "  EDITAR CADASTRO DE RESERVA "
#define TITULO_OPCAO6 "  CONSULTAR RESERVA PARA UM CLIENTE "
#define TITULO_OPCAO7 "  ESCOLHER RESTAURANTE"
#define TITULO_OPCAO8 "  SAIR "


#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'


/**
* Funcao: LimpaBuffer()
* Descricao: Le e descarta caracteres encontrados na entrada
* Parametros: Nenhum
* Retorno: Nada
**/
void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();//ler e ver se algum caratere não desejado, caso não seja desejado mostra-se o erro.
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/**
* Função: LeOpcao()
* Descrição: Lê e valida a opção digitada pelo usuário
* Parâmetros:
*   menorValor (entrada): o menor valor válido
*   maiorValor (entrada): o maior valor válido
* Retorno: A opção lida é validada
**/
int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}

void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i; //ela que vai apresentar o menu que usa-se com as implementações la em cima
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menorOpcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main(void) {
    unsigned char op; // variavel para armazenar a opção digitada pelo usuario
    unsigned int saida = 0; //variavel aux para sair do programa

    do {
        ApresentaMenu(N_OPCOES, OPCAO1, TITULO_OPCAO1, TITULO_OPCAO2,
		              TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, 
					  TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8);
                      //falta adicionar o resto do menu
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                Beep(1000,500); /* Emite um beep */
                Restaurante h;
                printf("insira os dados do Restaurante(Nome, Localização e Avaliação:\n");
                LerCadastro(&h);
                inserirInicio(&lista, h);
                break;

            case OPCAO2:
                Beep(1000,500);
                //chamada da função 
                break;

            case OPCAO3:
                Beep(1000,500);
                //chamada da função 
                break;

            case OPCAO4:
                Beep(1000,500);
             	 //chamada da função 
                break;
            case OPCAO5:
                Beep(1000,500);
                //chamada da função
                break;
            case OPCAO6:
                Beep(1000,500);
                //chamada da função
                break;
            
			case OPCAO7:
                Beep(1000,500);
                //chamada da função
                break;
            
            case OPCAO8:
                Beep(1000,500);
                saida = 1;
                printf("Obrigado por usar este programa.");
                break;
                

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    
	return 0;
}