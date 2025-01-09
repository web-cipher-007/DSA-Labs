#include<stdio.h>
#include<stdlib.h>
struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};
struct DLL *First,*Last=NULL;

struct DLL* create_node(int element) {
    struct DLL *NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    if (NewNode == NULL)
        return NULL;
    else {
        NewNode->data = element;
        NewNode->prev = NULL;
        NewNode->next=NULL;
        return NewNode;
    }
}
void display() {
    struct DLL *temp;
    if (First == NULL) {
        printf("List Is Empty\n"); 
    } else {
        temp = First;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("NULL\n");
    }
}

void insert_at_beginning(int element)
{
    struct DLL *NewNode = create_node(element);
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    }
    else
    {
        if (First==NULL)
        {
            First=Last=NewNode;
        }
        else
        {
            First->prev=NewNode;
            NewNode->next=First;
            First=NewNode;
        }
    }
}
void insert_at_end(int element)
{
    struct DLL *NewNode = create_node(element);
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    }
    else
    {
        if (First == NULL)
        {
            First = Last = NewNode;
        }
        else
        {
            Last->next=NewNode;
            NewNode->prev=Last;
            NewNode->next=NULL;
            Last=NewNode;
        }
    }
}
void insert_at_position(int element,int POS)
{
    struct DLL *NewNode;
    NewNode = create_node(element);
    struct DLL *temp,*tempp;
    int i;
    if (NewNode == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
    }
    else
    {
        if(POS<1)
        {
            printf(" Invalid Position");
        }
        else if(POS==1)
        {
            insert_at_beginning(element);
        }
        else
        {
            temp=First;
            for(i=1;i<POS-1;i++)
            {
                temp=temp->next;
            }
            tempp=temp->next;
            temp->next=NewNode;
            NewNode->prev=temp;
            tempp->prev=NewNode;
            NewNode->next=tempp;

        }
    }
}

int delete_at_beginning() {
    int element = -1;
    struct DLL *temp;
    if (First == NULL) {
        printf("List Is Empty\n"); 
    } else if (First->next == NULL) { 
        temp = First;
        First = Last = NULL;
        element = temp->data;
        free(temp);
        return element;
    } else {
        temp = First;
        First = First->next;
        First->prev=NULL;
        element=temp->data;
        free(temp);
        return element;
    }
}
int delete_at_end() 
{
    int element = -1;
    struct DLL *temp;
    if (First == NULL) {
        printf("List Is Empty\n"); 
    } else if (First->next == NULL) { 
        temp = First;
        First = Last = NULL;
        element = temp->data;
        free(temp);
        return element;
    }
    else
    {
        temp=Last;
        Last=Last->prev;
        Last->next=NULL;
        element=temp->data;
        free(temp);
        return element;
    }
}
int delete_at_position(int POS)
{
    struct DLL *temp,*tempp;
    int i;
    int element=-1;
    if(POS<1)
    {
        printf(" Invalid Position");
    }
    else if(POS==1)
    {
        delete_at_beginning();
    }
    else
    {
        temp=First;
        for(i=1;i<POS-1;i++)
        {
            temp=temp->next;
        }
        if(temp->next==Last)
        {
            delete_at_end();
        }
        else
        {
            tempp=temp->next;
            temp->next=tempp->next;
            (temp->next)->prev=temp;
            element=tempp->data;
            free(tempp);
            return element;
        }

    }
}
int main() 
{
    insert_at_beginning(100);
    display();
    insert_at_beginning(200);
    display();
    insert_at_end(300);
    display();
    insert_at_position(150,2);
    int deleted_value=delete_at_beginning();
    printf("Dleted value from beg is %d\n",deleted_value);
    display();
    deleted_value = delete_at_end();           
    printf("Deleted value from end: %d\n", deleted_value);
    display();
    deleted_value = delete_at_position(1);      
    printf("Deleted value from position 1: %d\n", deleted_value);
    display();
    return 0;
}