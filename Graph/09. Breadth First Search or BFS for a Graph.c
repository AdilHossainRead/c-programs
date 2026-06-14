
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Graph structure using an Adjacency Matrix
struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph matrix to 0
void initGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an undirected edge to the graph
void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Since the graph is undirected
}

// Core BFS Execution Function
void BFS(struct Graph* g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    // Enqueue the initial starting node and mark it as visited
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS Traversal Order: ");

    while (front < rear) {
        // Dequeue a vertex from the front of the queue
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Examine all neighbors of the current vertex
        for (int neighbor = 0; neighbor < g->numVertices; neighbor++) {
            // If an edge exists and the neighbor hasn't been visited yet
            if (g->adjMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor; // Enqueue the discovered neighbor
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices = 5;
    initGraph(&g, vertices);

    // Constructing a sample connected graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    // Run BFS starting from node 0
    BFS(&g, 0); // Expected Output: 0 1 2 3 4

    return 0;
}





// BFS for a single connected component
void bfsConnected(int adj[V][V], int src, int visited[V], int res[V], int *resSize) {
    int q[MAXQ];
    int front = 0, rear = 0;
    visited[src] = 1;
    q[rear++] = src;

    while (front < rear) {
        int curr = q[front++];
        res[(*resSize)++] = curr;

        // visit all the unvisited
        // neighbours of current node
        for (int x = 0; x < V; x++) {
            if (adj[curr][x] && !visited[x]) {
                visited[x] = 1;
                q[rear++] = x;
            }
        }
    }
}

// BFS for all components (handles disconnected graphs)
void bfs(int adj[V][V], int res[V], int *resSize) {
    int visited[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bfsConnected(adj, i, visited, res, resSize);
    }
}

