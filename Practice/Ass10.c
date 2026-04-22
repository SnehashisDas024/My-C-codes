#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

Node* head = NULL;
int size = 0;

void insertB(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = value;
	newNode->next = head;
	head = newNode;
	size++;
}

void insertE(int value) {
	if (head == NULL) {
		insertB(value);
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = value;
	newNode->next = NULL;
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	size++;
}

void insertP(int value, int pos) {
	if (pos <= 0 || pos > size + 1) {
		printf("Position is not possible\n");
		return;
	}
	if (head == NULL || pos == 1) {
		insertB(value);
		return;
	}
	if (pos == size + 1) {
		insertE(value);
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = value;
	Node* temp = head;
	int i = 1;
	while (temp->next != NULL && i < pos - 1) {
		temp = temp->next;
		i++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	size++;
}

void deleteB() {
	if (head == NULL)	return;
	Node* temp = head;
	head = head->next;
	free(temp);
	size--;
}

void deleteE() {
	if (head == NULL || head->next == NULL) {
		deleteB();
		return;
	}
	Node* temp = head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	Node* fr = temp->next;
	temp->next = NULL;
	free(fr);
	size--;
}

void deleteP(int pos) {
	if (pos <= 0 || pos > size) {
		printf("Position is not possible\n");
		return;
	}
	if (head == NULL || pos == 1) {
		deleteB();
		return;
	}
	if (pos == size) {
		deleteE();
		return;
	}
	Node* temp = head;
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
	}
	Node* fr = temp->next;
	temp->next = temp->next->next;
	free(fr);
	size--;
}

void traversal() {
	if (head == NULL) {
		printf("List is Empty\n");
		return;
	}
	Node* temp = head;
	while (temp != NULL) {
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("\n");
}