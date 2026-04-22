#include <stdio.h>
#define SIZE 4
int cqueue[SIZE];
int front = -1, rear = -1;

void cenque(int val) {
	if ((rear + 1) % SIZE == front) {
		printf("Queue is Full");
		return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % SIZE;
	}
	cqueue[rear] = val;
}

int cdelque() {
	if (front == -1) {
		printf("Queue is Empty");
		return -999;
	}
	int val = cqueue[front];
	if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % SIZE;
	}
	return val;
}

void display() {
	int i = front, j = rear;
	if (front == -1) {
		printf("Queue is empty");
		return;
	}
	while (i != j) {
		printf("%d\t", cqueue[i]);
		i = (i + 1) % SIZE;
	}
	printf("%d\n", cqueue[i]);
}

int main() {
    printf("--- Initial Fill (3 items) ---\n");
    cenque(10);
    cenque(20);
    cenque(30);
    display(); // Expected: 10  20  30

    printf("\n--- Deleting 2 items ---\n");
    cdelque(); // 10 gone
    cdelque(); // 20 gone
    display(); // Expected: 30

    printf("\n--- Adding 3 items (Testing Wrap-Around) ---\n");
    // Since SIZE is 4, adding 3 more items after having 1 left 
    // will force 'rear' to wrap back to index 0 and 1.
    cenque(40);
    cenque(50);
    cenque(60); 
    display(); // Expected: 30  40  50  60

    printf("\n--- Testing Full Condition ---\n");
    cenque(70); // Should print "Queue is Full"

    printf("\n--- Emptying the whole queue ---\n");
    cdelque(); // 30
    cdelque(); // 40
    cdelque(); // 50
    cdelque(); // 60 (This should trigger front = rear = -1)
    display(); // Expected: Queue is empty

    return 0;
}
