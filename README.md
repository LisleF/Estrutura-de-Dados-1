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
