#include <iostream>

using namespace std;

struct Element {
    int value;
    Element* next;
};

void create_list(Element** head) {
    cout << "Creating list" << endl;
    *head = NULL;
}

void push_element(Element** head, int new_value) {
    cout << "Push new value " << new_value << endl;
    Element* new_element = new(Element);
    new_element->value = new_value;
    new_element->next = *head;
    *head = new_element;
}

int pop_element(Element** head) {
    cout << "Pop old element" << endl;
    int result = (*head)->value;
    Element* old_element_to_delete = *head;
    *head = (*head)->next;
    delete(old_element_to_delete);
    return result;
}

void print_list(Element** head) {
    Element* tmp = *head;
    cout << "L: ";
    while (tmp != NULL) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void reverse_list(Element** head) {
    cout << "Reverse list" << endl;
    Element *prev, *tmp;
    prev = NULL;
    while (*head != NULL) {
        tmp = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = tmp;
    }
    *head = prev;
}

int main() {
    Element* h;
    create_list(&h);
    push_element(&h, 10);
    print_list(&h);
    push_element(&h, 20);
    print_list(&h);
    push_element(&h, 30);
    print_list(&h);

    cout << "Old element: " << pop_element(&h) << endl;
    print_list(&h);

    push_element(&h, 40);
    print_list(&h);

    reverse_list(&h);
    print_list(&h);

    reverse_list(&h);
    print_list(&h);

    return 0;
}
