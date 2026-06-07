/* Count distinct occurrences as a subsequence

Given two strings pat and txt, where pat is always shorter than txt, count the distinct occurrences of pat as a subsequence in txt.

Examples:

Input: txt = abba, pat = aba
Output: 2
Explanation: pat appears in txt as below two subsequences.
[abba], [abba]

Input: txt = banana, pat = ban
Output: 3 */
#include <stdio.h>
#include <string.h>

int countSubsequences(char txt[], char pat[]) {
    int n = strlen(txt);
    int m = strlen(pat);

    // যদি pat বড় হয়ে যায়, তবে সাবসিকোয়েন্স হওয়া সম্ভব নয়
    if (m > n) return 0;

    // ডিপি টেবিল তৈরি করা
    int dp[m + 1][n + 1];

    // বেস কেস: pat খালি হলে (i = 0), সবসময় ১টি উপায় থাকে
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    // যদি txt খালি হয় কিন্তু pat খালি না হয় (j = 0, i > 0), উপায় ০টি
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }

    // লুপের সাহায্যে বাকি ডিপি টেবিলটি পূরণ করা
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // যদি ক্যারেক্টার দুটি মিলে যায়
            if (pat[i - 1] == txt[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            // যদি ক্যারেক্টার দুটি না মিলে
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // টেবিলের শেষ ঘরেই আমাদের কাঙ্ক্ষিত মোট সংখ্যাটি থাকবে
    return dp[m][n];
}

int main() {
    // উদাহরণ ১
    char txt1[] = "abba";
    char pat1[] = "aba";
    printf("Output for abba & aba: %d\n", countSubsequences(txt1, pat1)); // আউটপুট: 2

    // উদাহরণ ২
    char txt2[] = "banana";
    char pat2[] = "ban";
    printf("Output for banana & ban: %d\n", countSubsequences(txt2, pat2)); // আউটপুট: 3

    return 0;
}
