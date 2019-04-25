
float* multiMat(int n, int m, int p, int q, float* ma, float* mb);
/*
	Retorna o vetor matriz multiplicacao
	entre duas matrizes(AxB)
*/

float* Transposta(int n, int m, float* vma);
/*
	Retorna o vetor matriz transposta
	de uma matriz.
*/

float* triangSuperior(int n, float* vma);
/*
	Retorna um vetor com os elementos
	do triangulo superior de uma matriz.
*/

float* diagPrinc(int n, int m, float* ma);
/*
	Retorna o vetor com os elementos da
	diagonal principal de uma matriz.
*/

float* retornaLinha(int n, int m, int k, float* ma);
/*
	Retorna o vetor de elementos de
	uma linha k qualquer da matriz.
*/

float* retornaColuna(int n, int m, int k, float* ma);
/*
	Retorna o vetor de elementos de
	uma coluna k qualquer da matriz.
*/

void printMat(int n, int m, float* ma);
/*
	Imprime na tela todos os elementos
	de um vetor matriz.
*/

void printVet(int n, float* ma);
/*
	Imprime na tela todos os 
	elementos de um vetor 
*/

void display();
/*
	Show menu options
*/

void menu(int n, int m, int p, int q, float* ma, float* mb);
/*
	Gera o menu do programa
*/