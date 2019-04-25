#ifndef TAD_C_INCLUDED
#define TAD_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"


//-----------------TAD--------------------
TAD* tadCreate(int n){
	TAD* c;
	if(n>0){
		c = (TAD *)malloc(sizeof(TAD));
		if(c != NULL){
			c->elms=(void* *)malloc(sizeof(void*)*n);
			if(c->elms != NULL){
				c->maxElms = n;
				c->nelms = 0;
				return c;
			}
		}
	}
	return NULL;
}

int tadInsert(TAD* c, void* elm){
	if(c != NULL){
		if((c->elms != NULL) && (c->nelms < c-> maxElms)){
			c->elms[c->nelms] = elm;
			c->nelms++;
			return TRUE;
		}
	}
	return FALSE;
}

void* tadQuery(TAD* c, void* key, int cmp(void* a, void* b)){
	int i = 0;
	int stat = FALSE;
	if(c != NULL){
		if(c->nelms > 0){
			stat = cmp(key, c->elms[i]);
			while((stat != TRUE) && (i < c->nelms-1)){
				i++;
				stat = cmp(key, c->elms[i]);
			}
			if(stat == TRUE){
				return c->elms[i];
			}
		}
	}
	return NULL;
}

void* tadRemove(TAD* c, void* key, int cmp(void* a, void* b)){
	if(c != NULL){
		void *aux;
		int stat =  FALSE;
		int i = 0;
		stat = cmp(key, c->elms[i]);
		while((stat != TRUE)&&(i < c->nelms-1)){
			i++;
			stat = cmp(key, c->elms[i]);
		}
		if(stat){
			aux = c->elms[i];
			for( ; i < c->nelms-1; i++){
				c->elms[i] = c->elms[i+1];
			}
			c->nelms--;
			return aux;
		}
	}
	return NULL;
}

int tadDestroy(TAD* c){
	if(c != NULL){
		if(c->nelms > 0){
			free(c->elms);
			free(c);
			return TRUE;
		}
	}
	return FALSE;
}

void tadPrint(TAD* c, void printer(void * a)){
	if(c != NULL){
		if(c->nelms > 0){
			for(int i = 0; i < c->nelms; i++){
				printer(c->elms[i]);
			}
		}
	}
}


#endif