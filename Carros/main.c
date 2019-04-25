#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
#include "carro.h"

int main(){
	setbuf(stdin, NULL);

	int choice;
	int n=0;
	TAD* cofo;

	do{
    	MenuDisplay();
    	scanf("%d", &choice);

    	switch(choice){
        	case 1:
        	///Cria um cofo vazio
	            printf("Quantas carros deseja cadastrar? \n");
	            scanf("%d", &n);
	            cofo = tadCreate(n); ///Cria cofo
	            if(cofo!=NULL){
	            	printf("Cofo criado\n");
	            }          
	            break;
	        case 2:
	            n = carStorage(cofo); ///Inseri o carro no cofo
	            if(n){
	            	printf("Carro inserido com sucesso");
	            }          
	            break;
	        case 3:
	            n = carSearch(cofo); ///Procura um carro no cofo e imprime
	            break;
	        case 4:
	            n = carRemove(cofo); ///Remove um carro do cofo
	            break;
	        case 5:
				if(cofo != NULL){
					tadPrint(cofo, carPrinter);	
				}else{
					print("Cofo vazio");
				}	        
	              ///Imprime todos os carros do TAD
	            break;
	        case 6:
	        ///Destroi cofo
	            n = tadDestroy(cofo);            
	            if(n){
	            	printf("Cofo destruido\n");
	            	cofo = NULL;
	            }
	            break;
	        case 7:
	            return 0;

	        default:
	          printf("DESEJA SAIR? PRESSIONE (7)\n");
	      };
	      printf("\n");
  	}while(choice != 7);
}