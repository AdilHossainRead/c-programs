
/*Given a grid of size m x n, determine the number of distinct paths from the top-left corner (0,0) to the bottom-right corner (m-1, n-1). At each step, one can either move down or right.

Input: m = 3, n = 3
Output: 6
Explanation: Let the given input 3*3 grid is filled as such:
A B C
D E F
G H I
The possible unique paths which exists to reach 'I' from 'A' following above conditions are as follows: ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.
*/
#include <stdio.h>

int countUniquePaths(int m, int n) {
    // ডিপি টেবিল বা ২D অ্যারে তৈরি করা
    int dp[m][n];

    // প্রথম কলামের সব ঘরের মান ১ করা (কেবল নিচে নামা সম্ভব)
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // প্রথম সারির সব ঘরের মান ১ করা (কেবল ডানে যাওয়া সম্ভব)
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // বাকি ঘরগুলোর জন্য পথ হিসাব করা
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // ওপরের ঘর + বামের ঘর
        }
    }

    // শেষ বা নিচের ডানদিকের কোণার ঘরের মান রিটার্ন করা
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;

    int result = countUniquePaths(m, n);
    printf("Number of distinct paths for a %dx%d grid: %d\n", m, n, result);

    return 0;
}
