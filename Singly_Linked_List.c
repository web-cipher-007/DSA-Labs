#include<stdio.h>
#include<stdlib.h>

struct SLL {
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

struct SLL* create_node(int element) {
    struct SLL *NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        return NULL;
    else {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void display() {
    struct SLL *temp;
    if (first == NULL) {
        printf("List Is Empty\n"); 
    } else {
        temp = first;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("NULL\n");
    }
}

void insert_at_beginning(int element) {
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    } else {
        if (first == NULL) { // List is empty
            first = last = NewNode;
        } else {
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning\n", first->data);
    }
}

void insert_at_end(int element) {
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    } else {
        if (first == NULL) { // List is empty
            first = last = NewNode;
        } else {
            last->next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted at the end\n", last->data);
    }
}

int delete_at_beginning() {
    int element = -1;
    struct SLL *temp;
    if (first == NULL) {
        printf("List Is Empty\n"); 
    } else if (first->next == NULL) { 
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    } else {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int delete_at_end() {
    int element = -1;
    struct SLL *temp;
    struct SLL *tempp;
    if (first == NULL) {
        printf("List Is Empty\n");
    } else if (first->next == NULL) { 
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    } else {
        temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        tempp = last;
        last = temp;
        element = tempp->data; 
        free(tempp);
        last->next = NULL;
    }
    return element;
}

void insert_at_position(int element, int POS) {
    struct SLL *NewNode = create_node(element);
    struct SLL *temp; 
    int i;           
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    } else {
        if (POS == 1) {
            NewNode->next = first;
            first = NewNode;
        } else {
            temp = first;
            for (i = 1; i < POS - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Invalid Position\n");
                free(NewNode);
            } else {
                NewNode->next = temp->next;
                temp->next = NewNode;
            }
        }
    }
}

int main() {
    insert_at_beginning(100);
    display();
    insert_at_beginning(200);
    display();
    insert_at_end(300);
    display();
    insert_at_position(250, 2); 
    display();
    return 0;
}