#ifndef STACK_C_INCLUDED
#define STACK_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* stkCreate(int n){
	Stack* s;
	if(n > 0){
		s = (Stack *)malloc(sizeof(Satck));
		if(s != NULL){
			s->elms = (void* *)malloc(sizeof(void*));
			if(s->elms != NULL){
				s->top = -1;
				s->maxElms= n;
				return s;
			}
		}
	}
	return NULL;
}

int stkPush(Stack* s, void* elm){
	if(s != NULL){
		if(s->top < (s->maxElms-1)){
			s->top++;
			s->elms[s->top] = elm;
			return TRUE;
		}
	}
	return FALSE;
}

void* stkPop(Sack* s){
	if(s != NULL){
		if(s->top >= 0){
			void* elm;
			elm = s->elms[s->top];
			s->top--;
			return elm;
		}
	}
	return NULL;
}

int stkDestroy(Stack* s){
	if(s != NULL){
		if(s->top < 0){
			free(s->elms);
			free(s);
			return TRUE;
		}
	}
	return FALSE
}

#endif