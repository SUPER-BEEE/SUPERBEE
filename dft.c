#include <stdio.h>
#include <math.h>
#include <complex.h>


#define PI 3.1415926535

void DFT(complex double x[], complex double X[], int n){
	complex double e_para = cexp(-2 * PI * I / n);

	for(int k = 0; k < n; k++){
		X[k] = 0;
		for(int i = 0; i < n; i++){
			//X[k] += x[i]*cpow(e_para, k*i);
			double angle = -2 * PI * k * i / n;
			//printf("%f",cos(angle));
			//printf("X[%d] = %6.3f + %6.3fi\n",k , creal(X[k]), cimag(X[k]));
			X[k] += x[i] * (cos(angle) + I * sin(angle));
		}
	}
	return;
}

void print_complex_number(complex double x[], int n){
	for(int i = 0; i < n; i++){
		printf("x[%d]: %10.3f + %10.3fi\n", i, creal(x[i]), cimag(x[i]));
	}

	return;
}

int main(){

	int N = 8;
	complex double x[] = {1, 1, 1, 1, 0, 0, 0, 0};
	complex double X[] = {0, 0, 0, 0, 0, 0, 0, 0};

	printf("The original data is:\n");
	print_complex_number(x, N);

	DFT(x, X, N);

	printf("The transformed data is:\n");
	print_complex_number(X, N);

	return 0 ;
}
