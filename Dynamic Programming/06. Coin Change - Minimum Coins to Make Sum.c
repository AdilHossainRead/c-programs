/*Coin Change - Minimum Coins to Make Sum

Given an array of coins[] of size n and a target value sum, where coins[i] represent the coins of different denominations. You have an infinite supply of each of the coins. The task is to find the minimum number of coins required to make the given value sum. If it is not possible to form the sum using the given coins, return -1.

Examples:

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation : Minimum 2 coins needed, 25 and 5

Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1

Input: coins[] = [5, 1], sum = 0
Output: 0*/
#include <stdio.h>

#define INF 100000000 // ইনফিনিটি বা অবাস্তব বড় সংখ্যা হিসেবে ডিফাইন করা হলো

int minCoinsRequired(int coins[], int n, int sum) {
    // ডিপি টেবিল তৈরি করা
    int dp[sum + 1];

    // বেস কেস: ০ টাকা তৈরি করতে ০টি কয়েন লাগে
    dp[0] = 0;

    // বাকি ঘরগুলোকে শুরুতে INF বা বড় মান দিয়ে রাখা
    for (int i = 1; i <= sum; i++) {
        dp[i] = INF;
    }

    // ১ টাকা থেকে শুরু করে টার্গেট sum পর্যন্ত প্রতিটির জন্য সর্বনিম্ন কয়েন বের করা
    for (int i = 1; i <= sum; i++) {
        // আমাদের হাতে থাকা প্রতিটি কয়েন চেক করা
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];

                // যদি সাব-প্রবলেমটির সমাধান বা পাথ থেকে থাকে
                if (sub_res != INF && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    // যদি শেষ ঘরের মান INF-ই থেকে যায়, তার মানে এই sum তৈরি করা অসম্ভব
    if (dp[sum] == INF) {
        return -1;
    }

    return dp[sum];
}

int main() {
    // উদাহরণ ১
    int coins1[] = {25, 10, 5};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    int sum1 = 30;
    printf("Output for Example 1: %d\n", minCoinsRequired(coins1, n1, sum1)); // আউটপুট: 2

    // ুদাহরণ ২ (যেখানে গ্রিডি পদ্ধতি ফেইল করে কিন্তু ডিপি কাজ করে)
    int coins2[] = {9, 6, 5, 1};
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    int sum2 = 19;
    printf("Output for Example 2: %d\n", minCoinsRequired(coins2, n2, sum2)); // আউটপুট: 3

    // উদাহরণ ৩
    int coins3[] = {5, 1};
    int n3 = sizeof(coins3) / sizeof(coins3[0]);
    int sum3 = 0;
    printf("Output for Example 3: %d\n", minCoinsRequired(coins3, n3, sum3)); // আউটপুট: 0

    return 0;
}
