#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	double c, l;
	double x, y, x1, x2, raiz;
	double z = 0.000;
	
	while(scanf("%lf %lf", &c, &l) != EOF){
		
		x = (4*(c+l) + sqrt(pow(-4*(c+l),2) - 4*12*(c*l)))/(2*12);
		y = (4*(c+l) - sqrt(pow(-4*(c+l),2) - 4*12*(c*l)))/(2*12);

		if(x < y){
			raiz = x;
		} else {
			raiz = y;
		}

		x1 = c/2;
		x2 = l/2;

		if(x1 < x2){
			x = x1;
		}else {
			x = x2;
		}

		printf("%.3lf %.3lf %.3lf\n", raiz, z, x);
	}
}
