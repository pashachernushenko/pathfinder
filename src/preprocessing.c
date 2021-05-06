#include "pathfinder.h"

//get size variable
static int get_size(int fd, const char *filename) {
    char *line = mx_strnew(15);
    int res = 0;
    
    if(!mx_read_line(&line, 5, '\n', fd))
        mx_check_size(filename);
    mx_check_length(line, 1);
    res = mx_atoi(line);
    mx_strdel(&line);
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
static void hash_fill(t_data *data, char **line, int *cnt) {
    //take first word. if not in arr yet, put it there
    if(!mx_is_in_arr(data->islands, line[0])) {
        mx_check_islands_num(*cnt, data->size, 0);
        data->islands[*cnt] = mx_strdup(line[0]);
        (*cnt) += 1;
    }
    //same for the second word
    if(!mx_is_in_arr(data->islands, line[1])) {
        mx_check_islands_num(*cnt, data->size, 0);
        data->islands[*cnt] = mx_strdup(line[1]);
        (*cnt) += 1;
    }
}

//fill matrix
static void matrix_fill(t_data *data, char *dist, char **points, int *sum) {
    //get index and weight
    int x = mx_get_idx(data->islands, points[0]);
    int y = mx_get_idx(data->islands, points[1]);
    int weight_next = mx_atoi(dist);
    mx_check_duplicates(data->weight[x][y]);
    mx_check_sum(sum, weight_next);
    //fill matrix
    data->weight[x][y] = weight_next;
    data->weight[y][x] = weight_next;
}

//fill hash table and matrix for algorithm
static void handle_input(t_data *data, int fd) {
    //read line until EOF
    char *line = mx_strnew(100);
    int cnt = 0, length_sum = 0, linenum = 1;

    while (mx_read_line(&line, 5, '\n', fd) > 0) {
        linenum++;
        //split by words
        char **a = mx_strsplit(line, ',');
        char **b = mx_strsplit(a[0], '-');
        mx_check_line(b[0], b[1], a[1], linenum);
        hash_fill(data, b, &cnt);
        matrix_fill(data, a[1], b, &length_sum);
        mx_del_strarr(&a);
        mx_del_strarr(&b);
    }
    char *end = "end";
    mx_read_line(&end, 5, '\n', fd);
    mx_strdel(&line);
    mx_check_islands_num(cnt, data->size, 1);
}

t_data *mx_get_data(char *file) {
    int fd = open(file, O_RDONLY);
    mx_check_file(fd, file);
    //allocate data structure
    t_data *data = malloc(sizeof(t_data));

    data->size = get_size(fd, file);
    //weight stores initial weights between islands
    data->weight = mx_arr_new(data->size);
    // "cost" and "path" stores shortest-cost/shortest-route information
    data->cost = mx_arr_new(data->size);
    data->path = mx_arr_list_new(data->size);
    data->islands = hash_init(data->size);
    //get hast table of island names and weights between them
    handle_input(data, fd);
    close(fd);
    return data;
}
