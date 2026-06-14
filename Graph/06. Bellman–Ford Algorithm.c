/*Given a weighted graph with V vertices and E edges, along with a source vertex src, the task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. In the presence of a negative weight cycle, return -1 to signify that shortest path calculations are not feasible.

Examples:

Input: V = 5, edges = [[0, 1, 5], [1, 2, 1], [1, 3, 2], [2, 4, 1], [4, 3, -1]], src = 0

bellman_ford_input_images

Output: [0, 5, 6, 6, 7]
*/
#include <stdio.h>

#define INF 100000000
#define MAX_V 20
#define MAX_E 50

void bellmanFordShortestPath(int V, int E, int edges[][3], int src) {
    int dist[MAX_V];

    // Step 1: Initialize distances from src to all other vertices as INFINITY
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Step 2: Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            // Negative cycle detected, abort calculations
            printf("-1\n");
            return;
        }
    }

    // Step 4: Format output, swapping unreachable nodes with 108
    printf("[");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            dist[i] = 108;
        }
        printf("%d", dist[i]);
        if (i < V - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int V = 5;
    int src = 0;
    int edges[][3] = {
        {0, 1, 5},
        {1, 2, 1},
        {1, 3, 2},
        {2, 4, 1},
        {4, 3, -1}
    };
    int E = sizeof(edges) / sizeof(edges[0]);

    printf("Output: ");
    bellmanFordShortestPath(V, E, edges, src); // Expected Output: [0, 5, 6, 6, 7]

    return 0;
}
