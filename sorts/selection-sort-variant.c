/* This is a variation of selection sort.
 * Instead of finding the minimum value and swapping values,
 * it also finds the maximum value from the array, and swaps that.
 * Thus, reducing the time complexity.
 *
 * TODO: better description
 * */

#include <stdio.h>

int A[1000];

void selection_variant(int n) {
	for (int i = 0, j = n - 1; i <= j; i++, j--) {
		int min = i;
		int max = j;

		for (int ii = i + 1; ii <= j; ii++) {
			if (A[ii] < A[min]) {
				min = ii;
			}

			if (A[ii] > A[max]) {
				max = ii;
			}
		}

		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;

		temp = A[j];
		A[j] = A[max];
		A[max] = temp;
	}
}

int main(void)
{
	//int n = sizeof(A) / sizeof(int);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", A+i);

	selection_variant(n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

