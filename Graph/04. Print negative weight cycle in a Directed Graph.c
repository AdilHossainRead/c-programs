/*
Given a weighted directed graph consisting of V vertices and E edges. The task is to print the cyclic path whose sum of weight is negative. If there is no such path present then print "-1".

Input: V = 5, E = 5, Below is the graph:
Here, for the given negative cycle o/p (1->2->3->4->1) ; In fig there has to be Edge from 4-->1  not from 4-->0
*/
#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define MAX_VERTICES 20
#define MAX_EDGES 20

struct Edge {
    int u, v, weight;
};

void printNegativeCycle(int V, int E, struct Edge edges[]) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];

    // Initialize tracking structures
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    // Assume 0 as source node
    dist[0] = 0;

    // 1. Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // 2. Check for negative-weight cycle on V-th iteration
    int cycle_node = -1;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            // Negative cycle detected, save the affected node
            cycle_node = v;
            parent[v] = u; // Ensure the cyclic link is saved
            break;
        }
    }

    // If a cycle is detected
    if (cycle_node != -1) {
        // Go backwards V times to ensure we are inside the cycle
        for (int i = 0; i < V; i++) {
            cycle_node = parent[cycle_node];
        }

        // Store the cycle path
        int path[MAX_VERTICES];
        int path_length = 0;
        int current = cycle_node;

        // Traverse the cycle backward until we loop back to the start
        do {
            path[path_length++] = current;
            current = parent[current];
        } while (current != cycle_node && path_length < V);

        path[path_length++] = cycle_node; // Complete the loop sequence visually

        // Print the path in reverse order (to get forward direction)
        printf("Cyclic path: ");
        for (int i = path_length - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i > 0) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int main() {
    int V = 5;
    int E = 5;

    // Creating the graph structure matching your description
    // Edge (4->1) forms the negative cycle 1 -> 2 -> 3 -> 4 -> 1
    struct Edge edges[MAX_EDGES] = {
        {0, 1, 4},
        {1, 2, 2},
        {2, 3, 3},
        {3, 4, -9}, // Keeping weight low to ensure cycle sum remains negative
        {4, 1, 2}   // Corrected edge link pointing to 1 instead of 0
    };

    printNegativeCycle(V, E, edges);

    return 0;
}
