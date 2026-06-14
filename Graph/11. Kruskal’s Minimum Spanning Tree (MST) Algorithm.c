
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a connected, weighted graph
struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};

// Disjoint Set data structures
int parent[MAX_VERTICES];
int rankArr[MAX_VERTICES];

// Initialize a disjoint set element
void makeSet(int v) {
    parent[v] = v;
    rankArr[v] = 0;
}

// Find the representative root of a set (with Path Compression)
int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

// Union of two disjoint sets (by Rank)
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

// Comparator function to sort edges by weight using qsort
int compareEdges(const void* a, const void* b) {
    struct Edge* aEdge = (struct Edge*)a;
    struct Edge* bEdge = (struct Edge*)b;
    return aEdge->weight - bEdge->weight;
}

// Main execution function for Kruskal's Algorithm
void kruskalMST(struct Graph* graph) {
    struct Edge result[MAX_VERTICES]; // Array to store the selected MST edges
    int e = 0;                        // Index variable for result[]
    int i = 0;                        // Index variable for sorted edges

    // Step 1: Sort all graph edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating V sets
    for (int v = 0; v < graph->V; v++) {
        makeSet(v);
    }

    // Number of edges to be taken is equal to V-1
    while (e < graph->V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle
        struct Edge nextEdge = graph->edges[i++];

        int x = findSet(nextEdge.src);
        int y = findSet(nextEdge.dest);

        // If including this edge doesn't cause a cycle, include it in result
        // and take the union of both sets
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(x, y);
        }
        // Else discard the nextEdge
    }

    // Print the constructed MST
    int totalCost = 0;
    printf("Edges in the constructed MST:\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalCost += result[i].weight;
    }
    printf("Total Weight of Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    struct Graph graph;
    graph.V = 4; // Total number of vertices
    graph.E = 5; // Total number of edges

    // Edge 0-1
    graph.edges[0].src = 0; graph.edges[0].dest = 1; graph.edges[0].weight = 10;
    // Edge 0-2
    graph.edges[1].src = 0; graph.edges[1].dest = 2; graph.edges[1].weight = 6;
    // Edge 0-3
    graph.edges[2].src = 0; graph.edges[2].dest = 3; graph.edges[2].weight = 5;
    // Edge 1-3
    graph.edges[3].src = 1; graph.edges[3].dest = 3; graph.edges[3].weight = 15;
    // Edge 2-3
    graph.edges[4].src = 2; graph.edges[4].dest = 3; graph.edges[4].weight = 4;

    kruskalMST(&graph);

    return 0;
