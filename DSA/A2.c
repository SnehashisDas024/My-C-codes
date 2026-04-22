// #include <stdio.h>
// #include <stdlib.h>
// void push(int arr[], int max, int* top){
//     if(*top == max - 1){
//         printf("Stack overflow");
//     }
//     else{
//         int val;
//         printf("Enter the value to push: ");
//         scanf("%d",&val);
//         arr[++(*top)] = val;
//     }
// }
// int pop(int arr[], int* top){
//     if (*top == -1){
//         return -9999;
//     }
//     else{
//         return arr[(*top)--];
//     }
// }
// void display(int arr[], int* top){
//     int i;
//     for(i = 0;i <= *top; i++){
//         printf("%d ",arr[i]);
//     }
// }

// void main(){
//     int max,top,c;
//     int arr[100];
//     char ch = 'y';
//     printf("Enter the max stack capacity: ");
//     scanf("%d",&max);
//     top = -1;
//     while (ch == 'y'){
//         printf("Enter 1 to push, 2 to pop, 3 to display: ");
//         scanf("%d", &c);
//         switch (c)
//         {
//         case 1:
//             push(arr, max, &top);
//             // display(arr,&top);
//             break;
//         case 2:
//             printf("");
//             int val = pop(arr, &top);
//             if (val == -9999)
//             {
//                 printf("Stack underflow");
//             }
//             else
//             {
//                 printf("The element popped is: %d", val);
//             }
//             break;
//         case 3:
//             display(arr, &top);
//             break;
//         default:
//             printf("Invalid input");
//         }
//         printf("\nDo you want to continue? y/n? ");
//         scanf(" %c",&ch);
//     }    
// }
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
// void push(int arr[], int max, int* top){
//     if(*top == max - 1){
//         printf("Stack overflow");
//     }
//     else{
//         int val;
//         printf("Enter the value to push: ");
//         scanf("%d",&val);
//         arr[++(*top)] = val;
//     }
// }
// int pop(int arr[], int* top){
//     if (*top == -1){
//         return -9999;
//     }
//     else{
//         return arr[(*top)--];
//     }
// }
// void display(int arr[], int* top){
//     int i;
//     for(i = 0;i <= *top; i++){
//         printf("%d ",arr[i]);
//     }
// }
//
// void main(){
//     int max,top,c;
//     int arr[100];
//     char ch = 'y';
//     printf("Enter the max stack capacity: ");
//     scanf("%d",&max);
//     top = -1;
//     while (ch == 'y'){
//         printf("Enter 1 to push, 2 to pop, 3 to display: ");
//         scanf("%d", &c);
//         switch (c)
//         {
//         case 1:
//             push(arr, max, &top);
//             break;
//         case 2:
//             printf("");
//             int val = pop(arr, &top);
//             if (val == -9999)
//             {
//                 printf("Stack underflow");
//             }
//             else
//             {
//                 printf("The element popped is: %d", val);
//             }
//             break;
//         case 3:
//             display(arr, &top);
//             break;
//         default:
//             printf("Invalid input");
//         }
//         printf("\nDo you want to continue? y/n? ");
//         scanf(" %c",&ch);
//     }
// }

int stack[MAX];
int top = -1;
void push(int val)
{
    stack[++top] = val;
}
int pop()
{
    return stack[top--];
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}

void main()
{
    int c;
    int val;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("Enter 1 to push, 2 to pop, 3 to display: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (top == MAX - 1)
            {
                printf("Stack overflow");
            }
            else
            {
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
            }
            break;
        case 2:
            if (top == -1)
            {
                printf("Stack underflow");
            }
            else
            {
                val = pop();
                printf("The element popped is: %d", val);
            }
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid input");
        }
        printf("\nDo you want to continue? y/n? ");
        scanf(" %c", &ch);
    }
}