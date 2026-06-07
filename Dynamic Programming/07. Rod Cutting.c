/*
Rod Cutting
Given a rod of length n and an array price[]. price[i] denotes the price of a piece of length i. Determine the maximum amount obtained by cutting the rod into pieces and selling the pieces.

Note: price[0] is always 0.

Input: price[] =  [0, 1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
*/
#include <stdio.h>

// দুটি সংখ্যার মধ্যে সর্বোচ্চটি বের করার ফাংশন
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProductProfit(int price[], int n) {
    int dp[n + 1];

    // বেস কেস: ০ দৈর্ঘ্যের রডের প্রফিট ০
    dp[0] = 0;

    // ১ থেকে শুরু করে n দৈর্ঘ্য পর্যন্ত প্রতিটির জন্য সর্বোচ্চ প্রফিট বের করা
    for (int i = 1; i <= n; i++) {
        int max_val = 0;

        // রডটিকে j দৈর্ঘ্যের টুকরোতে কাটার পর সর্বোচ্চ প্রফিট তুলনা করা
        for (int j = 1; j <= i; j++) {
            max_val = max(max_val, price[j] + dp[i - j]);
        }

        dp[i] = max_val; // i দৈর্ঘ্যের জন্য সর্বোচ্চ প্রফিট টেবিলে সংরক্ষণ
    }

    // টেবিলের শেষ ঘরেই n দৈর্ঘ্যের রডের সর্বোচ্চ প্রফিট থাকবে
    return dp[n];
}

int main() {
    // লক্ষ্য করুন: price[0] = 0, এবং ইনডেক্স i নির্দেশ করছে i দৈর্ঘ্যের রডের দাম
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]) - 1; // রডের সর্বোচ্চ দৈর্ঘ্য n = 8

    int result = maxProductProfit(price, n);
    printf("Maximum obtainable value: %d\n", result); // আউটপুট: 22

    return 0;
}
