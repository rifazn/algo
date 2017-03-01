#include<stdio.h>
#include <stdlib.h>


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

int main()
{
    int n, r, A[SIZE];

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter a random number: ");
    scanf("%d", &r);

    srand (r);

    for(int i = 1; i <= n; ++i)
        A[i] = rand() % 100;

    printf("Unsorted Array:\t");
    print_array(A, n);

    length = n;

    heap_sort(A, n);

    printf("Sorted Array:\t");
    print_array(A, n);


    return 0;
}

