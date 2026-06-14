
/*Given a connected undirected weighted graph in the form of a 2D array where each row is of the type [start node, end node, weight] describing an edge, and also two integers (A, B). Return if the edge formed between (A, B) is a part of any of the Minimum Spanning Tree (MST) of the graph.
Input: graph = [[0 ,1, 20] , [0 , 2 , 5] , [ 0, 3, 10 ] , [ 2, 3, 10]], A = 2, B = 3
Output:  True*/


#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 100000000

// Graph representation using an Adjacency Matrix
struct Graph {
    int V;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// BFS function to check if a path exists between u and v using edges strictly lighter than 'weightLimit'
bool hasLighterPath(struct Graph* g, int src, int dest, int weightLimit) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Start BFS from the source vertex
    visited[src] = true;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];

        // If we reached the destination, a lighter path is confirmed
        if (u == dest) {
            return true;
        }

        for (int v = 0; v < g->V; v++) {
            int edgeWeight = g->adjMatrix[u][v];

            // Travel only if an edge exists, it's unvisited, and its weight is strictly less than the limit
            if (edgeWeight != 0 && !visited[v] && edgeWeight < weightLimit) {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }

    return false; // No lighter path found
}

// Function to check if a specific edge is part of any MST
void checkEdgeInMST(struct Graph* g, int u, int v) {
    int w = g->adjMatrix[u][v];

    if (w == 0) {
        printf("Edge (%d, %d) does not exist in the graph.\n", u, v);
        return;
    }

    // Check if a path exists between u and v using edges strictly less than w
    if (hasLighterPath(g, u, v, w)) {
        printf("Edge (%d, %d) with weight %d is NOT part of any MST.\n", u, v, w);
    } else {
        printf("Edge (%d, %d) with weight %d IS part of at least one MST.\n", u, v, w);
    }
}

int main() {
    struct Graph g;
    g.V = 4;

    // Initialize an empty adjacency matrix
    for (int i = 0; i < g.V; i++)
        for (int j = 0; j < g.V; j++)
            g.adjMatrix[i][j] = 0;

    // Constructing a sample cyclic graph
    // Creating a cycle: 0 - 1 - 2 - 0 with
