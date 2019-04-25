#ifndef _STACK_H_INCLUDED
#define _STACK_H_INCLUDED
#define TRUE 1
#define FALSE 0


typedef struct _stack_{
	int top;
	int maxElms;
	void** elms;
}Stack;

//Cria uma pilha com n espacos
Stack* stkCreate(int n);
/*
	retorna pilha vazia || NULL
*/

int stkPush(Stack* s, void* elm);
/*
	retorna se elemento foi empilhado (TRUE||FALSE)
*/
void* stkPop(Sack* s);
/*
	retorna elemento desempilhado || NULL
*/

int stkDestroy(Stack* s);
/*
	retorna se pilha foi destruida (TRUE||FALSE)
*/

#endif