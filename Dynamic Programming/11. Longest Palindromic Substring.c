/* Longest Palindromic Substring
Given a string s, find the longest substring which is a palindrome. If there are multiple answers, then find the first appearing substring.

Examples:

Input: s = "forgeeksskeegfor"
Output: "geeksskeeg"
Explanation: The longest substring that reads the same forward and backward is "geeksskeeg". Other palindromes like "kssk" or "eeksskee" are shorter.

Input: s = "Geeks"
Output: "ee"*/
#include <stdio.h>
#include <string.h>

// কেন্দ্র থেকে দুই পাশে বিস্তার করে প্যালিন্ড্রোমের দৈর্ঘ্য বের করার ফাংশন
int expandFromCenter(char s[], int left, int right, int n) {
    // যতক্ষণ বাউন্ডারির ভেতরে থাকবে এবং দুই পাশের ক্যারেক্টার মিলবে
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // প্যালিন্ড্রোমটির প্রকৃত দৈর্ঘ্য রিটার্ন করা
    return right - left - 1;
}

void longestPalindromicSubstring(char s[]) {
    int n = strlen(s);
    if (n == 0) return;

    int start = 0;      // সবচেয়ে বড় প্যালিন্ড্রোমের শুরুর ইনডেক্স
    int max_len = 1;    // সবচেয়ে বড় প্যালিন্ড্রোমের দৈর্ঘ্য

    for (int i = 0; i < n; i++) {
        // ১. বিজোড় দৈর্ঘ্যের প্যালিন্ড্রোম চেক (যেমন: "aba", কেন্দ্র i)
        int len1 = expandFromCenter(s, i, i, n);

        // ২. জোড় দৈর্ঘ্যের প্যালিন্ড্রোম চেক (যেমন: "abba", কেন্দ্র i এবং i+1)
        int len2 = expandFromCenter(s, i, i + 1, n);

        // দুটির মধ্যে যেটি বড় দৈর্ঘ্য সেটি নেওয়া
        int len = (len1 > len2) ? len1 : len2;

        // যদি বর্তমান দৈর্ঘ্য আমাদের জানা সর্বোচ্চ দৈর্ঘ্যের চেয়ে বড় হয়
        if (len > max_len) {
            max_len = len;
            // শুরুর ইনডেক্স হিসাব করার সূত্র
            start = i - (len - 1) / 2;
        }
    }

    // প্রথম দেখা যাওয়া লংগেস্ট প্যালিন্ড্রোম সাবস্ট্রিংটি প্রিন্ট করা
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + max_len; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    // উদাহরণ ১
    char s1[] = "forgeeksskeegfor";
    longestPalindromicSubstring(s1); // আউটপুট: geeksskeeg

    // উদাহরণ ২
    char s2[] = "Geeks";
    longestPalindromicSubstring(s2); // আউটপুট: ee

    return 0;
}
