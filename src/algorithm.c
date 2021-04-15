#include "pathfinder.h"

//initialize needed arrays for algorithm
void mx_floyd_warshall_init(int **path, int **cost, int **adjMatrix, int size) {
    for (int v = 0; v < size; v++) {
    for (int u = 0; u < size; u++) {
        // initially, cost would be the same as the weight of the edge
        cost[v][u] = adjMatrix[v][u];
        if (v == u)
            path[v][u] = 0;
        else if (cost[v][u] != INT_MAX)
            path[v][u] = v;
        else
            path[v][u] = -1;
        }
    }
}

void mx_floyd_warshall(int **path, int **cost, int **adjMatrix, int size) {
    mx_floyd_warshall_init(path, cost, adjMatrix, size);
    for (int k = 0; k < size; k++) {
        for (int v = 0; v < size; v++) {
            for (int u = 0; u < size; u++) {
                // If vertex `k` is on the shortest path from `v` to `u`,
                // then update the value of `cost[v][u]` and `path[v][u]`
                if (    cost[v][k] != INT_MAX &&
                        cost[k][u] != INT_MAX
                        && cost[v][k] + cost[k][u] < cost[v][u]) {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
        }
    }
}



