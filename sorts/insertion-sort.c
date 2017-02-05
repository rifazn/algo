/* Insertion sort in ascending order */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int a[SIZE];

void insertion_sort(int n) {
	int key;
	int i, j;
	for (i = 1; i < n; i++) {
		key = a[i];

		// insert a[j] into the sorted array
		j = i - 1;
		while (j > -1 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void print_array() {
	int i;
	for (i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int i;
	for (i = 0; i < SIZE; i++)
		a[i] = rand() % 101;

	// print array before sorting
	printf("Print the array before sorting:\n");
	print_array();

	// sort the array
	insertion_sort(SIZE);

	// print the array after sorting
	printf("Print the sorted array:\n");
	print_array();

	return 0;
}

