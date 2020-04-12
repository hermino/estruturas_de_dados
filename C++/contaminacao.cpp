/*
 * Este código foi desenvolvido por Leonardo Deliyannis Constantin
 * presente no link: https://github.com/maratonaupf/codigos/blob/master/URIOJ/uri1583-bfs.cpp
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define TAM 52

typedef pair<int, int> ii;

int N, M;
char grid[TAM][TAM];
bool visita[TAM][TAM];
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

bool eh_valido(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}

void flood_fill(int si, int sj){
    visita[si][sj] = true;
    queue<ii> pilha;
    pilha.push({si, sj});
    while(!pilha.empty()){
        int i = pilha.front().first, j = pilha.front().second;
        pilha.pop();
        grid[i][j] = 'T';
        for(int k = 0; k < 4; k++){
            int i2 = i+di[k], j2 = j+dj[k];
            if(!eh_valido(i2, j2) || grid[i2][j2] == 'X') continue;
            if(!visita[i2][j2] && grid[i2][j2] == 'A'){
                visita[i2][j2] = true;
                pilha.push({i2, j2});
            }
        }
    }
}

int main(){
    int i, j;
    while(scanf("%d %d", &N, &M), N){
        for(i = 0; i < N; i++)
            scanf("%s", grid[i]);
        memset(visita, 0, sizeof visita);
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                if(grid[i][j] == 'T' && !visita[i][j])
                    flood_fill(i, j);
        for(i = 0; i < N; i++)
            printf("%s\n", grid[i]);
        printf("\n");
    }
    return 0;
}
