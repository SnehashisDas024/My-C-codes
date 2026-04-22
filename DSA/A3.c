//Queue program
#include <stdio.h>
#include <stdlib.h>
void enqueue(int arr[], int* rear, int max, int value){
    if (*rear == max)
    {
        printf("Queue is full");
    }
    else{
        arr[(*rear)++] = value;
    }
}
int delqueue(int arr[], int* front, int* rear){
    if (*front == *rear){
        return -9999;
    }
    else{
        return arr[(*front)++];
    }
}
void display(int arr[], int* front, int* rear){
    int i;
    printf("The queue is: ");
    for ( i = *front; i < *rear; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main(){
    int a[100], max, i, j;
    int front = 0, rear = 0;
    char ch = 'y';
    printf("Enter the max length of the queue: ");
    scanf("%d",&max);
    while (ch == 'y')
    {
        printf("Enter 1 to enqueue, 2 to delqueue, 3 to display the queue: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the value to be entered: ");
            scanf("%d", &j);
            enqueue(a, &rear, max, j);
            // display(a, &front, &rear);
            break;
        case 2:
            printf("");
            int val;
            val = delqueue(a, &front, &rear);
            if (val == -9999)
            {
                printf("Queue is empty");
            }
            else
            {
                printf("%d", val);
            }
            break;
        case 3:
            display(a, &front, &rear);
            break;
        default:
            printf("Invalid input");
            break;
        }
        printf("\nDo you want to continue? y/n?");
        scanf(" %c", &ch);
    }
}

// // Queue program (character queue)
// #include <stdio.h>
// #include <stdlib.h>

// // ENQUE function
// void ENQUE(char arr[], int *rear, int max, char value)
// {
//     if (*rear == max)
//     {
//         printf("Queue is full\n");
//     }
//     else
//     {
//         arr[(*rear)++] = value;
//     }
// }

// // DELQUE function
// char DELQUE(char arr[], int *front, int *rear)
// {
//     if (*front == *rear)
//     {
//         return '\0'; // Special value for empty queue
//     }
//     else
//     {
//         return arr[(*front)++];
//     }
// }

// // DISPLAY function
// void DISPLAY(char arr[], int *front, int *rear)
// {
//     if (*front == *rear)
//     {
//         printf("Queue is empty\n");
//         return;
//     }

//     printf("The queue is: ");
//     for (int i = *front; i < *rear; i++)
//     {
//         printf("%c ", arr[i]);
//     }
//     printf("\n");
// }

// // Main function
// void main()
// {
//     char a[100]; // array of characters
//     int max, i;
//     int front = 0, rear = 0;
//     char ch = 'y', j;

//     printf("Enter the max length of the queue: ");
//     scanf("%d", &max);

//     while (ch == 'y')
//     {
//         printf("Enter 1 to ENQUE, 2 to DELQUE, 3 to DISPLAY: ");
//         scanf("%d", &i);

//         switch (i)
//         {
//         case 1:
//             printf("Enter the character to be enqueued: ");
//             scanf(" %c", &j); // Space before %c to skip newline
//             ENQUE(a, &rear, max, j);
//             break;

//         case 2:
//         {
//             char val = DELQUE(a, &front, &rear);
//             if (val == '\0')
//             {
//                 printf("Queue is empty\n");
//             }
//             else
//             {
//                 printf("Dequeued: %c\n", val);
//             }
//             break;
//         }

//         case 3:
//             DISPLAY(a, &front, &rear);
//             break;

//         default:
//             printf("Invalid input\n");
//         }

//         printf("Do you want to continue? y/n? ");
//         scanf(" %c", &ch); // Space to consume newline
//     }
// }
