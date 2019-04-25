#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#define TRUE 1
#define FALSE 0


//-----------------TAD--------------------
//Estrutura de um TAD genérico
typedef struct _TAD_ {
	int maxElms;
	int nelms;
	void* *elms;
}TAD;

//Cria um tad
TAD* tadCreate(int n);
/*
	retorna TAD criado||NULL
*/

//Insere um elemento no TAD
int tadInsert(TAD* c, void* elm);
/*
	retorna se elemento foi inserido
*/

//Procura um elemento no TAD
void* tadQuery(TAD* c, void* key, int cmp(void* a, void* b));
/*
	retorna elemento encontrado||NULL
*/

//Remove um elemento do TAD
void* tadRemove(TAD* c, void* key, int cmp(void* a, void* b));
/*
	retorna elemento removido||NULL
*/

//Destroi cofo vazio
int tadDestroy(TAD* c);
/*
	retorna se cofo foi destruido
*/

//Imprime todos os elementos do TAD
void tadPrint(TAD* c, void printer(void * a));
/*

*/

#endif