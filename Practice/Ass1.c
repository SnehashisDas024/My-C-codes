#include <stdio.h>
#define SIZE 10
int arr[SIZE];
int n = 0;

void insertAtBegin(int val) {
	if (n == SIZE) {
		printf("Full");
		return;
	}
	for (int i = n; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = val;
	n++;
}

void insertAtEnd(int val) {
	if (n == SIZE) {
		printf("Full");
		return;
	}
	else {
		arr[n++] = val;
	}
}

void insertAtPos(int val, int pos) {
	if (pos >= SIZE || n == SIZE || pos > n) {
		printf("ERROR");
	}
	for (int i = n; i > pos; i--) 
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = val;
	n++;
}

void deleteAtBegin() {
	if (n == 0) {
		printf("Empty");
		return;
	}
	else {
		for(int i = 0; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
	}
}

void deleteAtEnd() {
	if (n == 0) {
		printf("Empty");
		return;
	}
	n--;
}

void deleteAtPos(int pos) {
	if (n == 0) {
		printf("Empty");
		return;
	}
	if (pos == SIZE || pos >= n) {
		printf("BULUBULU\n");
		return;
	}
	for(int i = pos; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void display() {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main() {
	insertAtBegin(20);
	display();
	insertAtBegin(21);
	insertAtBegin(22);
	display();
	insertAtBegin(23);
	insertAtBegin(24);
	insertAtBegin(25);
	display();
	insertAtEnd(26);
	insertAtEnd(27);
	display();
	insertAtPos(28, 3);
	display();
	insertAtPos(29, 6);
	display();
	deleteAtBegin();
	display();
	deleteAtEnd();
	display();
	deleteAtPos(2);
	display();
	deleteAtPos(9);
	display();
	deleteAtEnd();
	display();
}