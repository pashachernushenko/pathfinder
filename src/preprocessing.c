#include "pathfinder.h"

//get size variable
static int get_size(int fd) {
    char *line = mx_strnew(15);
    int res = 0;
    mx_read_line(&line, 5, '\n', fd);
    res = mx_atoi(line);
    return res;
}

//initialize NULL-terminated strings array of given size
static char **hash_init(int size) {
    char **strings = malloc((size + 1) * sizeof(char*));
    for (int i = 0; i <= size; i++)
        strings[i] = NULL;
    return strings;
}

//fill hash with given names
static void hash_fill(char **islands, char **line, int *cnt) {
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
static void matrix_fill(int **weights, char *dist, char **points, char **islands) {
    //get index and weight
    int x = mx_get_idx(islands, points[0]);
    int y = mx_get_idx(islands, points[1]);
    int weight = mx_atoi(dist);
    //fill matrix
    weights[x][y] = weight;
    weights[y][x] = weight;
}

//fill hash table and matrix for algorithm
static void handle_input(char **islands, int fd, int **matrix) {
    //read line until EOF
    char *line = mx_strnew(100);
    int cnt = 0;
    while (mx_read_line(&line, 5, '\n', fd) > 0) {
        //split by words
        char **a = mx_strsplit(line, ',');
        char **b = mx_strsplit(a[0], '-');
        hash_fill(islands, b, &cnt);
        matrix_fill(matrix, a[1], b, islands);
        mx_del_strarr(&a);
        mx_del_strarr(&b);
    }
    mx_strdel(&line);
}

t_data *mx_get_data(char *file) {
    int fd = open(file, O_RDONLY);
    //allocate data structure
    t_data *data = malloc(sizeof(t_data));

    data->size = get_size(fd);
    //weight stores initial weights between islands
    data->weight = mx_arr_new(data->size);
    // "cost" and "path" stores shortest-cost/shortest-route information
    data->cost = mx_arr_new(data->size);
    data->path = mx_arr_new(data->size);
    data->islands = hash_init(data->size);
    //get hast table of island names and weights between them
    handle_input(data->islands, fd, data->weight);
    close(fd);
    return data;
}
