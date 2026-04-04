/*Problem-4: Binary Search
Write a function binarySearch that finds the index of an element X in a sorted (ascending) array A of N
integers using divide and conquer. If the element X is not present in the array, return -1.
Write a main that takes the array A and an integer X as input from the user. After that, sort the array A
using the quicksort algorithm and find the index of X in A using the function binarySearch and print it.
*/
#include <stdio.h>

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return (i + 1);
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int binarySearch(int A[], int low, int high, int X) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (A[mid] == X)
            return mid;


        if (A[mid] > X)
            return binarySearch(A, low, mid - 1, X);

        return binarySearch(A, mid + 1, high, X);
    }
    return -1;
}

int main() {
    int N, X;
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);

    int A[N];
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the element to search (X): ");
    scanf("%d", &X);

    quickSort(A, 0, N - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < N; i++) printf("%d ", A[i]);

    int result = binarySearch(A, 0, N - 1, X);

    if (result != -1)
        printf("\nElement %d found at index: %d\n", X, result);
    else
        printf("\nElement %d not present in the array.\n", X);

    return 0;
}
