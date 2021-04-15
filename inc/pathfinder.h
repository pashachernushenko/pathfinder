#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*--- Algorithm --- */
void mx_floyd_warshall_init(int **path, int **cost, int **adjMatrix, int size);
void mx_floyd_warshall(int **path, int **cost, int **adjMatrix, int size);
/*--- Output --- */
void printPath(int **path, int v, int u);
void printSolution(int **path, int size);

/*--- Utils --- */
int **mx_arr_new(int size);
