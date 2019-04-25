#ifndef CARRO_H_INCLUDED
#define CARRO_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include "TAD.h"

//Estrutura de Carros
typedef struct _Carro_ {
	char* marca;
	int potencia;
	int numPortas;
	float price;
	long int placa;
}CARRO;

//Displays menu in terminal
void MenuDisplay();
/*

*/

//Imprime um carro
void carPrinter(void *a);
/*

*/

//Compara duas marcas de carro
int cmpMarca(void* a, void* b);
/*
	retorna se marcas sao iguais
*/

//Compara duas placas de carro
int cmpPlaca(void* a, void* b);
/*
	retorna se placas sao iguais
*/

//Insere um carro no cofo
int carStorage(TAD* c);
/* 
	retorna se carro foi inserido
*/

//Procura um carro no cofo
int carSearch(TAD* c);
/*
	retorna se carro foi encontrado
*/

//Remove um carro do cofo
int carRemove(TAD* c);
/*
	retorna se carro foi removido
*/
#endif