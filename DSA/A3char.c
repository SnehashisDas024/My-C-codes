// Queue Program
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
char queue[MAX];
int front = 0;
int rear = 0;

void enque(char val)
{
    queue[rear++] = val;
}
char delque()
{
    return queue[front++];
}
void display()
{
    int i;
    printf("The queue is: ");
    for (i = front; i < rear; i++)
    {
        printf("%c ", queue[i]);
    }
    printf("\n");
}
void main()
{
    int i, j, val;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("Enter 1 to enque, 2 to delque, 3 to display the queue: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            if (rear == MAX)
            {
                printf("Queue is full");
            }
            else
            {
                printf("Enter the value: ");
                scanf(" %c", &val);
                enque(val);
            }
            break;
        case 2:
            if (front == rear)
            {
                printf("Queue is empty");
            }
            else
            {
                val = delque();
                printf("The popped element is: %c\n", val);
            }
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid input");
        }
        printf("\nDo you want to continue? y/n?");
        scanf(" %c", &ch);
    }
}