#include "pathfinder.h"

//prints vorder with '='
void mx_print_border(void) {
    for (int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}


//print path between two points
void mx_print_route(int **path, int v, int u, char **islands) {
    if (path[v][u] == v)
        return;
    mx_print_route(path, v, path[v][u], islands);
    mx_printstr(mx_get_name(islands, path[v][u]));
    mx_printstr(" -> ");
}

//print distance between two points
void mx_print_distance(int **path, int v, int u, char **islands, int **cost) {
    if (path[v][u] == v) {
        mx_printint(cost[path[v][u]][u]);
        return;
    }
    mx_print_distance(path, v, path[v][u], islands, cost);
    mx_printstr(" + ");
    mx_printint(cost[path[v][u]][u]);
}

// Function to print the shortest cost with path
// information between all pairs of vertices
void mx_print_solution(int **path, int size, char **islands, int **cost, int **matrix) {
    for (int v = 0; v < size; v++) {
        for (int u = v; u < size; u++) {
            if (u != v && path[v][u] != -1) {
                /*--- PRINT ROUTINE ---*/
                mx_print_border();
            //print path
                mx_printstr("Path: ");
                mx_printstr(mx_get_name(islands, v));
                mx_printstr(" -> ");
                mx_printstr(mx_get_name(islands, u));
                mx_printchar('\n');
            //print route
                mx_printstr("Route: ");
                mx_printstr(mx_get_name(islands, v));
                mx_printstr(" -> ");
                mx_print_route(path, v, u, islands);
                mx_printstr(mx_get_name(islands, u));
                mx_printchar('\n');
            //print distance 
                mx_printstr("Distance: ");

                //if only one node
                if (cost[v][u] == matrix[v][u])
                    mx_printint(cost[v][u]);
                else {
                //if multiple nodes
                    mx_print_distance(path, v, u, islands, matrix);
                    mx_printstr(" = ");
                    mx_printint(cost[v][u]);
                }
                mx_printchar('\n');

                mx_print_border();
                /*--- END PRINT ROUTINE ---*/
            }
        }
    }
}
