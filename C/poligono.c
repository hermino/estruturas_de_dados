#include <stdio.h>
#include <stdlib.h>
#define TAM 100000

//Esta função foi retirada do site: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int compare(const void * a, const void * b) { 
    return ( *(int*)a - *(int*)b ); 
} 
//-------------------------------------------------

int main() {
  
  int N, i, soma = 0, maior = 0;
  int vet[TAM+1];

  scanf("%d ", &N);

  for(i = 0; i < N; i++){
	  scanf("%d", &vet[i]);
	  soma += vet[i];
  }

  qsort(vet, N, sizeof(int), compare); 

  for(i = N-1; i > 0;){
	  maior = vet[i];
	  soma -= maior;
	  if(soma > maior){
		  printf("%d\n", i+1);
		  break;
	  }else {
		  i--;
	  }
  }

  if(i == 0){
	  printf("0\n");
  }

  return 0;
}
