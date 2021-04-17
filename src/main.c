#include "pathfinder.h"

int main(int argc, char **argv) {
    //errcheck prototype
    if (argc <=1)
        exit(0);
    //open file
    t_data *data = mx_get_data(argv[1]);
    mx_floyd_warshall(data);
    mx_print_solution(data);
    return 0;
}
