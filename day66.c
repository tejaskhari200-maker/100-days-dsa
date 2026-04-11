#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int V;               // Number of vertices

// DFS function to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {  // If edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent) {
                return 1; // Cycle detected
            }
        }
    }
    return 0;
}

// Function to check cycle in graph
int hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    if (hasCycle())
        printf("YES, cycle exists\n");
    else
        printf("NO, no cycle\n");

    return 0;
}