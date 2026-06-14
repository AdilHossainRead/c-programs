/*Given a weighted undirected graph represented using an adjacency list adj[][], where each adj[u] contains pairs of the form {v, w}, indicating that vertex u is connected to vertex v with an edge weight w. Find the distance of the second best Minimum Spanning Tree (MST) of this graph.

A second best MST is defined as the minimum-weight spanning tree whose total weight is strictly greater than the weight of the minimum spanning tree, but as small as possible. If no such spanning tree exists, return -1.

Examples:

Input: adj[][] = [[[1, 4], [2, 3]],
                          [[0, 4], [2, 1], [3, 5]],
                         [[0, 3], [1, 1], [3, 7], [4, 10]],
                         [[1, 5], [2, 7], [4, 2]],
                        [[2, 10], [3, 2]]]
Output: 12*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 100000000
#define MAX_V 10
#define MAX_E 30

struct Edge {
    int u, v, weight;
    bool in_mst;
};

// Graph representation for the original MST connections
int mstAdj[MAX_V][MAX_V];
bool hasMstEdge[MAX_V][MAX_V];

// Disjoint Set structural tracking arrays
int parent[MAX_V];
int rankArr[MAX_V];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

void unionSets(int i, int j) {
    int rootI = findSet(i);
    int rootJ = findSet(j);
    if (rootI != rootJ) {
        if (rankArr[rootI] < rankArr[rootJ]) {
            parent[rootI] = rootJ;
        } else if (rankArr[rootI] > rankArr[rootJ]) {
            parent[rootJ] = rootI;
        } else {
            parent[rootJ] = rootI;
            rankArr[rootI]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// DFS to precompute the maximum weight edge between all pairs in the MST
void findMaxEdgeInMST(int src, int u, int max_w, int max_edge[MAX_V][MAX_V], bool visited[], int V) {
    visited[u] = true;
    max_edge[src][u] = max_w;

    for (int v = 0; v < V; v++) {
        if (hasMstEdge[u][v] && !visited[v]) {
            int edge_w = mstAdj[u][v];
            int current_max = (edge_w > max_w) ? edge_w : max_w;
            findMaxEdgeInMST(src, v, current_max, max_edge, visited, V);
        }
    }
}

int findSecondBestMST(int V, struct Edge edges[], int E) {
    // Step 1: Compute Primary MST using Kruskal's
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    makeSet(V);

    int mst_weight = 0;
    int edges_selected = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            hasMstEdge[i][j] = false;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            mst_weight += edges[i].weight;
            edges[i].in_mst = true;

            // Build the MST graph adjacency maps
            hasMstEdge[u][v] = hasMstEdge[v][u] = true;
            mstAdj[u][v] = mstAdj[v][u] = edges[i].weight;

            edges_selected++;
        } else {
            edges[i].in_mst = false;
        }
    }

    // If the graph is disconnected and cannot form a spanning tree
    if (edges_selected != V - 1) return -1;

    // Step 2: For every pair (u, v), find the heaviest edge on their MST path
    int max_edge[MAX_V][MAX_V];
    for (int i = 0; i < V; i++) {
        bool visited[MAX_V] = {false};
        findMaxEdgeInMST(i, i, 0, max_edge, visited, V);
    }

    // Step 3: Iterate through non-MST edges to find the second-best MST weight
    int second_best_mst = INF;

    for (int i = 0; i < E; i++) {
        if (!edges[i].in_mst) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].weight;

            int max_mst_edge_weight = max_edge[u][v];
            int current_tree_weight = mst_weight + w - max_mst_edge_weight;

            // Enforce strict inequality constraint
            if (current_tree_weight > mst_weight && current_tree_weight < second_best_mst) {
                second_best_mst = current_tree_weight;
            }
        }
    }

    return (second_best_mst == INF) ? -1 : second_best_mst;
}

int main() {
    int V = 5;
    /* Map incoming adjacency lists cleanly into an Edge collection list:
       Node 0 connects to: 1 (wt: 4), 2 (wt: 3)
       Node 1 connects to: 0 (wt: 4), 2 (wt: 1), 3 (wt: 5)
       Node 2 connects to: 0 (wt: 3), 1 (wt: 1), 3 (wt: 7), 4 (wt: 10)
       Node 3 connects to: 1 (wt: 5), 2 (wt: 7), 4 (wt: 2)
       Node 4 connects to: 2 (wt: 10), 3 (wt: 2)
    */
    struct Edge edges[MAX_E] = {
        {0, 1, 4}, {0, 2, 3},
        {1, 2, 1}, {1, 3, 5},
        {2, 3, 7}, {2, 4, 10},
        {3, 4, 2}
    };
    int E = 7;

    int ans = findSecondBestMST(V, edges, E);
    printf("Weight of the second best MST: %d\n", ans); // Expected Output: 12

    return 0;
}
