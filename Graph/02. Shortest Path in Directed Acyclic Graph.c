
/*Given a weighted Directed Acyclic Graph (DAG) with n nodes and m edges, where each edge is represented as [u, v, w] (a directed edge from u to v with weight w), and a source node src, find the shortest distance from src to all other nodes.

Note: If it is impossible to reach a node from source node, then mark the distance as -1.

Example:

Input: n = 6, src = 0, edges[][] = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]

1

Output: 0 2 3 6 1 5*/

#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define MAX_NODES 10

// Adjacency Matrix representation for simplicity
int adjMatrix[MAX_NODES][MAX_NODES];
int edgeWeight[MAX_NODES][MAX_NODES];

// Helper structures for Topological Sort Stack
int topoStack[MAX_NODES];
int stackTop = -1;

void push(int node) {
    topoStack[++stackTop] = node;
}

// DFS function to find Topological Sort
void topologicalSortDFS(int u, bool visited[], int n) {
    visited[u] = true;

    for (int v = 0; v < n; v++) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            topologicalSortDFS(v, visited, n);
        }
    }
    // Push current node to stack which stores the reverse topological order
    push(u);
}

void findShortestPathDAG(int n, int src, int edges[][3], int m) {
    // 1. Initialize Adjacency Matrix and Weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
            edgeWeight[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjMatrix[u][v] = 1;
        edgeWeight[u][v] = w;
    }

    // 2. Generate Topological Sort
    bool visited[MAX_NODES] = {false};
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, visited, n);
        }
    }

    // 3. Initialize Distance Array
    int dist[MAX_NODES];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // 4. Process nodes in Topological Order (by popping from stack)
    while (stackTop != -1) {
        int u = topoStack[stackTop--];

        // If the current node has been reached from the source
        if (dist[u] != INF) {
            for (int v = 0; v < n; v++) {
                if (adjMatrix[u][v] == 1) {
                    // Relax the edge
                    if (dist[u] + edgeWeight[u][v] < dist[v]) {
                        dist[v] = dist[u] + edgeWeight[u][v];
                    }
                }
            }
        }
    }

    // 5. Replace INF with -1 for unreachable nodes and print output
    printf("Output: ");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            dist[i] = -1;
        }
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n = 6;
    int src = 0;
    int edges[][3] = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };
    int m = sizeof(edges) / sizeof(edges[0]);

    findShortestPathDAG(n, src, edges, m); // Expected Output: 0 2 3 6 1 5

    return 0;
}
