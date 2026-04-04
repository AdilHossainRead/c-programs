/*How to count good pairs? [Suppose, if i < j and A[i] < A[j], then the pair (A[i], A[j]) is called a
good pair of an array A. The sequence 8, 4, -1, 2, 5 has 4 inversions: (4,5), (-1,2), (-1,5), (2,5). ]
*/
#include <stdio.h>

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            count += (right - j + 1);
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return count;
}

int countGoodPairs(int arr[], int temp[], int left, int right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        count += countGoodPairs(arr, temp, left, mid);
        count += countGoodPairs(arr, temp, mid + 1, right);
        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
}

int main() {
    int A[] = {8, 4, -1, 2, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int temp[n];

    int result = countGoodPairs(A, temp, 0, n - 1);
    printf("Total Good Pairs: %d\n", result);

    return 0;
}
