#include "pathfinder.h"

//get size variable
int mx_get_size(int fd) {
    char *line = mx_strnew(15);
    int res = 0;
    mx_read_line(&line, 5, '\n', fd);
    res = mx_atoi(line);
    return res;
}

//initialize NULL-terminated strings array of given size
char **mx_hash_init(int size) {
    char **strings = malloc((size + 1) * sizeof(char*));
    for (int i = 0; i <= size; i++)
        strings[i] = NULL;
    return strings;
}

//fill hash with given names
void mx_hash_fill(char **islands, char **line, int *cnt) {
    //take first word. if not in arr yet, put it there
    if(!mx_is_in_arr(islands, line[0])) {
        islands[*cnt] = mx_strdup(line[0]);
        (*cnt) += 1;
    }
    //same for the second word
    if(!mx_is_in_arr(islands, line[1])) {
        islands[*cnt] = mx_strdup(line[1]);
        (*cnt) += 1;
    }
}

//fill matrix
void mx_matrix_fill(int **matrix, char *s_weight, char **points, int size, char **islands) {
    //get index and weight
    int x = mx_get_idx(islands, points[0]);
    int y = mx_get_idx(islands, points[1]);
    int weight = mx_atoi(s_weight);
    //fill matrix
    matrix[x][y] = weight;
    // matrix[y][x] = weight;
}


//fill hash table and matrix for algorithm
void mx_handle_input(char **islands, int fd, int size, int **matrix) {
    //read line until EOF
    char *line = mx_strnew(100);
    int cnt = 0;
    while (mx_read_line(&line, 5, '\n', fd) > 0) {
        //split by words
        char **a = mx_strsplit(line, ',');
        char **b = mx_strsplit(a[0], '-');
        mx_hash_fill(islands, b, &cnt);
        mx_matrix_fill(matrix, a[1], b, size, islands);
        mx_del_strarr(&a);
        mx_del_strarr(&b);
    }
    mx_strdel(&line);
}
