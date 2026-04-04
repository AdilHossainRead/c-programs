
/*Problem-3: Find the max and min element of an array.
Write a program that does the following
(i) take N numbers as input and store them in an array A
(ii) write a function findMaxMin that returns the maximum and minimum elements of an array using
divide and conquer.
(iii) use the function findMaxMin to print the maximum and minimum elements of the array A */

#include <stdio.h>
struct Pair {
    int max;
    int min;
};

struct Pair findMaxMin(int A[], int low, int high) {
    struct Pair result, left_pair, right_pair;
    int mid;

    if (low == high) {
        result.max = A[low];
        result.min = A[low];
        return result;
    }

    if (high == low + 1) {
        if (A[low] > A[high]) {
            result.max = A[low];
            result.min = A[high];
        } else {
            result.max = A[high];
            result.min = A[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left_pair = findMaxMin(A, low, mid);
    right_pair = findMaxMin(A, mid + 1, high);

    if (left_pair.max > right_pair.max)
        result.max = left_pair.max;
    else
        result.max = right_pair.max;

    if (left_pair.min < right_pair.min)
        result.min = left_pair.min;
    else
        result.min = right_pair.min;

    return result;
}

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    struct Pair result = findMaxMin(A, 0, N - 1);

    printf("Maximum element: %d\n", result.max);
    printf("Minimum element: %d\n", result.min);

    return 0;
}
