/*Given two strings txt and pat, the task is to find if pat is a substring of txt. If yes, return the index of the first occurrence, else return -1.

Examples :

Input: txt = "geeksforgeeks", pat = "eks"
Output: 2
Explanation: String "eks" is present at index 2 and 10, so 2 is the smallest index.
*/

#include <stdio.h>
#include <string.h>

int findFirstOccurrence(char txt[], char pat[]) {
    int N = strlen(txt);
    int M = strlen(pat);

    // If pattern is longer than text, it can't be a substring
    if (M > N) {
        return -1;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= N - M; i++) {
        int match = 1; // Flag to track if pattern matches at index i

        // Check if the substring starting at index i matches the pattern
        for (int j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                match = 0; // Character mismatch
                break;     // Break inner loop early to save time
            }
        }

        // If a complete match is found, return the current starting index immediately
        if (match == 1) {
            return i;
        }
    }

    // Return -1 if the pattern is not found anywhere in txt
    return -1;
}

int main() {
    // Example 1
    char txt1[] = "geeksforgeeks";
    char pat1[] = "eks";
    int result1 = findFirstOccurrence(txt1, pat1);
    printf("Input: txt = \"%s\", pat = \"%s\"\n", txt1, pat1);
    printf("Output: %d\n\n", result1); // Expected: 2

    // Example 2
    char txt2[] = "helloWorld";
    char pat2[] = "abc";
    int result2 = findFirstOccurrence(txt2, pat2);
    printf("Input: txt = \"%s\", pat = \"%s\"\n", txt2, pat2);
    printf("Output: %d\n", result2); // Expected: -1

    return 0;
}
