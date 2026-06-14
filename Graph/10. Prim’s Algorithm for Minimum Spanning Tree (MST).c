
#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define V 5 // Total number of vertices in the sample graph

// Helper function to find the vertex with the minimum key value
// from the set of vertices not yet included in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to construct and print the MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Values used to pick the minimum weight edge in the cut
    bool mstSet[V]; // To track vertices included in the MST

    // Initialize all keys as INFINITY and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    // Make key 0 so that this vertex is picked as the first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // The MST will have exactly V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST edges and weights
    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Minimum Spanning Tree Cost: %d\n", totalCost);
}

int main() {
    /* Constructing a sample 5-vertex weighted undirected graph:
          2          3
       0-----1-----------2
       |    / \          |
      6|  8/   \5        |7
       |  /     \        |
       3-----------4------
             9
    */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {
