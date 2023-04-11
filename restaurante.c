#include  <stdio.h>
#include  <stdlib.h>
#include "restaurante.h"

struct restaurante{
    char local[100];
    char horaOpen[15];
    char horaClose[15];
    int total_mesa;
    int total_reserva;
};

struct reserva{
    char n_responsavel[100];
    char horaIn[15];
    char horaOut[15];
    int n_mesa;
    float consumo;
    struct reserva *prox;
};

struct fila{
	Reserva *entra;
	Reserva *sai;
};


Fila* fila_cria(void){
	Fila *rv = (Fila*)malloc(sizeof(Fila));
	rv -> entra = NULL;
	rv -> sai = NULL;
	return rv;
}

Restaurante* CriaR(){
	Restaurante *r = (Restaurante*)malloc(sizeof(Restaurante));
	return r;
}

void addAtributos(Restaurante *r){
	
	printf("  ////////////////////////////////////\n");
	printf("  ///   = PREENCHA OS ATRIBUTOS =   ///\n");
	printf("  ////////////////////////////////////\n");
	
	printf("\n  LOCALIZACAO: ");
		scanf(" %[^\n]" ,r->local);
	
	printf("  HORARIO DE ABERTURA: ");
		scanf(" %[^\n]" ,r->horaOpen);
	
	printf("  HORARIO DE FECHAMENTO: ");
		scanf(" %[^\n]" ,r->horaClose);
	
	printf("  TOTAL DE MESAS: ");
		scanf("%d" ,&r->total_mesa);
		
	printf("  TOTAL DE RESERVAS: ");
		scanf(" %d" ,&r->total_reserva);
    
	printf("\n");
	printf("  LOCALIZAÇÃO: %s\n", r->local);
	printf("  HORARIO DE ABERTURA: %s\n", r->horaOpen);
	printf("  HORARIO DE FECHAMENTO: %s\n", r->horaClose);
    printf("  TOTAL DE MESAS: %d\n", r->total_mesa);
    printf("  TOTAL DE RESERVAS: %d\n", r->total_reserva);
	
}

Reserva* CriaRV(){
	Reserva *rvlista = (Reserva*)malloc(sizeof(Reserva));
	return rvlista;
} 
   	    
void addReserva(Fila *rv){
	
	Reserva *novo = (Reserva*)malloc(sizeof(Reserva));
	
	printf("  ////////////////////////////////////\n");
	printf("  ///   = PREENCHA SUA RESERVA =   ///\n");
	printf("  ////////////////////////////////////\n");
	
	printf("\n  NOME DO RESPONSAVEL: ");
		scanf(" %[^\n]" ,novo->n_responsavel);
	
	printf("  HORARIO DE CHEGADA: ");
		scanf(" %[^\n]" ,novo->horaIn);
	
	printf("  HORARIO DE SAIDA: ");
		scanf(" %[^\n]" ,novo->horaOut);
	
	printf("  NUMERO DA MESA: ");
		scanf("%d" ,&novo->n_mesa);
		
	printf("  CONSUMO: ");
		scanf(" %f" ,&novo->consumo);
		
	novo->prox = NULL;
    if(rv -> sai!=NULL)
        rv -> sai -> prox = novo;
    else{
       	rv -> entra = novo;
    }
    rv -> sai = novo;		
}

void delreserva(Fila *rv){
	
	if(rv->entra == NULL){
		printf("  OPCAO NEGADA, LISTA DE RESERVAS VAZIA!\n");
		exit(1);
	}
	else{
		struct reserva *fi = rv -> entra;
		rv -> entra = fi -> prox;
		free(fi);
		
		printf("\n PRIMEIRA RESERVA DA LISTA EXLUIDA! ");
	}
}
void editreserva(Fila *rv){
	int codigo_rv = 0;
	printf("  INSIRA O NUMERO DA MESA: ");
	scanf("%d", &codigo_rv);
	
	printf("  ////////////////////////////////////\n");
	printf("  ///      = ALTERAR RESERVA =     ///\n");
	printf("  ////////////////////////////////////\n");		

	
	Reserva *p;
	for(p = rv -> entra; p!=NULL; p = p -> prox){
		if(p -> n_mesa == codigo_rv){
			printf("\n  RESERVA ENCONTRADA!\n");
			printf("  NOME DO RESPONSAVEL: ");
			scanf(" %[^\n]" ,p->n_responsavel);	
		   	printf("  HORARIO DE CHEGADA: ");
			scanf(" %[^\n]" ,p->horaIn);
    	   	printf("  HORARIO DE SAIDA: ");
    	   	scanf(" %[^\n]" ,p->horaOut);
			printf("  NUMERO DA MESA:");
			scanf("%d" ,&p->n_mesa);
    	   	printf("  CONSUMO: \n");
			scanf(" %f" ,&p->consumo);
		}
	}
}
void buscareserva(Fila *rv){
	int codigo_mesa = 0;
	system("clear||cls");
	printf("\n  INSIRA O NUMERO DA MESA: ");
	scanf("%d", &codigo_mesa);
	
	Reserva *p;
	for(p = rv -> entra; p!=NULL; p = p -> prox){
		if(p -> n_mesa == codigo_mesa){
			
			printf("\n  RESERVA ENCONTRADA!");
			printf("\n  NOME DO RESPONSAVEL: %s\n", p->n_responsavel);
			printf("  HORARIO DE CHEGADA: %s\n", p->horaIn);
			printf("  HORARIO DE SAIDA: %s\n", p->horaOut);
			printf("  NUMERO DA MESA: %d\n", p->n_mesa);
			printf("  CONSUMO: %.2f\n", p->consumo);
		}
	}
}

void listar(Fila *rv){
	Reserva *p;
	
	for(p=rv->entra; p!=NULL; p=p->prox){
		printf("  ////////////////////////////////////\n");
		printf("  ///   = RESERVAS CADASTRADAS =   ///\n");
		printf("  ////////////////////////////////////\n");	
		printf("\n");	
		
		printf("  NOME DO RESPONSAVEL: %s\n", p->n_responsavel);
		printf("  HORARIO DE CHEGADA: %s\n", p->horaIn);
		printf("  HORARIO DE SAIDA: %s\n", p->horaOut);
		printf("  NUMERO DA MESA: %d\n", p->n_mesa);
		printf("  CONSUMO: %.2f\n", p->consumo);	
	}
}

void consultareservas(Restaurante *r, Fila *rv){
	Reserva *p;
	int disponiveis;
	disponiveis = r->total_mesa;
	for(p=rv->entra; p!=NULL; p=p->prox){
			disponiveis--;
		}
	printf("  MESAS DISPONIVEIS: %d\n", disponiveis);
}