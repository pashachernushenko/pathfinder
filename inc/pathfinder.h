#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libmx.h"

/*--- Preprocessing --- */
int mx_get_size(int fd);
char **mx_hash_init(int size);
void mx_handle_input(char **islands, int fd, int size, int **matrix);

/*--- Algorithm --- */
void mx_floyd_warshall_init(int **path, int **cost, int **adjMatrix, int size);
void mx_floyd_warshall(int **path, int **cost, int **adjMatrix, int size);

/*--- Output --- */
void printPath(int **path, int v, int u);
void printSolution(int **path, int size);

/*--- Utils --- */
int **mx_arr_new(int size);
int mx_get_idx(char **arr, char *name);
char *mx_get_name(char **arr, int idx);
bool mx_is_in_arr(char **arr, char *str);
