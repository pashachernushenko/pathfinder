#include "pathfinder.h"

// Total number of vertices in the `adjMatrix`
#define N 4
// Define infinity
#define I INT_MAX

int main() {
    /*--- TEST DATA PART ---*/
    // given adjacency representation of the matrix
    int adjMatrix[N][N] =
    {
        { 0, I, -2, I },
        { 4, 0, 3, I },
        { I, I, 0, 2 },
        { I, -1, I, 0 }
    };
 //allocate array
    int **padjMatrix = mx_arr_new(N);
//copy array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            padjMatrix[i][j] = adjMatrix[i][j];
    }

/*--- MAIN PART ---*/
    // Run Floyd–Warshall algorithm
    // "cost" and "path" stores shortest-cost/shortest-route information
    int **cost = mx_arr_new(N);
    int **path = mx_arr_new(N);

    mx_floyd_warshall(path, cost, padjMatrix, N);

    printSolution(path, N);

    return 0;
}