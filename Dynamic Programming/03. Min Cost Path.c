
/*Given a 2D matrix cost[][], where each cell represents the cost of traversing through that position. We need to determine the minimum cost required to reach the bottom-right cell (m-1, n-1) starting from the top-left cell (0,0).
The total cost of a path is the sum of all cell values along the path, including both the starting and ending positions. From any cell (i, j), you can move in the following three direction Right (i, j+1), Down (i+1, j) and Diagonal (i+1, j+1). Find the minimum cost path from (0,0) to (m-1, n-1), ensuring that movement constraints are followed.

Example:

Input: cost[][] = [[1, 2, 3],
                             [4, 8, 2],
                             [1, 5, 3]]

                             */

#include <stdio.h>

// তিনটি সংখ্যার মধ্যে সর্বনিম্নটি খুঁজে বের করার ফাংশน
int min(int x, int y, int z) {
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int minCostPath(int cost[3][3], int m, int n) {
    int dp[m][n];

    // বেস কেস: শুরুর ঘরের খরচ
    dp[0][0] = cost[0][0];

    // প্রথম কলামের ঘরগুলোর খরচ হিসাব করা (কেবল নিচে নামা সম্ভব)
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

    // প্রথম সারির ঘরগুলোর খরচ হিসাব করা (কেবল ডানে যাওয়া সম্ভব)
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }

    // লুপের সাহায্যে বাকি ডিপি টেবিলটি পূরণ করা
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // ওপরের, বামের এবং কোনাকুনি ঘরের মধ্যে সর্বনিম্নটি নেওয়া
            dp[i][j] = cost[i][j] + min(dp[i - 1][j],     // Down থেকে আসা
                                        dp[i][j - 1],     // Right থেকে আসা
                                        dp[i - 1][j - 1]); // Diagonal থেকে আসা
        }
    }

    // শেষ বা নিচের ডানদিকের কোণার ঘরের মোট সর্বনিম্ন খরচ রিটার্ন করা
    return dp[m - 1][n - 1];
}

int main() {
    int cost[3][3] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };

    int result = minCostPath(cost, 3, 3);
    printf("Minimum cost to reach the bottom-right cell: %d\n", result); // আউটপুট: 8

    return 0;
}
