/*
Write a Menu Driven C Program to implement the following after creating a
Single Linked List(SLL)

a) Insert a node
(insert_at_beg / insert_at_end / insert_at_pos) in SLL

b) Delete a node
(del_from_beg / del_from_end / del_at_pos) from SLL

c) Traverse the
nodes of the list.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

void insertAtBeg() {
    Node* newnode;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    //newnode = (Node*)malloc(sizeof(Node)); //Unnecessary typecast. void* implicitly gets converted into any other type of pointer in C
    //newnode = malloc(sizeof(Node)); //Clean and standard Practice
    newnode = malloc(sizeof(*newnode)); // Best practice. Typesafe. If I later change the type of newnode, the sizeof(*newnode) will still be correct
    newnode->data = num;
    // if (head == NULL) {
    //     newnode->next = NULL;
    // }
    // else {
    //     newnode->next = head;
    // }
    // head = newnode; //This seems redundant...just the else statement and the final line will suffice
    newnode->next = head;
    head = newnode;
}

void insertAtEnd() {
    if (head == NULL) {
        insertAtBeg();
        return;
    }
    else {
        Node* newnode = malloc(sizeof(*newnode));
        int num;
        printf("\nEnter the data: ");
        scanf("%d", &num);
        newnode->data = num;
        Node* ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
    }
}

// void insertAtPos() {
//     Node* newnode = malloc(sizeof(*newnode));
//     int num, pos, i = 1;
//     printf("Enter the data: ");
//     scanf("%d", &num);
//     newnode->data = num;
//     printf("Enter the position to insert in: ");
//     scanf("%d", &pos);
//     Node* ptr = head;
//     while (i != pos-1 && ptr != NULL){
//         ptr = ptr->next;
//         i++; 
//     }
//     newnode->next = ptr->next;
//     ptr->next = newnode;
// }

void insertAtPos()
{
    Node *newnode = malloc(sizeof(*newnode));
    int num, pos, i = 1;
    printf("Enter the data: ");
    scanf("%d", &num);
    newnode->data = num;
    newnode->next = NULL;

    printf("Enter the position to insert in: ");
    scanf("%d", &pos);

    // Case: insert at head
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node *ptr = head;
    while (i != pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL)
    {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void main(){

}