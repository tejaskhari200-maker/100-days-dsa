#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if graph is directed
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 1; count <= n; count++) {
        int min = INT_MAX, u = -1;

        // Find unvisited node with minimum distance
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // Update distances of adjacent nodes
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}