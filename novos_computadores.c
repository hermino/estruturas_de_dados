// Referência: https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/ 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 2001

typedef struct ponto {
    int x, y;
}Pontos;

//Função para verificar o qual o proximo ponto da envoltoria
int orientacao(Pontos p, Pontos q, Pontos r){
    //Equação matemática
    int val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));

    if(val == 0) return 0;
    return (val > 0)? 1 : 2;
}


void envoltoria_convexa(Pontos pontos[], int n){
    //Verifica se existe mais de dois ponto no plano
    if(n < 3) return;
    //Vetor para armazenar os pontos da envoltória
    Pontos envoltoria[TAM]; 
    
    int l = 0, i;
    //Procura o ponto mais a esquerda do plano
    for(i = 1; i < n; i++){
        if(pontos[i].x <= pontos[l].x && pontos[i].y <= pontos[l].y){
            l = i;
        }
    }
    
    int p = l, q, j = 0;
    do {
        //Armazena os pontos no vetor da envoltoria
        envoltoria[j] = pontos[p];
        q = (p+1)%n;    
        
        for(i = 0; i < n; i++){
            if(orientacao(pontos[p], pontos[i], pontos[q]) == 2){
                q = i;
            }
        }
        
        p = q;
        j++;
    }while(p != l);
    
    float tam = 0;
    
    for(i = 0; i < j-1; i++){
        //Imprime os pontos da envoltoria
       tam += sqrt(pow(envoltoria[i].x - envoltoria[i+1].x, 2) + pow(envoltoria[i].y - envoltoria[i+1].y, 2));
    }

    float x = sqrt(pow(envoltoria[0].x - envoltoria[j-1].x, 2) + pow(envoltoria[0].y - envoltoria[j-1].y, 2));

    printf("Tera que comprar uma fita de tamanho %.2f.\n", tam+x);
}

int main() {
    // Pontos no plano cartesiano
    int i, c, a, b;
    
    while(1){
      scanf("%d", &c);
      
	  if(c == 0) return 0;
      
	  Pontos pontos[TAM];
      
      for(i = 0; i < c; i++){
        scanf("%d %d", &a, &b);
        pontos[i].x = a;
        pontos[i].y = b;
      }
      
      envoltoria_convexa(pontos, c);
	}
}
