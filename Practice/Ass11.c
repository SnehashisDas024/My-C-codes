#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

Node* head = NULL;
int size = 0;

void push(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) { // This is the Overflow condition. RAM is full and malloc returns NULL
        printf("Overflow: System out of memory!\n");
        return;
    }
	newNode->val = value;
	newNode->next = head;
	head = newNode;
	size++;
}

int pop() {
	if (head == NULL)	return -999;
	Node* temp = head;
	int value = temp->val;
	head = head->next;
	size--;
	free(temp);
	return value;
}