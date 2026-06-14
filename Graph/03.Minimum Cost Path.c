/*Given a 2D grid of size n*n, where each cell represents the cost to traverse through that cell, the task is to find the minimum cost to move from the top left cell to the bottom right cell. From a given cell, we can move in 4 directions: left, right, up, down.

Note: It is assumed that negative cost cycles do not exist in input matrix.

Example:

Input: grid = {{9, 4, 9, 9},
                        {6, 7, 6, 4},
                       {8, 3, 3, 7},
                      {7, 4, 9, 10}}
Output: 43*/
#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define MAX 10

// 4 possible direction vectors for moving up, down, left, right
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

// Helper function to find the unvisited cell with the minimum distance
void findMinCell(int dist[MAX][MAX], bool visited[MAX][MAX], int n, int *minRow, int *minCol) {
    int min_val = INF;
    *minRow = -1;
    *minCol = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && dist[i][j] < min_val) {
                min_val = dist[i][j];
                *minRow = i;
                *minCol = j;
            }
        }
    }
}

int minimumCostPath(int grid[MAX][MAX], int n) {
    int dist[MAX][MAX];
    bool visited[MAX][MAX];

    // Initialize all cells as unvisited and at an infinite distance
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    // Set starting cell cost
    dist[0][0] = grid[0][0];

    // Process all cells of the grid
    for (int count = 0; count < n * n; count++) {
        int u_row, u_col;
        findMinCell(dist, visited, n, &u_row, &u_col);

        // If no valid cell is found or the remaining cells are unreachable
        if (u_row == -1 || u_col == -1) break;

        // Mark the picked cell as finalized
        visited[u_row][u_col] = true;

        // If we reached the destination cell, we can exit early
        if (u_row == n - 1 && u_col == n - 1) {
            return dist[n - 1][n - 1];
        }

        // Explore the 4 potential neighbors
        for (int i = 0; i < 4; i++) {
            int v_row = u_row + rowDir[i];
            int v_col = u_col + colDir[i];

            // Boundary and visited validation checks
            if (v_row >= 0 && v_row < n && v_col >= 0 && v_col < n && !visited[v_row][v_col]) {
                // Relaxation step
                if (dist[u_row][u_col] + grid[v_row][v_col] < dist[v_row][v_col]) {
                    dist[v_row][v_col] = dist[u_row][u_col] + grid[v_row][v_col];
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main() {
    int n = 4;
    int grid[MAX][MAX] = {
        {9, 4, 9, 9},
        {6, 7, 6, 4},
        {8, 3, 3, 7},
        {7, 4, 9, 10}
    };

    int result = minimumCostPath(grid, n);
    printf("Minimum cost to reach the bottom-right cell: %d\n", result); // Expected Output: 43

    return 0;
}
