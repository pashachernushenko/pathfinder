#include "pathfinder.h"

//allocate square 2-D array
int **mx_arr_new(int size) {
    int **arr = malloc(size * (sizeof(int*)));
    for(int i = 0; i < size; i++)
        arr[i] = malloc(size * (sizeof(int)));
    return arr;
}
