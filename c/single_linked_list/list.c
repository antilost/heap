#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void new_list(list* L) {
    L->head = NULL;
    L->tail = NULL;
    L->length = 0;
}


void push_front(list* L, const int value) {
    node* new_node = (node*)malloc( sizeof(node) );
    new_node->value = value;
    new_node->next = L->head;
    L->head = new_node;
    if (L->tail == NULL) {
        L->tail = L->head;
    }
    L->length++;
}

void push_back(list* L, const int value) {
    node* new_node = (node*)malloc( sizeof(node) );
    new_node->value = value;
    new_node->next = NULL;
    if (L->tail != NULL) {
        L->tail->next = new_node;
    } else {
        L->head = L->tail = new_node;
    }
    L->length++;
}


void print_list(const list* L) {
    if (L->length == 0) {
        puts("List is empty");
        return;
    }

    printf("List has %d nodes\nL: ", L->length);
    node* p = L->head;
    while (p != NULL) {
        printf("%d -> ", p->value);
        p = p->next;
    }
    printf("NULL\n\n");
}