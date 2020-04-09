#include <stdio.h>
#define TAM 1000
 
int main() {
    int vet[TAM];
    int i, j = 0, n;
    
    scanf("%d", &n);
    
    if(n >= 3 && n <= 50){
 
        for(i = 0; i < TAM; i++){
            vet[i] = j;
            j++;
            if(j == n){
                j = 0;
            }
        }
        
        for(i = 0; i < TAM; i++){
            printf("N[%d] = %d\n", i, vet[i]);
        }
    }
    return 0;
}
