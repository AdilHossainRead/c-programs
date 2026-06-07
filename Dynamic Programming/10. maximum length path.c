/*Find the longest path in a matrix with given constraints
Last Updated : 23 Jul, 2025
Given an n*m matrix where all numbers are distinct, the task is to find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

Example:

Input:
n = 3, m = 3
matrix[][] = [[1 2 9],
                     [5 3 8],
                    [4 6 7]]

Output: 4*/

#include <stdio.h>

// গ্লোবাল ডিরেকশন অ্যারে (৪টি দিক নির্দেশ করে: উপূরে, নিচে, বামে, ডানে)
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

// দুটি সংখ্যার মধ্যে সর্বোচ্চটি বের করার ফাংশন
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ডিএফএস (DFS) ফাংশন যা মেমোভাইজেশন ব্যবহার করে
int findLongestPathFromCell(int i, int j, int matrix[3][3], int dp[3][3], int n, int m) {
    // যদি এই ঘরের জন্য পথ ইতিমধ্যে হিসাব করা থাকে
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int max_path = 1; // যেকোনো ঘরের ন্যূনতম পথ ১ (সে নিজে)

    // ৪টি দিক চেক করার লুপ
    for (int d = 0; d < 4; d++) {
        int next_i = i + rowDir[d];
        int next_j = j + colDir[d];

        // বাউন্ডারি এবং শর্ত চেক: পরবর্তী ঘরের মান বর্তমান ঘরের চেয়ে ঠিক ১ বেশি হতে হবে
        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m) {
            if (matrix[next_i][next_j] == matrix[i][j] + 1) {
                // ১ যোগ করে পরবর্তী ঘরের ডিএফএস কল করা
                max_path = max(max_path, 1 + findLongestPathFromCell(next_i, next_j, matrix, dp, n, m));
            }
        }
    }

    // ডিপি টেবিলে মানটি সংরক্ষণ করা
    dp[i][j] = max_path;
    return dp[i][j];
}

// মূল ফাংশন যা পুরো ম্যাট্রিক্সের জন্য লংগেস্ট পাথ বের করে
int findLongestPathInMatrix(int matrix[3][3], int n, int m) {
    int dp[3][3];

    // শুরুতে ডিপি টেবিল -১ দিয়ে পূরণ করা
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    int overall_max_path = 0;
