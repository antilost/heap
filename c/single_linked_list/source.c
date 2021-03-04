#include "list.h"

/*
antilost@antilost:~/heap/c/single_linked_list$ ./a.out 
List is empty
List has 1 nodes
L: 15 -> NULL

List has 2 nodes
L: 23 -> 15 -> NULL

List has 3 nodes
L: 23 -> 15 -> 80 -> NULL

List has 5 nodes
L: 54 -> 23 -> 15 -> 47 -> NULL
*/

int main(void) {
    list L;
    
    new_list(&L);
    print_list(&L);

    push_front(&L, 15);
    print_list(&L);
    
    push_front(&L, 23);
    print_list(&L);
    
    push_back(&L, 80);
    print_list(&L);

    push_back(&L, 47);
    push_front(&L, 54);
    print_list(&L);

    return 0;
}