#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


/*

*/
int main(){
	//DECLARATION
	FILE *file_matA, *file_matB;
	float *matA, *matB;
	int lineA, columA, lineB, columB;

	//MATRIX A
	file_matA = fopen("matrizA.txt", "r");//Abre arquivo da primeira matriz
	fscanf(file_matA, "%d %d", &lineA, &columA);//Pega valores da linha e coluna
	matA = (float*)malloc(sizeof(float)*lineA*columA);
	if(matA!=NULL){
		for(int i = 0; i < lineA; i++){
			for(int j=0; j < columA; j++){
				fscanf(file_matA, "%f", &matA[columA*i+j]);
			}
		}
	}

	//MATRIX B
	file_matB = fopen("matrizB.txt", "r");
	fscanf(file_matB, "%d %d", &lineB, &columB);//Pega valores da linha e coluna
	matB = (float*)malloc(sizeof(float)*lineB*columB);
	if(matB!=NULL){
		for(int i = 0; i < lineB; i++){
			for(int j=0; j < columB; j++){
				fscanf(file_matB, "%f", &matB[columB*i+j]);
			}
		}
	}

	menu(lineA, columA, lineB, columB, matA, matB);
}