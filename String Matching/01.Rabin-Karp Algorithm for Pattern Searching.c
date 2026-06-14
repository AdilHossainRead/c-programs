
/*Given two strings text (the text) and pattern (the pattern), consisting of lowercase English alphabets, find all 0-based starting indices where pattern occurs as a substring in text.

Examples:

Input: text = "geeksforgeeks", pattern = "geeks"
Output:  [0, 8]*/

#include <stdio.h>
#include <string.h>

void findPatternIndices(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    int found = 0;

    printf("Output: [");

    // Loop through the text string up to the valid boundary (N - M)
    for (int i = 0; i <= N - M; i++) {
        int match = 1; // Assume a match is found at index i

        // Compare characters of pattern with the substring of text
        for (int j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                match = 0; // Mismatch found
                break;
            }
        }

        // If the inner loop finished without a mismatch
        if (match == 1) {
            if (found > 0) {
                printf(", "); // Add comma separation for multiple indices
            }
            printf("%d", i);
            found++;
        }
    }

    printf("]\n");

    if (found == 0) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    // Example 1
    char text1[] = "geeksforgeeks";
    char pattern1[] = "geeks";
    printf("Input: text = \"%s\", pattern = \"%s\"\n", text1, pattern1);
    findPatternIndices(text1, pattern1); // Expected Output: [0, 8]

    // Example 2
    char text2[] = "aaaaa";
    char pattern2[] = "aa";
    printf("\nInput: text = \"%s\", pattern = \"%s\"\n", text2, pattern2);
    findPatternIndices(text2, pattern2); // Expected Output: [0, 1, 2, 3]

    return 0;
}
