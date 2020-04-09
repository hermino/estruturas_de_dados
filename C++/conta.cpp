#include <iostream>
using namespace std;

int main() {
	int i = 0, j = 0, n = 0, contador = 0, c = 0;

	cin >> c;

	for (j = 0; j < c; j++){

		cin >> n;

		for (i = 1; i <= n; i++){
			if(i%2 != 0){
				contador++;
			}else {
				contador--;
			}
		}
		cout << contador << endl;
		contador = 0;
	}
}
