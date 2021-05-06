#include "pathfinder.h"

void print_list(t_list **list) {
    t_list *current = *list;
    printf("(");
    while (current != NULL) {
        printf("%d ", *(int*)current->data);
        current = current->next;     
    }
    printf(")");
}

int main(int argc, char **argv) {
    mx_check_args(argc);
    t_data *data = mx_get_data(argv[1]);
    printf("Got data\n");
    mx_floyd_warshall(data);
    printf("Algorithm done\n");

    for (int i = 0; i < data->size; i++) {
        for (int j = 0; j < data->size; j++) {
            print_list(&(data->path[i][j]));
            printf("\t");
        }
        printf("\n");
    }

    // mx_print_solution(data);
    // mx_free_data(data);
    return 0;
}
