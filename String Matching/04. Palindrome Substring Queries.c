/*
Given a string s and a 2D list of queries[][], where each queries[i] consists of two integers [left, right]. Each query refers to the substring s[left : right], where both left and right are inclusive (0-based indexing).
For each query, find whether the substring s[left : right] forms a palindrome.

Examples :

Input: s = "abaaabaaaba", queries[][] = [[0, 10], [5, 8], [2, 5], [5, 9]]
Output: [1, 0, 0, 1]
Explanation: Lets process all the queries one by one:
-> [0, 10]: The substring is "abaaabaaaba" which is a palindrome.
-> [5, 8]: The substring is "baaa" which is not a palindrome.
-> [2, 5]: The substring is “aaab” which is not a palindrome.
-> [5, 9]: The substring is “baaab” which is a palindrome. */
#include <stdio.h>
#include <string.h>

void solvePalindromeQueries(char s[], int queries[][2], int num_queries) {
    int n = strlen(s);

    // Create a 2D DP table initialized to 0
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // 1. All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // 2. Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    // 3. Check substrings of length 3 or more
    // len is the current substring length
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // Ending index

            // Conditions for a palindrome: outer match and inner substring match
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
            }
        }
    }

    // Process each query in O(1) time
    printf("Output: [");
    for (int q = 0; q < num_queries; q++) {
        int left = queries[q][0];
        int right = queries[q][1];

        printf("%d", dp[left][right]);
        if (q < num_queries - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    char s[] = "abaaabaaaba";
    int queries[][2] = {
        {0, 10},
        {5, 8},
        {2, 5},
        {5, 9}
    };
    int num_queries = sizeof(queries) / sizeof(queries[0]);

    printf("Input string: \"%s\"\n", s);
    solvePalindromeQueries(s, queries, num_queries); // Expected Output: [1, 0, 0, 1]

    return 0;
}
