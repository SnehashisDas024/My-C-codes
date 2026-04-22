#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void enque(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) { // This is the Overflow condition. RAM is full and malloc returns NULL
        printf("Overflow: System out of memory!\n");
        return;
    }
	newNode->val = value;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

int delque() {
	if (head == NULL)	return -999;
	Node* temp = head;
	int value = temp->val;
	head = head->next;

	if (head == NULL) {
		tail = NULL;
	}
	
	size--;
	free(temp);
	return value;
}