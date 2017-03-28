#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000100

clock_t t;
int a[SIZE];

void start_clock() {
	t = clock();
}

void stop_clock() {
	t = clock() - t;
}

void print_time(int size) {
	printf("input size %d: %f\n", size, ( (float) t )/CLOCKS_PER_SEC);
}

void print_array(int n, int A[]) {
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void counting_sort(int A[], int B[], int k, int n) {
	// making extra space just to be sure
	int* C = malloc(sizeof(int) * (k + 6) );
	for (int i = 0; i < k + 5; i++)
		C[i] = 0;

	for (int j = 1; j <= n; j++) {
		C[ A[j] ] = C[ A[j] ] + 1;
	}

	for (int i = 1; i < k+1; i++)
		C[i] = C[i] + C[i - 1];

	for (int j = n; j > 0; j--) {
		B[ C[ A[j] ] ] = A[j];
		C[ A[j] ] = C[ A[j] ] - 1;
	}

}

int* radix_sort(int A[], int d, int n) {
	int* B = malloc(sizeof(int) * 1000);
	for (int i = 1; i <= d; i++) {
		counting_sort(A, B, 100, n);
	}

	return B;
}

int main(void) {
	int A[1000100];
	int n;

	freopen("input0.txt", "r", stdin);

    scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf(" %d", A + i);
	}

	start_clock();

	int* B = radix_sort(A, 2, n);

	stop_clock();

	print_time(n);

	return 0;
}
