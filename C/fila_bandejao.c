/*
 * Leonardo Deliyannis Constantin
 * URI 1524 - Fila do Bandejão
*/

#include<stdio.h>
#include<stdlib.h>
#define TAM 1123
#define indices(dist, idx) do{ indices[i].primeiro = dist; indices[i].segundo = idx; }while(0)

typedef struct par{
	int primeiro, segundo;
} Par;

int distCmp(const void *p1, const void *p2){
	Par a = *(Par*)p1;
	Par b = *(Par*)p2;
	return b.primeiro - a.primeiro;
}

int idxCmp(const void *p1, const void *p2){
	Par a = *(Par*)p1;
	Par b = *(Par*)p2;
	return a.segundo - b.segundo;
}

int main(void){
	Par indices[TAM];
	int N, K, i;
	int pos[TAM];
	int soma, anterior, atual;
	while(scanf("%d %d", &N, &K) != EOF){
		pos[0] = i = 0;
		indices(0, 0);
		for(i = 1; i < N; i++){
			scanf("%d", &pos[i]);
			indices(pos[i] - pos[i-1], i);
		}
		qsort(indices, N, sizeof(indices[0]), &distCmp);
		qsort(indices, --K, sizeof(indices[0]), &idxCmp);
		soma = 0;
		atual = 0;
		for(i = 0; i < K; i++){
			anterior = atual;
			atual = indices[i].segundo;
			soma += pos[atual-1] - pos[anterior];
		}
		soma += pos[N-1] - pos[atual];
		printf("%d\n", soma);
	}
	return 0;
}
