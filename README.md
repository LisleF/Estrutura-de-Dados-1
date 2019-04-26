# Estrutura-de-Dados-1
Aulas de Estruturas de Dados 1
## Alocacao Dinamica
Como alocar dinamicamente usando malloc:
```
<estrutura> = (<tipo da estrutura> *)malloc(size of(<tipo da estrutura>)*<tamanho>); 
```
### Variavel:
```
int *pa;
pa = (int*)malloc(sizeof(int));
free(pa); //Para liberar memoria alocada
```
### Vetores
```
int *pva;
pva = (int*)malloc(sizeof(int)*tamanho);
if(pva != NULL){
  // Testou se alocou
  <codigo>
}
free(pva); //Para liberar memoria alocada

```
### Matrizes
```
  int *ma;
  ma = (int*)malloc(sizeof(int)*linhas);
  for(int i=0; i<linhas; i++){
    ma[i]=(int*)malloc(sizeof(int)*colunas);
  }
  if(ma != NULL){
    // Testou se alocou
    <codigo>
  }
  free(ma); //Para liberar memoria alocada
```
## Matrizes como vetores
Como indexar vetor matriz nxm :
```
  m[i][j] --> vm[m*i + j]
```
Como alocar dinamicamente vetor matriz nxm :

```
int *vm;
vm = (int*)malloc(sizeof(int)*n*m);
if(vm != NULL){
  // Testou se alocou
  <codigo>
}
free(vm); //Para liberar memoria alocada
```
*trabalho de matrizes como vetores na pasta Matrizes*

## Tipos Abstratos de Dados (TAD)
Estrutura de dados e colecao de funcoes que operam sobre essa estrutura.
Especifica tudo que se precisa saber para usar um determinado tipo de dados.
```
typedef struct _TAD_ {
	int maxElms;
	int nelms;
	void* *elms;
}TAD;
```
*Implementacao de um TAD que guarda qualquer tipo de dados*

## Pilhas 
Restricao de acesso. 
Last In First Out(LIFO).

```
typedef struct _stack_{
	int top;
	int maxElms;
	void** elms;
}Stack;
```
*Implementacao de uma pilha*

## Filas 
Restricao de acesso. 
First In First Out(FIFO).

```
typedef struct _queue_{
	void* elms;
	int front;
	int rear;
	int maxElms;
	int nelms;
}Queue;
```
*Implementacao de uma fila*
