#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100


void insertion_sort(int vet[]){

    int key = 0, j = 0;

    for(int i = 1; i < TAM; i++){
        key = vet[i];

        j = i - 1;

        while(j >= 0 && vet[j] > key){
            vet[j+1] = vet[j];
            j = j - 1;
        }

        vet[j+1] = key;
    }

    for(int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }
}

int main(){
    int vet[TAM] = {0}, x = 0;

    srand((unsigned)time(NULL));

    for(int i = 0; i < TAM; i++){
        x = (rand()%TAM);
        vet[i] = x;
    }

    insertion_sort(vet);

    return 0;
}
