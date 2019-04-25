#ifndef CARRO_C_INCLUDED
#define CARRO_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"
#include "TAD.h"



void MenuDisplay(){
	printf("\n");
	printf("1 - Criar um cofo\n");
	printf("2 - Inserir um carro em um cofo\n");
	printf("3 - Procurar um carro no cofo\n");
	printf("4 - Remover um carro do cofo\n");
	printf("5 - Listar todos os carros do cofo\n");
	printf("6 - Destruir o cofo\n");
	printf("7 - Sair do programa");
	printf("\n");
}

void carPrinter(void *a){
	if(a != NULL){
		CARRO* car;
		car = (CARRO*)a;
		printf("\n");
	    printf("Marca: %s\n", car->marca);
	    printf("Potencia: %d\n", car->potencia);
	    printf("Numero de portas: %d\n",car->numPortas);
	    printf("Preco(R$): %f\n", car->price);
	    printf("Placa: %ld\n", car->placa);
	    printf("\n");
  }
}

int cmpMarca(void* a, void* b){
	char *strA;
	CARRO *carB;
	strA = (char *)malloc(sizeof(char*)*100);
	strA = (char *)a;
	carB = (CARRO *)b;
	if(strcmp(strA, carB->marca)==0){
		return TRUE;
	}
	return FALSE;
}

int cmpPlaca(void* a, void* b){
	long int nA;
	CARRO *carB;
	nA = (long int)a;
	carB = (CARRO *)b;
	if(carB->placa == nA){
		return TRUE;
	}
	return FALSE;
}


int carStorage(TAD* c){
	int stat = FALSE;
	if(c != NULL){
		CARRO* car = (CARRO *)malloc(sizeof(CARRO));
		if(car != NULL){
			if(c->nelms < c->maxElms){
				car->marca = (char*)malloc(sizeof(char)*100);
				if(car->marca != NULL){
					printf("Insira marca do carro:\n");
					scanf("%s", car->marca);
					printf("Insira potencia do carro:\n");
					scanf("%d", &(car->potencia));
					printf("Insira o numero de portas do carro:\n");
					scanf("%d", &(car->numPortas));
					printf("Insira preco do carro:\n");
					scanf("%f", &(car->price));
					printf("Insira placa do carro:\n");
					scanf("%ld", &(car->placa));
				}
				stat = tadInsert(c, (void*) car);
			}
		}
	}
	return stat;
}

int carSearch(TAD* c){
	if((c != NULL) && (c->nelms > 0)){
		int i;
		long int plate;
		char* brand;
		void* elm = NULL;
		brand = (char*)malloc(sizeof(char*)*100);
		printf("Deseja procurar o carro por:\n");
		printf("[1] - Marca  |  ");
		printf("[2] - Placa\n");
		scanf("%d", &i);
		if(i==1){
			printf("Insira a marca do carro:\n");
			//fgets(brand, 100, stdin);
			scanf("%s", brand);
			elm = tadQuery(c, (void*)brand,  cmpMarca);
		}else if(i==2){
			printf("Insira a placa do carro:\n");
			scanf("%ld", &plate);
			elm = tadQuery(c, (void*)plate,  cmpPlaca);

		}else{
			carSearch(c);
		}
		if(elm != NULL){
			carPrinter(elm);
			return TRUE;
		}

	}
	return FALSE;
}

int carRemove(TAD* c){
	if((c != NULL) && (c->nelms > 0)){
		int i=0;
		long int plate;
		char* brand;
		void* elm = NULL;
		brand = (char*)malloc(sizeof(char*)*100);
		printf("Deseja procurar o carro por:\n");
		printf("[1] - Marca  |  ");
		printf("[2] - Placa\n");
		scanf("%d", &i);
		if(i==1){
			printf("Insira a marca do carro:\n");
			scanf("%s", brand);
			elm = tadRemove(c, (void*)brand,  cmpMarca);
		}else if(i==2){
			printf("Insira a placa do carro:\n");
			scanf("%ld", &plate);
			elm = tadRemove(c, (void*)plate,  cmpPlaca);

		}else{
			carRemove(c);
		}
		if(elm != NULL){
			carPrinter(elm);
			return TRUE;
		}
	}
	return FALSE;
}



#endif
