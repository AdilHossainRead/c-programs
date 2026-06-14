/*
Number of Ways to Reach Destination in Shortest Time
Last Updated : 18 Nov, 2025
Given an undirected weighted graph containing V vertices from 0 to V-1 represented as an adjacency list adj[][], where each adj[u] contains pairs [v, t] indicating there is an edge between nodes u and v such that it takes travel time of t to reach from u to v or v to u.

Find the number of distinct paths to reach (V-1)th node from 0th node in minimum amount of time.

Examples:

Input: adj[][] = [[[1, 2], [3, 5]],
                            [0, 2], [2, 3], [3, 3]],
                            [1, 3], [3, 4]],
                            [0, 5], [1, 3], [2, 4]]]

1

Output: 2 */
#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define MAX_V 10

// Helper function to find the unvisited vertex with the minimum distance
int getMinDistanceVertex(int dist[], bool visited[], int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int countShortestPaths(int graph[MAX_V][MAX_V], int V) {
    int dist[MAX_V];
    int ways[MAX_V];
    bool visited[MAX_V];

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        ways[i] = 0;
        visited[i] = false;
    }

    // Base cases for source node 0
    dist[0] = 0;
    ways[0] = 1;

    for (int count = 0; count < V - 1; count++) {
        int u = getMinDistanceVertex(dist, visited, V);
        if (u == -1) break;

        visited[u] = true;

        // Examine all neighbors of node u
        for (int v = 0; v < V; v++) {
            // Check if an edge exists
            if (graph[u][v] != 0 && !visited[v]) {
                int t = graph[u][v]; // travel time weight

                // Condition 1: Found a shorter path to neighbor v
                if (dist[u] + t < dist[v]) {
                    dist[v] = dist[u] + t;
                    ways[v] = ways[u]; // reset to inherit the cleaner count
                }
                // Condition 2: Found an alternative path of equal minimum time
                else if (dist[u] + t == dist[v]) {
                    ways[v] = ways[v] + ways[u]; // accumulate path options
                }
            }
        }
    }

    // Return the total ways recorded at the destination node (V-1)
    return ways[V - 1];
}

int main() {
    int V = 4;

    // Converting the example adjacency input into an adjacency matrix
    // Node 0 connects to 1 (wt: 2), 3 (wt: 5)
    // Node 1 connects to 0 (wt: 2), 2 (wt: 3), 3 (wt: 3)
    // Node 2 connects to 1 (wt: 3), 3 (wt: 4)
    // Node 3 connects to 0 (wt: 5), 1 (wt: 3), 2 (wt: 4)
    int graph[MAX_V][MAX_V] = {
        {0, 2, 0, 5},
        {2, 0, 3, 3},
        {0, 3, 0, 4},
        {5, 3, 4, 0}
    };

    int total_ways = countShortestPaths(graph, V);
    printf("Number of distinct paths with minimum time: %d\n", total_ways); // Expected Output: 2

    return 0;
}
