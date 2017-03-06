#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1003

int length, heapSize;

void print_array(int *A, int n)
{
    for(int i = 1; i <= n; ++i)
        printf(" %d", A[i]);

    printf("\n");
}


int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2 * i + 1;
}

void max_heapify(int *A, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= heapSize && A[l] > A[i])
        largest = l;


    if (r <= heapSize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        max_heapify(A, largest);
    }

}

void build_max_heap(int *A, int n)
{
    heapSize = n;
    for (int i = n / 2; i > 0; i--) {
        max_heapify(A, i);
    }
}

/*
void heap_sort(int *A, int n)
{
    build_max_heap(A, n);

    for (int i = length; i > 0; i--) {

        // exchange A[1] with A[i]
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;

        heapSize--;
        max_heapify(A, 1);
    }
}
*/

int heap_maximum(int *A) {
	return A[1];
}

int heap_extract_maximum(int *A) {
	if (heapSize < 1) {
		return INT_MIN;
		printf("Heap Error.\n");
	}

	int max = A[1];
	A[1] = A[heapSize];
	heapSize--;
	max_heapify(A, 1);
	return max;
}

void heap_increase_key(int* A, int i, int key) {
	if (key < A[i]) {
		printf("Error increasing key.\n");
		return;
	}

	A[i] = key;
	while (i > 1 && A[parent(i)] < A[i]) {
		int temp = A[i];
		A[i] = A[ parent(i) ];
		A[ parent(i) ] = temp;

		i = parent(i);
	}
}

void max_heap_insert(int* A, int key) {
	heapSize++;
	A[heapSize] = INT_MIN;
	heap_increase_key(A, heapSize, key);
}

int main()
{
    int n, r;

	/*
    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter a random number: ");
    scanf("%d", &r);

    srand (r);

    for(int i = 1; i <= n; ++i)
        A[i] = rand() % 100;
	*/

	int A[] = {0, 4, 2, 6, 8, 9};
	n = sizeof(A) / sizeof(int) - 1;

    printf("Unheaped Array:\t");
    print_array(A, n);

    length = n;

    // heap_sort(A, n);
	build_max_heap(A, n);

    printf("Heaped Array:\t");
    print_array(A, n);

	max_heap_insert(A, 98);

    printf("inserted key 98: ");
    print_array(A, heapSize);

	heap_increase_key(A, 4, 8);
	// heapify again?
    printf("change key at 4 to 8: ");
    print_array(A, heapSize);

	printf("Getting the maximum element in heap..\n");
	int max = heap_extract_maximum(A);
	printf("Extracted: %d\n", max);
    print_array(A, heapSize);



    return 0;
}

