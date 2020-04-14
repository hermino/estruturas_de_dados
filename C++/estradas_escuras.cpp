/*Referencias do algoritmo de Kruskal:
http://www.codcad.com/lesson/44
*/

#include <algorithm>
#include <iostream>

using namespace std;

struct t_aresta {
	int dis;
	int x, y;
};

bool comp(t_aresta a, t_aresta b) {
	return a.dis < b.dis;
}

//--------------------
#define MAXN 50500
#define MAXM 200200

int n, m; // número de vértices e arestas
t_aresta aresta[MAXM];

// para o union find
int pai[MAXN];
int peso[MAXN];

// a árvore
t_aresta mst[MAXM];
//--------------------

// funções do union find
int find(int x) {
	if (pai[x] == x)
		return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);

	if (peso[a] < peso[b])
		pai[a] = b;
	else if (peso[b] < peso[a])
		pai[b] = a;
	else {
		pai[a] = b;
		peso[b]++;
	}
}

int main() {
	int soma, min;

	while (1) {
		cin >> n >> m;
		// ler a entrada

    if(n == 0 && m == 0){
      break;
    } 

		soma = min = 0;

		for (int i = 1; i <= m; i++)
			cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;

		// inicializar os pais para o union-find
		for (int i = 0; i <= n; i++)
			pai[i] = i;

		// ordenar as arestas
		sort(aresta + 1, aresta + m + 1, comp);

		int size = 0;
		for (int i = 1; i <= m; i++) {
			if (find(aresta[i].x) !=
				find(aresta[i].y)) { // se estiverem em componentes distintas
				join(aresta[i].x, aresta[i].y);
        
				mst[++size] = aresta[i];
			}
		}

		// imprimir a MST
		for (int i = 1; i < n; i++) {
			//cout << i <<": "<< mst[i].dis << "\n";
			min += mst[i].dis;
		}

		for (int i = 1; i <= m; i++) {
			// cout << aresta[i].dis << "\n";
			soma += aresta[i].dis;
		}
    
		//cout << "Soma: " << soma << "\n";
		//cout << "Minimo: " << min << "\n\n";

		cout << soma - min << "\n";

    
	}
	return 0;
}
