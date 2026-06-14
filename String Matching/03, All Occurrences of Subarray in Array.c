
/*You are given two integer arrays a[] and b[]. Return all the starting indexes of all the occurrences of b[] as a subarray in a[].

Examples:

Input: a[] = [2, 4, 1, 0, 4, 1, 1], b[] = [4, 1]
Output: [1, 4]
Explanation: b[] occurs as a subarray in a[] from index 1 to 2 and from index 4 to 5.*/

#include <stdio.h>

void findSubarrayIndices(int a[], int n, int b[], int m) {
    int found = 0;

    printf("Output: [");

    // Loop through array a[] up to the valid boundary (n - m)
    for (int i = 0; i <= n - m; i++) {
        int is_match = 1; // Flag to track if b[] matches starting at index i

        // Compare elements of b[] with the segment of a[]
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                is_match = 0; // Mismatch detected
                break;        // Exit inner loop early
            }
        }

        // If a complete match is confirmed
        if (is_match == 1) {
            if (found > 0) {
                printf(", "); // Format with commas for multiple indices
            }
            printf("%d", i);
            found++;
        }
    }

    printf("]\n");

    if (found == 0) {
        printf("Subarray b[] was not found in a[].\n");
    }
}

int main() {
    // Example test case
    int a[] = {2, 4, 1, 0, 4, 1, 1};
    int b[] = {4, 1};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    printf("Input: a[] = [2, 4, 1, 0, 4, 1, 1], b[] = [4, 1]\n");
    findSubarrayIndices(a, n, b, m); // Expected Output: [1, 4]

    return 0;
}
