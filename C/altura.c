#include <stdio.h>
#define TAM 231

int main() {
  int N, A, i, j, flag = 0;

  scanf("%d", &N);
  
  while(N--){
	  flag = 0;
	  scanf("%d", &A);
	  
	  int vet[TAM] = {0};

	  for(i = 0; i < A; i++){
		  int valor;
		  scanf("%d", &valor);

		  vet[valor]++;
	  }

	for(i = 20; i < TAM; i++){
		for(j = 0; j < vet[i]; j++){
			if(flag){
				printf(" %d", i);
			}else {
				printf("%d", i);
				flag = 1;
			}
		}
 	}
	printf("\n");
  }

  
  return 0;
}
