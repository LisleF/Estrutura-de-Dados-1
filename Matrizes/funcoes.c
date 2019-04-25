#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


float* multiMat(int n, int m, int p, int q, float* ma, float* mb){
	if((ma!=NULL)&&(mb!=NULL)){
		float *mc;
		float addmult;
		mc = (float*)malloc(sizeof(float)*n*q);
		if(mc!=NULL){
			if(m==p){
				for(int i=0; i < n; i++){
					for(int j=0; j < q; j++){
						addmult = 0.0;
						for(int k=0; k < m; k++){
							addmult += ma[m*i+k]*mb[q*k+j];
						}
						mc[q*i+j] = addmult;
					}
				}
				return mc;
			}	
		}
		free(mc);	
	}
	return NULL;
}

float* Transposta(int n, int m, float* vma){
	float *vtransp;
	if(vma!=NULL){
		vtransp = (float*)malloc(sizeof(float)*n*m);
		if(vtransp!=NULL){
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					vtransp[m*i+j]=vma[m*j+i];
				}
			}
			return vtransp;	
		}
		free(vtransp);	
	}
	return NULL;
	
}

float* triangSuperior(int n, float* vma){
	int sizeVet, contador;
	float* vtriang;
	contador=0;
	sizeVet = n*(n-1)/2;
	vtriang = (float*)malloc(sizeof(float)*sizeVet);
	if((vma!=NULL)&&(vtriang!=NULL)){
		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				if(i<j){
					vtriang[contador]=vma[n*i+j];
					contador++;
				}
			}
		}
		return vtriang;
	}
	free(vtriang);
	return NULL;
}

float* diagPrinc(int n, int m, float* ma){
	if(ma!=NULL){
		float *diagonal;
		int size=n;
		if(m<n){//pega a quantidade de numeros iguais(i==j) para determinar tamanho do vetor diagonal
			size = m;
		}
		diagonal = (float *)malloc(sizeof(float)*size);
		if(diagonal!=NULL){
			for (int i = 0; i < size; i++){
				diagonal[i]= ma[m*i+i];
			}
			return diagonal;
		}
		free(diagonal);	
	}
	return NULL;
}

float* retornaLinha(int n, int m, int k, float* ma){
	if(ma!=NULL){
		float *linha;
		linha=(float*)malloc(sizeof(float)*m);//tamanho é o numero de colunas em 1 linha
		if(linha!=NULL){
			for(int i=0; i < m; i++){
				linha[i]=ma[m*k+i];
			}
			return linha;
		}
		free(linha);
	}
	return NULL;
}
float* retornaColuna(int n, int m, int k, float* ma){
	if(ma!=NULL){
		float *coluna;
		coluna=(float*)malloc(sizeof(float)*n);//tamanho é o numero de linhas em 1 coluna
		if(coluna!=NULL){
			for(int i=0; i < n; i++){
				coluna[i]=ma[m*i+k];
			}
			return coluna;
		}
		free(coluna);
	}
	return NULL;
}

void printMat(int n, int m, float* ma){
	if(ma!=NULL){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				printf("%f ", ma[m*i + j]);
			}
			printf("\n");
		}
	}
}

void printVet(int n, float* vet){
	if(vet!=NULL){
		for(int i = 0; i < n; i++){
			printf("%f ", vet[i]);
		}
	}
}

void display(){
	printf("Qual relatório desejas?\n");
    printf("1 - Multiplicacao(AxB)               5 - Diagonal principal(A) \n");
    printf("2 - Multiplicacao transposta(AxBT)   6 - Linha k da matriz(A)\n");
    printf("3 - Transposta(AT)                   7 - Coluna k da matriz(A)\n");
    printf("4 - Triangulo Superior(A)            8 - Exit Program\n");
}

void menu(int n, int  m, int p, int q, float* ma, float* mb){
	int opc, flag, num;
	float *aux, *matriz;
	display();
    scanf("%d",&opc);
    switch(opc){
    case 1:
    	aux = multiMat( n, m, p, q, ma,  mb);
    	printf("Matriz multiplicacao AxB:\n");
    	printMat(n, q, aux);
    	printf("\nReturn Menu [1]\nExit Program [0]");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 2:
    	aux = Transposta(p, q, mb);
    	if(aux == NULL){
    		matriz = multiMat( n, m, q, p, ma,  aux);
	    	if(matriz!=NULL){
		    	printf("Matriz multiplicacao com a transposta AxBT:\n");
		    	printMat(n, q, matriz);
	    	}	
    	}
    	
    	printf("\nReturn Menu [1]\nExit Program [0]\n");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 3:
    	aux = Transposta(p, q, mb);
    	printf("Matriz transposta A:\n");
    	printMat(p, q, aux);
    	printf("\nReturn Menu [1]\nExit Program [0]");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 4:
    	aux = triangSuperior(n, ma);
    	printf("Os elementos do triangulo superior:\n");
    	printVet(n, aux);
    	printf("\nReturn Menu [1]\nExit Program [0]");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 5:
    	aux = diagPrinc(n, m, ma);
    	num = n;
    	if(m<n){
    		num = m;
    	}
    	printf("\nOs elementos da diagonal principal:\n");
    	printVet(num, aux);

    	printf("\nReturn Menu [1]\nExit Program [0]");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 6:
    	flag = 1;
    	while(flag){
    		printf("Insira a linha: ");
    		scanf("%d", &num);
    		if((num>=0)&&(num<=n)){
    			aux = retornaLinha(n, m, num, ma);
    			flag = 0;	
    		}else{
    			printf("Valor invalido");
    		}
    	}

    	printf("\nOs elementos da linha %d:\n", num);
    	printVet(m, aux);

    	printf("\nReturn Menu [1]\nExit Program [0]");
    	scanf("%d", &flag);
    	if(flag){
    		menu(n, m, p, q, ma, mb);
    	}
    	break;
    case 7:
	    flag = 1;
	    	while(flag){
	    		printf("Insira a coluna: ");
	    		scanf("%d", &num);
	    		if((num>=0)&&(num<=n)){
	    			aux = retornaColuna(n, m, num, ma);
	    			flag = 0;	
	    		}else{
	    			printf("Valor invalido");
	    		}
	    	}

	    	printf("\nOs elementos da coluna %d:\n", num);
	    	printVet(n, aux);

	    	printf("\nReturn Menu [1]\nExit Program [0]");
	    	scanf("%d", &flag);
	    	if(flag){
	    		menu(n, m, p, q, ma, mb);
	    	}
    	break;
    case 8:
    	break;
    default:
    	printf("\nINVALID\n");
    	menu(n, m, p, q, ma, mb);
    	break;	
    }
}