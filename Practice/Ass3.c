#include <stdio.h>
#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

void enque(int val) {
	if (rear == SIZE - 1) {
		printf("Queue is Full");
		return;
	}
	if (front == -1) {
		front = rear = 0;
	}
	else {
		rear = rear + 1;
	}
	queue[rear] = val;
}

int delque() {
	if (front == -1) {
		printf("Queue is empty");
		return -999;
	}
	int val = queue[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front++;
	}
	return val;
}

void display() {
	if (front == -1) {
		printf("Queue is Empty");
		return;
	}
	for (int i = front; i <= rear; i++) {
		printf("%d\t", queue[i]);
	}
	printf("\n");
}

int main() {
    // 1. Fill the queue
    printf("Enqueuing items...\n");
    enque(10);
    enque(20);
    enque(30);
    display(); // Expected: 10   20   30

    // 2. Delete an item
    printf("\nDequeuing one item...\n");
    int val = delque();
    printf("Deleted: %d\n", val); // Expected: 10
    display(); // Expected: 20   30

    // 3. Test empty/reset logic
    printf("\nEmptying the queue...\n");
    delque(); // Removes 20
    delque(); // Removes 30 (this should trigger front = rear = -1)
    display(); // Expected: Queue is Empty

    // 4. Test re-usability from start
    printf("\nEnqueuing again after reset...\n");
    enque(50);
    enque(65);
    display(); // Expected: 50 (at index 0)

    return 0;
}
