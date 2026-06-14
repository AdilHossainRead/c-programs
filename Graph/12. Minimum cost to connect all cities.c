
/*There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair a particular road.

Input is in the form of edges {u, v, w} where, u and v are city indices. w is the cost to rebuild the road between u and v. Print out the minimum cost to connect all the cities by repairing roads.

Examples:

Input: {{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {1, 5, 4},
            {2, 3, 5}, {2, 5, 7}, {3, 4, 6}}
Output: 10
Explanation: Refer the fig...*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 20
#define MAX_ROADS 50

// Structure to represent a road
struct Road {
    int u, v, cost;
};

// Disjoint Set structural tracking arrays
int parent[MAX_CITIES];
int rankArr[MAX_CITIES];

void makeSet(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]); // Path compression
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

// Comparator function to sort roads based on repair cost
int compareRoads(const void* a, const void* b) {
    struct Road* roadA = (struct Road*)a;
    struct Road* roadB = (struct Road*)b;
    return roadA->cost - roadB->cost;
}

int main() {
    int num_cities = 5; // Cities are 1, 2, 3, 4, 5
    int num_roads = 7;

    struct Road roads[MAX_ROADS] = {
        {1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {1, 5, 4},
        {2, 3, 5}, {2, 5, 7}, {3, 4, 6}
    };

    // Step 1: Sort all roads by cost
    qsort(roads, num_roads, sizeof(roads[0]), compareRoads);

    // Step 2: Initialize disjoint sets for components
    makeSet(num_cities);

    int min_total_cost = 0;
    int roads_built = 0;

    // Step 3: Process sorted edges
    for (int i = 0; i < num_roads; i++) {
        int u = roads[i].u;
        int v = roads[i].v;
        int cost = roads[i].cost;

        // Check if cities u and v are already connected
        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            min_total_cost += cost;
            roads_built++;

            // Optimization: An MST always has exactly V - 1 edges
            if (roads_built == num_cities - 1) {
                break;
            }
        }
    }

    printf("Minimum cost to connect all cities: %d\n", min_total_cost);

    return 0;
}
