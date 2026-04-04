// How to change binary search for descending order?
#include <stdio.h>

int binarySearchDescending(int A[], int low, int high, int X) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == X)
            return mid;
        if (X > A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int A[] = {90, 75, 60, 45, 30, 15};
    int n = sizeof(A) / sizeof(A[0]);
    int X = 45;

    int result = binarySearchDescending(A, 0, n - 1, X);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
