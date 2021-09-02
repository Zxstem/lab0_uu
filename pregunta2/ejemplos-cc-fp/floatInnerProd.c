#include <stdio.h>
#include <stdlib.h>

extern void asmFloatInnerProd(float *v1, float *v2, int N, float *ip);
void cFloatInnerProd(float *v1, float *v2, int N, float *ip);

int main() {

	float *v1, *v2, ipC, ipAsm;
	int N = 1024;

	v1 = malloc(N * sizeof(float));

	v2 = malloc(N * sizeof(float));

	int i = 0;

	for(i = 0; i < N; i++){
		v1[i] = (float)i;
		v2[i] = (float)i;
	}

	cFloatInnerProd(v1, v2, N, &ipC);
	
	asmFloatInnerProd(v1, v2, N, &ipAsm);

	printf("%f\n%f\n",ipC,ipAsm);

	return 0;
};

void cFloatInnerProd(float *v1, float *v2, int N, float *ip) {
	int i = 0;
	float sum = 0;
	for(i = 0; i < N; i++) {
		sum += v1[i] * v2[i];
	}
	ip[0] = sum;
}
