#include <stdio.h>
#include <stdlib.h>
#define TAM 100001

int main(void) {
  
  int vet[TAM];
  int aux[7] = {0,0,0,0,0,0,0};

  int i, j, N, menor, soma = 0;

  scanf("%d", &N);

  for(i = 0; i < N; i++){
	  scanf("%d", &vet[i]);
  }
  
  for(i = 1; i < 7; i++){
	  for(j = 0; j < N; j++){
			if(vet[j] != i){
		  		if((vet[j]+i) == 7){
			  		aux[i] += 2;
				} else if (vet[j] == i) {
					aux[i] += 0;
		  		}else {
			 		aux[i] += 1;
		  	}
	  	}
	}	 
  }

  menor = aux[1];

  for(i = 2; i < 7; i++){
	  if(aux[i] < menor){
		  menor = aux[i];
	  }
  }
  printf("%d\n", menor);
  return 0;
}
