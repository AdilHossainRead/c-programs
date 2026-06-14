/*
Given a square chessboard of n x n size, the position of the Knight and the position of a target are given. We need to find out the minimum steps a Knight will take to reach the target position.

Examples:

Input:

kNIGHT
Knight
knightPosition:  (1, 3) , targetPosition: (5, 0)

Output: 3*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_BOARD_SIZE 20

// Coordinate offsets representing the 8 possible legal moves of a knight
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Custom struct to represent cells inside our BFS queue array
struct QueueCell {
    int x;
    int y;
    int dist; // Steps taken from the source cell
};

// Checking if coordinates stay within legal chessboard dimensions
bool isInsideBoard(int x, int y, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

int minKnightSteps(int knightPos[], int targetPos[], int n) {
    // 2D tracking matrix to remember visited configurations
    bool visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    // Creating a static array-based queue big enough to track worst-case cells
    struct QueueCell queue[MAX_BOARD_SIZE * MAX_BOARD_SIZE];
    int front = 0;
    int rear = 0;

    // Map coordinates safely to 0-indexed positions
    int startX = knightPos[0];
    int startY = knightPos[1];
    int targetX = targetPos[0];
    int targetY = targetPos[1];

    // Enqueue the initial starting position
    queue[rear].x = startX;
    queue[rear].y = startY;
    queue[rear].dist = 0;
    rear++;

    visited[startX][startY] = true;

    // Run BFS loop
    while (front < rear) {
        // Dequeue current element
        struct QueueCell current = queue[front++];

        // If current cell is the target, return distance immediately
        if (current.x == targetX && current.y == targetY) {
            return current.dist;
        }

        // Loop through all 8 possible moves for the knight
        for (int i = 0; i < 8; i++) {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];

            // If the next move is valid and hasn't been visited yet
            if (isInsideBoard(nextX, nextY, n) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;

                // Enqueue the new cell with step count incremented by 1
                queue[rear].x = nextX;
                queue[rear].y = nextY;
                queue[rear].dist = current.dist + 1;
                rear++;
            }
        }
    }

    return -1; // Return -1 if target is unreachable
}

int main() {
    // Setting board size to 8x8 as a standard template example
    int n = 8;
    int knightPosition[] = {1, 3};
    int targetPosition[] = {5, 0};

    int min_steps = minKnightSteps(knightPosition, targetPosition, n);

    printf("Input Knight Position: (%d, %d)\n", knightPosition[0], knightPosition[1]);
    printf("Input Target Position: (%d, %d)\n", targetPosition[0], targetPosition[1]);
    printf("Minimum steps needed: %d\n", min_steps); // Expected Output: 3

    return 0;
}
