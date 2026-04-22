// #include <stdio.h>
// #include <stdlib.h>
// void display(int arr[],int n){
//     int i;
//     for (i=0;i<n;i++){
//         printf("%d\t",arr[i]);
//     }
// }
// void insert(int a[], int n, int pos, int value){
//     int i;
//     for (i=n-1;i>pos;i--){
//         a[i+1] = a[i];
//     }
//     a[pos] = value;
// }
// void delete(int a[], int n, int pos){
//     int i;
//     for(i=pos;i<n-1;i++){
//         a[i]=a[i+1];
//     }
// }
// int search(int arr[],int n,int target){
//     int i;
//     for(i=0;i<n;i++){
//         if(arr[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }
// void replace(int arr[], int pos, int target){
//     arr[pos] = target;
// }

//     void main()
// {
//     int a[100],n,i,j;
//     printf("Enter the number of elements in the array");
//     scanf("%d",&n);
//     for (i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     printf("1 to insert, 2 to delete, 3 to search and 4 to display and 5 to replace");
//     scanf("%d",&j);
//     switch (j)
//     {
//     case 1:
//         int tar,pos;
//         printf("Enter the value and the index position");
//         scanf("%d%d",&tar,&pos);
//         insert(a,n,pos,tar);
//         break;
//     case 2:
//         int pos;
//         printf("Enter the index position to delete");
//         scanf("%d",&pos);
//         delete(a,n,pos);
//         break;
//     case 3:
//         int tar,ans;
//         printf("Enter the value to search");
//         scanf("%d", &tar);
//         ans = search(a,n,tar);
//         if(ans == -1){
//             printf("Not found");
//         }
//         else{
//             printf("The element is found at index %d",ans);
//         }
//         break;
//     case 4:
//         printf("The array is as follows:\n");
//         display(a,n);
//         break;
//     case 5:
//         int pos,tar;
//         printf("Enter the position and value: ");
//         scanf("%d%d",&pos,&tar);
//         replace(a,pos,tar);
//     default:
//         break;
//     }
// }
#include <stdio.h>
#include <stdlib.h>
void insert(int a[], int *n, int target, int pos)
{
    int i;
    for (i = (*n) - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = target;
    (*n)++;
}
void deletev(int a[], int *n, int pos)
{
    int i;
    for (i = pos; i < *n; i++)
    {
        a[i] = a[i + 1];
    }
    (*n)--;
}
void replace(int a[], int target, int pos)
{
    a[pos] = target;
}
int search(int a[], int *n, int target)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        if (a[i] == target)
            return i;
    }
    return -1;
}
void display(int a[], int *n)
{
    int i;
    for (i = 0; i < (*n); i++)
    {
        printf("%d ", a[i]);
    }
}

void main()
{
    int a[100], n, i, j;
    int ch, pos, val;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // int t = 5;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter 1 to insert, 2 to delete, 3 to replace, 4 to search and 5 to display the array");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        printf("Enter 1 for beginning, 2 for end, 3 for position: ");
        scanf("%d", &ch);
        pos = (ch == 1) ? 0 : (ch == 2) ? n : -1;
        if (pos == -1)
        {
            printf("Enter the position: ");
            scanf("%d", &pos);
        }
        // printf("Enter the position you want to insert in");
        // scanf("%d", &pos);
        printf("Enter the value you want to insert: ");
        scanf("%d", &val);
        insert(a, &n, val, pos);
        display(a, &n);
        break;
    case 2:
        printf("Enter 1 for beginning, 2 for end, 3 for position: ");
        scanf("%d", &ch);
        pos = (ch == 1) ? 0 : (ch == 2) ? n : -1;
        if (pos == -1)
        {
            printf("Enter the position: ");
            scanf("%d", &pos);
        }
        // printf("Enter the position you want to delete: ");
        // scanf("%d", &pos1);
        deletev(a, &n, pos);
        display(a, &n);
        break;
    case 3:
        printf("Enter the position you want to replace with");
        // int pos2, val1;
        scanf("%d", &pos);
        printf("Enter the value you want to replace");
        scanf("%d", &val);
        replace(a, val, pos);
        display(a, &n);
        break;
    case 4:
        printf("Enter the value you want to search");
        int pos, val;
        scanf("%d", &val);
        pos = search(a, &n, val);
        if (pos == -1)
        {
            printf("Not found");
        }
        else
            printf("Found at index:%d", pos);
        break;
    case 5:
        display(a, &n);
        break;
    default:
        printf("Invalid input");
    }
}