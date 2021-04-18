#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libmx.h"

//data structure
typedef struct  s_data {
    int size;
    char **islands;
    int **weight;
    int **cost;
    int **path;
}               t_data;

/*--- Preprocessing ---*/
t_data *mx_get_data(char *file);

/*--- Algorithm ---*/
void mx_floyd_warshall(t_data *data);

/*--- Output ---*/
void mx_print_solution(t_data *data);


/*--- Utils ---*/
int **mx_arr_new(int size);
int mx_get_idx(char **arr, char *name);
char *mx_get_name(char **arr, int idx);
bool mx_is_in_arr(char **arr, char *str);

/*--- Errors ---*/
void mx_check_args(int argc);
void mx_check_file(int fd, const char *filename);
void mx_check_size(const char *filename);
void mx_check_length(const char *length, int linenum);
void mx_check_line( const char *island1, const char *island2,
                    const char *length, int linenum);
void mx_check_islands_num(int size_so_far, int size_max, int last);
void mx_check_duplicates(int weight_so_far);
void mx_check_sum(int *sum_so_far, int next);
