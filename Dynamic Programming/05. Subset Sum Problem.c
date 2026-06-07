/* Subset Sum Problem
Given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum.

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.*/


#include <stdio.h>

// সাবসেট সাম চেক করার ফাংশন
int isSubsetSum(int arr[], int n, int sum) {
    // ডিপি টেবিল তৈরি করা
    int dp[n + 1][sum + 1];

    // বেস কেস ১: যদি sum ০ হয়, তবে উত্তর সবসময় True (1)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // বেস কেস ২: যদি অ্যারে খালি হয় কিন্তু sum ০ না হয়, তবে উত্তর False (0)
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = 0;
    }

    // লুপের সাহায্যে বাকি ডিপি টেবিলটি পূরণ করা
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // যদি বর্তমান উপাদানটি কাঙ্ক্ষিত যোগফল j এর চেয়ে বড় হয়
            if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            // যদি ছোট বা সমান হয়, তবে Exclude OR Include
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // টেবিলের শেষ ঘরেই আমাদের চূড়ান্ত উত্তর (0 বা 1) থাকবে
    return dp[n][sum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, sum)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
