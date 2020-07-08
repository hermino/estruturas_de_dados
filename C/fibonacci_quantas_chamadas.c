#include <stdio.h>

int cont = -1, calls = 0;

int fib(int n){
    cont++;
    if(n == 0){
        return 0;
    } else if(n == 1){
        calls++;
        return 1;
    }else {
        return fib(n - 1) + fib(n - 2);
    }
}
void main() {
    int v, n, i;
    scanf("%d", &v);

    for(i = 0; i < v; i++){
        scanf("%d", &n);
        fib(n);
        printf("fib(%d) = %d calls = %d\n", n, cont, calls);
        cont = -1;
        calls = 0;
    }
}
