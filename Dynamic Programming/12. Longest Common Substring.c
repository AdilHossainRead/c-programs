/*Given two strings s1 and s2, find the length of the longest common substring. A substring is a sequence of characters that appears contiguously in a string.

Example:

Input: s1 = "GeeksforGeeks", s2 = "GeeksQuiz"
Output : 5
Explanation: The longest common substring is "Geeks" and is of length 5.

Input: s1 = "abcdxyz", s2 = "xyzabcd"
Output : 4
*/
#include <stdio.h>
#include <string.h>

int getLongestCommonSubstring(char s1[], char s2[]) {
    int m = strlen(s1);
    int n = strlen(s2);

    // ২D ডিপি টেবিল তৈরি করা
    int dp[m + 1][n + 1];
    int max_length = 0; // সর্বোচ্চ দৈর্ঘ্য ট্র্যাকিং করার জন্য

    // লুপের সাহায্যে ডিপি টেবিলটি পূরণ করা
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // বেস কেস: যেকোনো একটির দৈর্ঘ্য ০ হলে সাবস্ট্রিং দৈর্ঘ্য ০
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // যদি ক্যারেক্টার দুটি মিলে যায়
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // কোনাকুনি আগের ঘরের সাথে ১ যোগ

                // গ্লোবাল সর্বোচ্চ দৈর্ঘ্য আপডেট করা
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                }
            }
            // যদি ক্যারেক্টার না মিলে, তবে ধারাবাহিকতা ভেঙে ০ হবে
            else {
                dp[i][j] = 0;
            }
        }
    }

    return max_length;
}

int main() {
    // উদাহরণ ১
    char s1[] = "GeeksforGeeks";
    char s2[] = "GeeksQuiz";
    printf("Length of Longest Common Subsequence (Example 1): %d\n", getLongestCommonSubstring(s1, s2)); // আউটপুট: 5

    // উদাহরণ ২
    char s3[] = "abcdxyz";
    char s4[] = "xyzabcd";
    printf("Length of Longest Common Subsequence (Example 2): %d\n", getLongestCommonSubstring(s3, s4)); // আউটপুট: 4

    return 0;
}
