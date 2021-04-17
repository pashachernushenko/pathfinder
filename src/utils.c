#include "pathfinder.h"

//allocate square 2-D array
int **mx_arr_new(int size) {
    int **arr = malloc(size * (sizeof(int*)));
    for(int i = 0; i < size; i++)
        arr[i] = malloc(size * (sizeof(int)));
    //fill array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INT_MAX;
        }
    }
    return arr;
}

//get island index by name
int mx_get_idx(char **arr, char *name) {
    int idx = 0;
    while (arr[idx] != NULL) {
        if (!mx_strcmp(arr[idx], name))
            return idx;
        idx++;
    }
    return -1;
}

//get island name by index
char *mx_get_name(char **arr, int idx) {
    return arr[idx];
}

//check if string is in array already
bool mx_is_in_arr(char **arr, char *str) {
    for (int i = 0; arr[i] != NULL; i++)
        if(!mx_strcmp(str, arr[i]))
            return true;
    return false;
}
