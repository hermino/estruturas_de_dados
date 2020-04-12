#include<stdio.h>
#include<string.h>
#include<algorithm>
#define TAM 112


/*
Este c´ódigo foi desenvolvido por leodeliyannis é encontrado
no link: https://github.com/maratonaupf/codigos/blob/master/URIOJ/uri1286.cpp
*/

int q[TAM], t[TAM];
int m[TAM][TAM];

int soma_tempo(int N, int W){
	int tempo, soma, i, j;
	memset(m, 0, sizeof(m));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= W; j++){
			tempo = m[i-1][j];
			if(q[i] <= j){
				soma = m[i-1][j-q[i]] + t[i];
				if(tempo < soma) {
					tempo = soma;
				}
			}
			m[i][j] = tempo;
		}
	}
	return m[N][W];
}

int main(){
	int N, P;
	while(scanf("%d", &N), N){
		scanf("%d", &P);
		for(int i = 1; i <= N; i++) {
			scanf("%d %d", t+i, q+i);
		}
		printf("%d min.\n", soma_tempo(N, P));
	}
	return 0;
}
