
#include <stdio.h>

int findMinimumElements(int arr[], int n) {
    long long totalSum = 0;


    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    long long currentSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        count++;


        if (currentSum > (totalSum - currentSum)) {
            return count;
        }
    }
    return count;
}

int main() {
    int arr1[] = {3, 1, 7, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output for [3, 1, 7, 1]: %d\n", findMinimumElements(arr1, n1));

    int arr2[] = {2, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output for [2, 1, 2]: %d\n", findMinimumElements(arr2, n2));

    return 0;
}
