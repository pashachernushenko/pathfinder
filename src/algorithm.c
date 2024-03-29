#include "pathfinder.h"

//initialize needed arrays for algorithm
static void floyd_warshall_init(t_data *data) {
    for (int v = 0; v < data->size; v++) {
        for (int u = 0; u < data->size; u++) {
            // initially, cost would be the same as the weight of the edge
            data->cost[v][u] = data->weight[v][u];
            if (v == u)
                data->path[v][u] = 0;
            else if (data->cost[v][u] != INT_MAX)
                data->path[v][u] = v;
            else
                data->path[v][u] = -1;
        }
    }
}

void mx_floyd_warshall(t_data *data) {
    floyd_warshall_init(data);
    for (int k = 0; k < data->size; k++) {
        for (int v = 0; v < data->size; v++) {
            for (int u = 0; u < data->size; u++) {
                // If vertex `k` is on the shortest path from `v` to `u`,
                // then update the value of `cost[v][u]` and `path[v][u]`
                if (data->cost[v][k] != INT_MAX
                    && data->cost[k][u] != INT_MAX
                    && data->cost[v][k] + data->cost[k][u] < data->cost[v][u]) {
                    data->cost[v][u] = data->cost[v][k] + data->cost[k][u];
                    data->path[v][u] = data->path[k][u];
                }
            }
        }
    }
}
