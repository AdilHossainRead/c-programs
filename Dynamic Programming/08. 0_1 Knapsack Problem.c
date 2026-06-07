/*0/1 Knapsack Problem
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, also given an integer W representing the maximum capacity of the knapsack (the total weight it can hold).Put the items into the knapsack such that the sum of values associated with them is the maximum possible, without exceeding the capacity W.

Note: We can either include an item completely or exclude it entirely - we cannot include a fraction of an item.

Examples:

Input:  W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3*/

#include <stdio.h>

// দুটি সংখ্যার মধ্যে সর্বোচ্চটি বের করার ফাংশন
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack01(int W, int wt[], int val[], int n) {
    // ডিপি টেবিল তৈরি করা (আকার n+1 এবং W+1)
    int dp[n + 1][W + 1];

    // লুপের সাহায্যে ডিপি টেবিলটি পূরণ করা
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // বেস কেস: আইটেম ০ বা ক্যাপাসিটি ০ হলে ভ্যালু ০
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // যদি বর্তমান আইটেমের ওজন ন্যাপসাকের কারেন্ট ক্যাপাসিটি w এর সমান বা ছোট হয়
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            // যদি আইটেমের ওজন বেশি হয়, তবে আইটেমটি বাদ যাবে (Exclude)
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // টেবিলের শেষ ঘরেই আমাদের চূড়ান্ত সর্বোচ্চ ভ্যালু থাকবে
    return dp[n][W];
}

int main() {
    int W = 4;
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int n = sizeof(val) / sizeof(val[0]);

    int max_value = knapsack01(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", max_value); // আউটপুট: 3

    return 0;
}
