/*
Este código foi baseado no algoritmo feito por: Malbolge, no seguinte link: https://github.com/malbolgee/URI
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct brinquedo{

	unsigned short tempo;
	unsigned short qtd_pontos;
	double ponto_tempo;

} Brinquedo;

int compara(Brinquedo *a, Brinquedo *b);

void main ()
{
	unsigned short i;
	unsigned short inst;
	unsigned short atracoes;
	unsigned short limite, aux;
	unsigned short total, tem_total;

	inst = 0;
	while (true){

		scanf("%hu %hu", &atracoes, &limite);

		if (atracoes == 0) {
			break;
		}

		Brinquedo brinquedos[atracoes];

		for (i = 0; i < atracoes; ++i){
			scanf("%hu %hu", &brinquedos[i].tempo, &brinquedos[i].qtd_pontos);
			brinquedos[i].ponto_tempo = (brinquedos[i].qtd_pontos / (double)brinquedos[i].tempo);

		}

		qsort(brinquedos, atracoes, sizeof(Brinquedo), compara);

		i = 0;
		total = tem_total = 0;

		while (i < atracoes){
			aux = tem_total + brinquedos[i].tempo;
			if (aux <= limite){
				total += brinquedos[i].qtd_pontos;
				tem_total = aux;
			}
			else {
				i++;
			}
		}

		printf("Instancia %hu\n%hu\n\n", ++inst, total);
	}
}

int compara(Brinquedo *a, Brinquedo *b){
	if (a->ponto_tempo == b->ponto_tempo){
		return 0;
	} else if (a->ponto_tempo > b->ponto_tempo){
		return -1;
	} else
		return 1;
}
