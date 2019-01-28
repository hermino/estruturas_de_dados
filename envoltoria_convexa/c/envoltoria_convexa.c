// Referência: https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/ 

#include<stdio.h>

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
    Pontos envoltoria[10]; 
    
    int l = 0;
    //Procura o ponto mais a esquerda do plano
    for(int i = 1; i < n; i++){
        if(pontos[i].x <= pontos[l].x && pontos[i].y <= pontos[l].y){
            l = i;
        }
    }
    
    
    int p = l, q, j = 0;

    do {
        //Armazena os pontos no vetor da envoltoria
        envoltoria[j] = pontos[p];
        
        q = (p+1)%n;    
        
        for(int i = 0; i < n; i++){
            
            if(orientacao(pontos[p], pontos[i], pontos[q]) == 2){
                q = i;
            }
        }
        
        p = q;
        
        j++;
    }while(p != l);
    
    for(int i = 0; i < j; i++){
        //Imprime os pontos da envoltoria
        printf("(%d,%d)\n", envoltoria[i].x, envoltoria[i].y);
    }
}




int main() {
    // Pontos no plano cartesiano
    Pontos pontos[] = {{0,8}, {1,6}, {8,7}, {6,6}, {8,0}, {3,1}};
    //Quantidades de pontos
    int n = sizeof(pontos)/sizeof(pontos[0]);
    //Chamada da função
    envoltoria_convexa(pontos, n);
    
    return 0;
}