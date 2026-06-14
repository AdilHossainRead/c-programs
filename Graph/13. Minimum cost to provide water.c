/*
Given an integer N, where N denotes the number of villages numbered 1 to N, an array wells[] where wells[i] denotes the cost to build a water well in the i'th city, a 2D array pipes in form of [X Y C] which denotes that the cost to connect village X and Y with water pipes is C. Your task is to provide water to each and every village either by building a well in the village or connecting it to some other village having water. Find the minimum cost to do so.

Examples:

Input: N=3, wells=[1, 2, 2], pipes=[[1 2 1], [2 3 1]]
Output: 3 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define MAX_E 500

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Disjoint Set structural arrays
int parent[MAX_V];
int rankArr[MAX_V];

void makeSet(int total_nodes) {
    for (int i = 0; i <= total_nodes; i++) {
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

// Comparator function to sort edges by weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int minCostToSupplyWater(int n, int wells[], int pipes[][3], int num_pipes) {
    struct Edge edges[MAX_E];
    int edge_count = 0;

    // 1. Add virtual edges from Node 0 to each village (representing wells)
    for (int i = 1; i <= n; i++) {
        edges[edge_count].src = 0;
        edges[edge_count].dest = i;
        edges[edge_count].weight = wells[i - 1]; // 0-indexed array mapping
        edge_count++;
    }

    // 2. Add the real pipe edges between villages
    for (int i = 0; i < num_pipes; i++) {
        edges[edge_count].src = pipes[i][0];
