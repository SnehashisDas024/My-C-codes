#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int cque[MAX];
int front = 0;
int rear = 0;
void enque(int val){
    if ((front == 0 && rear == MAX) || (front != 0 && rear == front - 1))
    {
        printf("Queue is full");
    }
    else
    {
        cque[rear] = val;
        rear = rear == MAX? 0 : rear+1;
    }
}
int delque(){
    if(front == rear){
        return -9999;
    }
    else{
        int t = front;
        front = front == MAX - 1? 0 : front+1;
        return cque[t];
    }
}
void display(){
    int i;
    if (front == rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i = front; i < (rear >= front? rear : MAX); i++){
        printf("%d ", cque[i]);
    }
    if (rear < front){
        for (i = 0; i < rear; i++){
            printf("%d ", cque[i]);
        }
    }
    printf("\n");
}
// void main(){
//     int i,j,c;
//     printf("Enter 1 to enque, 2 to delque, 3 to display: ");
//     scanf("%d",&c);    
// }
void main()
{
    int choice, val;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter 1 to enque, 2 to delque, 3 to display the queue: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enque(val);
            break;

        case 2:
            val = delque();
            if (val != -9999)
                printf("The deleted element is: %d\n", val);
            else
                printf("Queue is empty\n");
            break;

        case 3:
            display();
            break;

        default:
            printf("Invalid input\n");
        }

        printf("\nDo you want to continue? y/n: ");
        scanf(" %c", &ch); // note the space before %c to consume leftover newline
    }
}
