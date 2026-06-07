/*Longest Common Subsequence (LCS)
Last Updated : 13 Apr, 2026
Given two strings, s1 and s2, find the length of the Longest Common Subsequence. If there is no common subsequence, return 0. A subsequence is a string generated from the original string by deleting 0 or more characters, without changing the relative order of the remaining characters.

For example, subsequences of "ABC" are "", "A", "B", "C", "AB", "AC", "BC" and "ABC". In general, a string of length n has 2n subsequences.
*/
#include <stdio.h>
#include <string.h>

// দুটি সংখ্যার মধ্যে সর্বোচ্চটি বের করার ম্যাক্রো ফাংশন
int max(int a, int b) {
    return (a > b) ? a : b;
}

int getLCSLength(char s1[], char s2[]) {
    int m = strlen(s1);
    int n = strlen(s2);

    // ডিপি টেবিল তৈরি করা (ইনডেক্সিং সহজ করার জন্য আকার m+1 এবং n+1)
    int dp[m + 1][n + 1];

    // বেস কেস: যেকোনো একটি স্ট্রিংয়ের দৈর্ঘ্য ০ হলে LCS হবে ০
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // লুপের সাহায্যে ডিপি টেবিলটি পূরণ করা
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // যদি ক্যারেক্টার মিলে যায়
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // যদি ক্যারেক্টার না মিলে
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // টেবিলের শেষ ঘরেই আমাদের কাঙ্ক্ষিত সর্বোচ্চ দৈর্ঘ্য থাকবে
    return dp[m][n];
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    int result = getLCSLength(s1, s2);
    printf("Length of Longest Common Subsequence: %d\n", result); // আউটপুট: 4 (GTAB)

    return 0;
}
