#include <stdio.h>

int A[] = {2, 4, 5, 7, 1, 2, 3, 6};

void merge(int p, int q, int ra) {
	int n1 = q - p + 2;
	int n2 = ra - q + 1;

	printf("dbg: n1: %d\tn2: %d\n", n1, n2);

	int l[n1], r[n2];

	l[4] = 100000;
	r[4] = 100000;

	for (int i = 0; i < n1 - 1; i++) {
		l[i] = A[p + i];
	}
	for (int i = 0; i < n1; i++) {
		printf("%d ", l[i]);
	}
	puts("");
	for (int j = 0; j < n2 - 1; j++) {
		r[j] = A[q + 1 + j];
	}
	for (int j = 0; j < n2; j++) {
		printf("%d ", r[j]);
	}
	puts("");


	int i = 0;
	int j = 0;

	for (int k = p; i < ra; i++) {
		if (l[i] <= r[j]) {
			A[k] = l[i];
			i++;
		}
		else {
			A[k] = r[j];
			j--;
		}
	}
}

void print_array() {
	for (int i = 0; i < (sizeof(A) / sizeof(int)); i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void)
{
	printf("Before merge\n");
	print_array();

	merge(0, 3, 7);

	printf("After merge\n");
	print_array();
	return 0;
}

