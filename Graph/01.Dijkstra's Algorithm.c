
/*Given a weighted undirected graph and a source vertex src. We need to find the shortest path distances from the source vertex to all other vertices in the graph.
Note: The given graph does not contain any negative edge.

Examples:

Input: src = 0, adj[][] = [[[1, 4], [2, 8]],
                                            [[0, 4], [4, 6], [2,3]],
                                            [[0, 8], [3, 2], [1,3]],
                                            [[2, 2], [4, 10]],
                                            [[1, 6], [3, 10]]]*/

#include <stdio.h>
#include <stdbool.h>

#define INF 100000000
#define V 5 // Number of vertices based on the example input

// Function to find the vertex with the minimum distance value
// from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's shortest path algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // dist[i] holds the shortest distance from src to i
    bool visited[V]; // visited[i] is true if vertex i is finalized

    // Initialize all distances as INFINITY and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in visited, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current dist[v]
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t ", i);
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    /* Converting the given input example adjacency entries into a standard adjacency matrix:
       [[1, 4], [2, 8]] -> Node 0 connects to 1 (wt: 4), 2 (wt: 8)
       [[0, 4], [4, 6], [2, 3]] -> Node 1 connects to 0 (wt: 4), 4 (wt: 6), 2 (wt: 3)
       ...and so on.
    */
    int graph[V][V] = {
        {0, 4, 8, 0, 0},
        {4, 0, 3, 0, 6},
        {8, 3, 0, 2, 0},
        {0, 0, 2, 0, 10},
        {0, 6, 0, 10, 0}
    };

    int src = 0;
    dijkstra(graph, src);

    return 0;
}
