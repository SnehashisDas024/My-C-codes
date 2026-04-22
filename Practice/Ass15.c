// #include <stdio.h>
// #define SIZE 10
// int map[SIZE];

// void insertVal(int value) {
// 	int idx = value % SIZE;
// 	while (map[idx] != -999) {
// 		idx = (idx + 1) % SIZE;
// 	}
// 	map[idx] = value;
// }

// void display() {
// 	for (int i = 0; i < SIZE; i++) {
// 		printf("%d\t", map[i]);
// 	}
// }

// void main() {
// 	int val;
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		map[i] = -999;
// 	}
// 	for (int i = 0; i < SIZE; i++) {
// 		printf("Enter a value: ");
// 		scanf("%d", &val);
// 		insertVal(val);
// 	}
// 	display();
// }

#include <stdio.h>

#define SIZE 10
#define EMPTY -999

int map[SIZE];

// Division Hash Function with Linear Probing
void insertVal(int value) {
    int idx = value % SIZE;
    int startIdx = idx;

    // Linear Probing: Look for the next empty slot
    while (map[idx] != EMPTY) {
        idx = (idx + 1) % SIZE;
        
        // Safety check: if we've circled back, the table is full
        if (idx == startIdx) {
            printf("Table Overflow: Could not insert %d\n", value);
            return;
        }
    }
    map[idx] = value;
}

// Function to find a value in the hash table
int search(int value) {
    int idx = value % SIZE;
    int startIdx = idx;

    while (map[idx] != EMPTY) {
        if (map[idx] == value) return idx;
        idx = (idx + 1) % SIZE;
        if (idx == startIdx) break; // Searched the whole table
    }
    return -1; // Not found
}

void display() {
    printf("\nIndex\tValue\n");
    for (int i = 0; i < SIZE; i++) {
        if (map[i] == EMPTY)
            printf("%d\t---\n", i);
        else
            printf("%d\t%d\n", i, map[i]);
    }
}

int main() {
    int val;
    
    // Initialize table
    for (int i = 0; i < SIZE; i++) {
        map[i] = EMPTY;
    }

    // Input 10 values
    printf("Enter %d values to store in the hash table:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &val);
        insertVal(val);
    }

    display();

    // Example Search
    printf("\nEnter a value to search: ");
    scanf("%d", &val);
    int pos = search(val);
    if (pos != -1)
        printf("Value found at index %d\n", pos);
    else
        printf("Value not found.\n");

    return 0;
}
