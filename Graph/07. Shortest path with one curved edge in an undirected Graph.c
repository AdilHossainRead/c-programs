
/*Given an undirected connected graph represented using an adjacency list adj[][][]. For each vertex i, the list adj[i] contains entries of the form {u, w1, w2}, where u is the neighboring vertex, w1 is the weight of the straight edge between i and u, and w2 is the weight of the curved edge between them. Thus, every pair of connected vertices has two parallel edges: one straight and one curved.
We are also given two vertices a and b, and we need to determine the minimum cost required to travel from a to b under the constraint that:

we may use any number of straight edges
we may use at most one curved edge in the entire path.
If no such path exists that satisfies this restriction, we must return -1.

Examples:

Input: a = 1, b = 3, adj[][][] = [[[1, 1, 4], [2, 2, 4], [3, 3, 1]],
                                                    [[0, 1, 4], [3, 6, 5]],
                                                    [[0, 2, 4]],
                                                    [[0, 3, 1], [1, 6, 5]]]

1-
 output: 2 */
 #include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define MAX_V 10

// Adjacency matrices to represent parallel edges
int straightEdge[MAX_V][MAX_V];
int curvedEdge[MAX_V][MAX_V];
bool hasEdge[MAX_V][MAX_V];

// Helper function to find the unvisited node-state pair with the minimum distance
void getMinDistanceState(int dist[MAX_V][2], bool visited[MAX_V][2], int V, int *minNode, int *minState) {
    int min_val = INF;
    *minNode = -1;
    *minState = -1;

    for (int i = 0; i < V; i++) {
        for (int s = 0; s < 2; s++) {
            if (!visited[i][s] && dist[i][s] < min_val) {
                min_val = dist[i][s];
                *minNode = i;
                *minState = s;
            }
        }
    }
}

int findMinCostPath(int V, int a, int b, int edges[][4], int E) {
    // 1. Build Graph Representation
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            hasEdge[i][j] = false;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w1 = edges[i][2];
        int w2 = edges[i][3];

        hasEdge[u][v] = true;
        hasEdge[v][u] = true;
        straightEdge[u][v] = straightEdge[v][u] = w1;
        curvedEdge[u][v] = curvedEdge[v][u] = w2;
    }

    // 2. Initialize Dijkstra Tables
    int dist[MAX_V][2];
    bool visited[MAX_V][2];

    for (int i = 0; i < V; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
        visited[i][0] = false;
        visited[i][1] = false;
    }

    // Starting at node 'a' with 0 curved edges used
