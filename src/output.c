#include "pathfinder.h"

//prints vorder with '='
static void print_border(void) {
    for (int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}

//prints path between two points
static void print_route(int **path, int v, int u, char **islands) {
    if (path[v][u] == v)
        return;
    print_route(path, v, path[v][u], islands);
    mx_printstr(mx_get_name(islands, path[v][u]));
    mx_printstr(" -> ");
}

//prints distance between two points
static void print_distance(int **path, int v, int u, char **islands, int **cost) {
    if (path[v][u] == v) {
        mx_printint(cost[path[v][u]][u]);
        return;
    }
    print_distance(path, v, path[v][u], islands, cost);
    mx_printstr(" + ");
    mx_printint(cost[path[v][u]][u]);
}

//print path
static void print_path_full(char **islands, int v, int u) {
    mx_printstr("Path: ");
    mx_printstr(mx_get_name(islands, v));
    mx_printstr(" -> ");
    mx_printstr(mx_get_name(islands, u));
    mx_printchar('\n');
}

//print route
static void print_route_full(char **islands, int **path, int v, int u) {
    mx_printstr("Route: ");
    mx_printstr(mx_get_name(islands, v));
    mx_printstr(" -> ");
    print_route(path, v, u, islands);
    mx_printstr(mx_get_name(islands, u));
    mx_printchar('\n');
}

//print distance
static void print_distance_full(t_data *data, int v, int u) {
    mx_printstr("Distance: ");
    //if only one node
    if (data->cost[v][u] == data->weight[v][u])
        mx_printint(data->cost[v][u]);
    else {
    //if multiple nodes
        print_distance(data->path, v, u, data->islands, data->weight);
        mx_printstr(" = ");
        mx_printint(data->cost[v][u]);
    }
    mx_printchar('\n');
}

void mx_print_solution(t_data *data) {
    for (int v = 0; v < data->size; v++) {
        for (int u = v; u < data->size; u++) {
            if (u != v && data->path[v][u] != -1) {
                print_border();
                print_path_full(data->islands, v, u);
                print_route_full(data->islands, data->path, v, u);
                print_distance_full(data, v, u);
                print_border();
            }
        }
    }
}
