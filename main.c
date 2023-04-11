#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "restaurante.h"


int main(){
	setlocale(LC_ALL,"portuguese");
	
	Restaurante *r;
	r = CriaRV();
    Fila *rv = fila_cria();
    int menu = 1;
    int op;
    
		while(menu==1){
		
		printf("  //////////////////////////////////////////////////\n");
        printf("  ///    === BASTONE DI FERRO RESTAURANT ===     ///\n");
        printf("  //////////////////////////////////////////////////\n");
        printf("  ///                                            ///\n");
		printf("  ///          [0] - RESTAURANTE                 ///\n");       
		printf("  ///          [1] - ADICIONAR RESERVA;          ///\n");
        printf("  ///          [2] - EXCLUIR RESERVA;            ///\n");
        printf("  ///          [3] - LISTAR RESERVAS;            ///\n");
        printf("  ///          [4] - EDITAR RESERVA;             ///\n");
        printf("  ///          [5] - BUSCAR RESERVA;             ///\n");
        printf("  ///          [6] - CONSULTAR RESERVA;          ///\n");
        printf("  ///          [7] - SAIR;                       ///\n");
        printf("  ///                                            ///\n");
        printf("  //////////////////////////////////////////////////\n");
        
        printf("\n  INSIRA A OPÇÃO: ");
        scanf("%d", &op);

		switch(op){
			case 0: 
			system("clear||cls");
			addAtributos(r);
            system("Pause");
            break;	
  
			case 1: 
			system("clear||cls");
			addReserva(rv);
            system("Pause");
            break;

            case 2: 
			system("clear||cls");
			delreserva(rv);     
  	   	    system("Pause");
            break;
            
            case 3: 
			system("clear||cls");
            listar(rv);
            system("Pause");
            break;
        
			case 4: 
			system("clear||cls");
			editreserva(rv);
            system("Pause");
            break;
        
            case 5: 
			system("clear||cls");
            buscareserva(rv);
            system("Pause");
            break;
        
            case 6: 
			system("clear||cls");
            consultareservas(r, rv);
            system("Pause");
            break;
        
			case 7: 
			system("clear||cls");
			printf("  VOCE SAIU DO PROGRAMA!.\n");
			free(rv);
			return 0;
            system("Pause");
            break;
        
        	default:
			printf("  NENHUMA OPCAO SELECIONADA!\n"); 
			system("pause");
        }	
	}
	return 0;
}

