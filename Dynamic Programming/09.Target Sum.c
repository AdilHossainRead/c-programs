/* Target Sum

Given an array arr[] and an integer target. We want to build an expression out of arr[] by adding one of the symbols '+' and '-' before each integer in arr[] and then concatenate all the integers. Determine the number of different expressions that can be built, which evaluates to target.

Example:

Input : arr[] = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation: There are 5 ways for target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: arr[] = [1], target = 1
Output: 1*/
#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int arr[], int n, int target) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    // কর্নার কেস চেক
    if (abs(target) > total_sum) return 0;
    if ((total_sum + target) % 2 != 0) return 0;

    // আমাদের খোঁজা কাঙ্ক্ষিত সাবসেট সাম (S1)
    int s1_sum = (total_sum + target) / 2;

    // যদি target মাইনাস হওয়ার কারণে s1_sum ঋণাত্মক হয়
    if (s1_sum < 0) return 0;

    // ১-ডাইমেনশনাল ডিপি টেবিল (Space Optimized)
    int dp[s1_sum + 1];

    // ডিপি টেবিল ইনিশিয়ালাইজ করা (শুরুতে সব ০, কেবল dp[0] = 1)
    dp[0] = 1;
    for (int j = 1; j <= s1_sum; j++) {
        dp[j] = 0;
    }

    // ডাইনামিক প্রোগ্রামিং লুপ
    for (int i = 0; i < n; i++) {
        // উল্টো দিক থেকে লুপ চালানো হচ্ছে যাতে একই উপাদান বারবার কাউন্ট না হয়
        for (int j = s1_sum; j >= arr[i]; j--) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }

    return dp[s1_sum];
}

int main() {
    // উদাহরণ ১
    int arr1[] = {1, 1, 1, 1, 1};
    int target1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output for Example 1: %d\n", findTargetSumWays(arr1, n1, target1)); // আউটপুট: 5

    // উদাহরণ ২
    int arr2[] = {1};
    int target2 = 1;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output for Example 2: %d\n", findTargetSumWays(arr2, n2, target2)); // আউটপুট: 1

    return 0;
}
