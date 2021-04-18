#include "pathfinder.h"

int main(int argc, char **argv) {
    mx_check_args(argc);
    t_data *data = mx_get_data(argv[1]);
    mx_floyd_warshall(data);
    mx_print_solution(data);
    mx_free_data(data);
    return 0;
}
