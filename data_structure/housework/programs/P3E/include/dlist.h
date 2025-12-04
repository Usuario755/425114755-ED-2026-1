// dlist.h
#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

// Macros
#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(node) ((node)->prev == NULL ? 1 : 0)
#define dlist_is_tail(node) ((node)->next == NULL ? 1 : 0)

#define dlist_data(node) ((node)->data)
#define dlist_next(node) ((node)->next)
#define dlist_prev(node) ((node)->prev)

// Estructuras
typedef struct DListNode_ {
    void *data;
    struct DListNode_ *next;
    struct DListNode_ *prev;
} DListNode;

typedef struct DList_ {
    int size;
    void (*destroy)(void *data);
    DListNode *head;
    DListNode *tail;
} DList;

// Prototipos
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListNode *node, const void *data);
int dlist_ins_prev(DList *list, DListNode *node, const void *data);
int dlist_remove(DList *list, DListNode *node, void **data);

#endif
// dlist.c


void dlist_init(DList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void dlist_destroy(DList *list) {
    void *data;
    while (dlist_size(list) > 0) {
        if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL)
            list->destroy(data);
    }
    memset(list, 0, sizeof(DList));
}

int dlist_ins_next(DList *list, DListNode *node, const void *data) {
    DListNode *new_node;
    if (node == NULL && dlist_size(list) != 0) return -1;
    if ((new_node = (DListNode *)malloc(sizeof(DListNode))) == NULL) return -1;
    new_node->data = (void *)data;

    if (dlist_size(list) == 0) {
        list->head = list->tail = new_node;
        new_node->prev = new_node->next = NULL;
    } else {
        new_node->next = node->next;
        new_node->prev = node;
        if (node->next == NULL)
            list->tail = new_node;
        else
            node->next->prev = new_node;
        node->next = new_node;
    }

    list->size++;
    return 0;
}

int dlist_ins_prev(DList *list, DListNode *node, const void *data) {
    DListNode *new_node;
    if (node == NULL && dlist_size(list) != 0) return -1;
    if ((new_node = (DListNode *)malloc(sizeof(DListNode))) == NULL) return -1;
    new_node->data = (void *)data;

    if (dlist_size(list) == 0) {
        list->head = list->tail = new_node;
        new_node->prev = new_node->next = NULL;
    } else {
        new_node->next = node;
        new_node->prev = node->prev;
        if (node->prev == NULL)
            list->head = new_node;
        else
            node->prev->next = new_node;
        node->prev = new_node;
    }

    list->size++;
    return 0;
}

int dlist_remove(DList *list, DListNode *node, void **data) {
    if (node == NULL || dlist_size(list) == 0) return -1;
    *data = node->data;

    if (node == list->head) {
        list->head = node->next;
        if (list->head == NULL)
            list->tail = NULL;
        else
            node->next->prev = NULL;
    } else {
        node->prev->next = node->next;
        if (node->next == NULL)
            list->tail = node->prev;
        else
            node->next->prev = node->prev;
    }

    free(node);
    list->size--;
    return 0;
}

