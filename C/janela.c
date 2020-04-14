#include <stdio.h>
#include <stdlib.h>
#define JANELA 600
#define FOLHA 200

//Esta função foi retirada do site: https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int compare(const void * a, const void * b) { 
    return ( *(int*)a - *(int*)b ); 
} 
//-------------------------------------------------

int main() {
  int vet[3], F1, F2, F3, calculo = 0;

  scanf("%d %d %d", &vet[0], &vet[1], &vet[2]);

  qsort(vet, 3, sizeof(int), compare);

  F1 = vet[0] + FOLHA;
  F2 = vet[1] + FOLHA;
  F3 = vet[2] + FOLHA;

  //PRIMEIRO CASO: SE TODOS AS FOLHAS ESTIVEREM SEPARADAS
  if(vet[1] >= F1 && vet[2] >= F2){
	  printf("0\n");
  //SEGUNDO CASO: SE TODAS AS FOLHAS ESTIVEREM EM CIMA F1
  } else if (vet[1] < F1 && vet[2] < F2){
	  calculo = JANELA-(FOLHA+(F2-F1)+(F3-F2));
	  printf("%d\n", calculo*100);
  //TERCEIRO CASO: SE F3 ESTIVER EM CIMA DE F2 E F1 SEPARADA
  } else if (vet[2] < F2 && vet[1] >= F1){
	  calculo = JANELA-(FOLHA+FOLHA+(F3-F2));
	  printf("%d\n", calculo*100);
  //QUARTO CASO: SE F2 ESTIVER EM CIMA DE F1 E F3 SEPARADA
  } else if (vet[1] < F1 && vet[2] >= F2){
	  calculo = JANELA-(FOLHA+(F2-F1)+FOLHA);
	  printf("%d\n", calculo*100);
  }
  return 0;
}
