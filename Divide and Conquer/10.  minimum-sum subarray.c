
//How to find the minimum-sum subarray?
#include <stdio.h>
#include <limits.h>

int findMinSumSubarray(int A[], int n) {
    int min_so_far = INT_MAX;
    int current_min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (current_min > 0) {
            current_min = A[i];
        } else {
            current_min += A[i];
        }

        if (current_min < min_so_far) {
            min_so_far = current_min;
        }
    }
    return min_so_far;
}

int main() {
    int A[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(A) / sizeof(A[0]);

    int result = findMinSumSubarray(A, n);
    printf("The minimum-sum subarray sum is: %d\n", result);

    return 0;
}
