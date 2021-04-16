#include "pathfinder.h"

// Total number of vertices in the `adjMatrix`
#define N 4
// Define infinity
#define I INT_MAX

int main(int argc, char **argv) {

    if (argc <=1)
        exit(0);

    int fd = open(argv[1], O_RDONLY);

    int size = mx_get_size(fd);
    // printf("Size: %d\n", size);
    int **matrix = mx_arr_new(size);

    char **islands = mx_hash_init(size);
    mx_handle_input(islands, fd, matrix);
    // mx_print_strarr(islands, "\n");

    // "cost" and "path" stores shortest-cost/shortest-route information
    int **cost = mx_arr_new(size);
    int **path = mx_arr_new(size);


    mx_floyd_warshall(path, cost, matrix, size);


    //     printf("\nPath Matrix:\n");
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         printf("%d\t", path[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\nSolution:\n");
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         printf("%d\t", cost[i][j]);
    //     }
    //     printf("\n");
    // }

    mx_print_solution(path, size, islands, cost, matrix);
    return 0;
}
