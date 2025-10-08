// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

static void print_list(const DList *list) {
    DListNode *node = dlist_head(list);
    int *data, i = 0;

    printf("DList size is %d\n", dlist_size(list));
    while (node) {
        data = dlist_data(node);
        printf("dlist.node[%03d]=%03d, %14p <- %p -> %p\n", i++, *data, node->prev, node, node->next);
        node = dlist_next(node);
    }
}

int main(int argc, char **argv) {
    DList list;
    DListNode *node;
    int *data, i;

    dlist_init(&list, free);

    for (i = 1; i < argc; i++) {
        data = malloc(sizeof(int));
        if (!data) return 1;
        *data = atoi(argv[i]);
        if (dlist_ins_next(&list, dlist_tail(&list), data) != 0) return 1;
    }

    print_list(&list);
    // Aquí puedes seguir con el resto de las operaciones como en tu código original...

    dlist_destroy(&list);
    return 0;
}

