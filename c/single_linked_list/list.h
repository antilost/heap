#ifndef LIST_H
#define LIST_H

struct node {
    struct node* next;
    int value;
};
typedef struct node node;

typedef struct {
    node* head; // голова
    node* tail; // хвост
    int length;
} list;

void new_list(list* L);
void push_front(list* L, const int value);
void push_back(list* L, const int value);
void print_list(const list* L);

#endif /* LIST_H */