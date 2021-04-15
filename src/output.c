#include "pathfinder.h"

void printPath(int **path, int v, int u) {
    if (path[v][u] == v)
        return;
    printPath(path, v, path[v][u]);
    printf("%d ", path[v][u]);
}
 
// Function to print the shortest cost with path
// information between all pairs of vertices
void printSolution(int **path, int size) {
    for (int v = 0; v < size; v++) {
        for (int u = 0; u < size; u++) {
            if (u != v && path[v][u] != -1) {
                printf("The shortest path from %d -> %d is (%d ", v, u, v);
                printPath(path, v, u);
                printf("%d)\n", u);
            }
        }
    }
}
