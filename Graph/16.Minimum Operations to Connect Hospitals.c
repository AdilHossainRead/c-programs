/* In a city, there are many hospitals. Each hospital is connected to some other hospitals, represented using an adjacency list adj[][], where adj[i] contains all hospitals directly connected to the i-th hospital.
Our task is to ensure that all hospitals are connected, either directly or indirectly to each other. In one operation, we can remove an existing link and reconnect it between two previously disconnected hospitals. Determine the minimum number of operations required to make the entire network connected. If it is impossible, return -1.

Examples:

Input: adj[][] = [[1, 2], [0, 2], [0, 1], []]
Output: 1 */


#include <stdio.h>
#include <stdbool.h>

#define MAX_HOSPITALS 20

// Global Adjacency Matrix for simple tracking
int adjMatrix[MAX_HOSPITALS][MAX_HOSPITALS];
int degree[MAX_HOSPITALS];

// Standard DFS function to visit all hospitals in a single component
void DFS(int u, bool visited[], int V) {
    visited[u] = true;

    for (int v = 0; v < V; v++) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            DFS(v, visited, V);
        }
    }
}

int minOperationsToConnect(int V, int edges[][2], int E) {
    // Rule 1: A graph with V vertices needs at least V - 1 edges to be fully connected
    if (E < V - 1) {
        return -1;
    }

    // Initialize Adjacency Matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Build the undirected graph from the edge list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    bool visited[MAX_HOSPITALS] = {false};
    int components = 0;

    // Count the total number of isolated connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            DFS(i, visited, V);
        }
    }

    // The number of operations needed to connect C components is always C - 1
    return components - 1;
}

int main() {
    int V = 4; // Total hospitals: 0, 1, 2, 3

    /* Mapping the input example adj[][] = [[1, 2], [0, 2], [0, 1], []]
       This translates to 3 edges: (0-1), (0-2), (1-2)
       Hospital 3 is completely isolated.
    */
    int edges[][2] = {
        {0, 1},
        {0, 2},
        {1, 2}
    };
    int E = sizeof(edges) / sizeof(edges[0]);

    int result = minOperationsToConnect(V, edges, E);
    printf("Minimum operations required: %d\n", result); // Expected Output: 1

    return 0;
}
