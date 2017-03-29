/* Rifaz Nahiyan
 * Radix sort using Counting sort
 *
 * Please note that this algo is 1 indexed.
 * */

#include <stdio.h>
#include <stdlib.h>

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

    scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf(" %d", A + i);
	}

	int* B = radix_sort(A, 2, n);

	return 0;
}
