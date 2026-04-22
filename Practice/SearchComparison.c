#include <stdio.h>
void linearSearch(int arr[], int n, int target){
    int i, c = 0;
    for (i = 0; i < n; i++){
        if(arr[i] == target){
            printf("found: %d iterations.\n",c + 1);
            break;
        }
        c++;
    }
}
void binarySearch(int arr[], int n, int target){
    int l = 0, u = n - 1, mid, c = 0, flag = 0;
    while (l <= u){
        mid  = l + (u - l) / 2;
        if (arr[mid] == target){
            break;
        }
        else if (arr[mid] < target){
            l = mid + 1;
            c++;
        }  
        else{
            u = mid - 1;
            c++;
        }
    }
    if (flag == 1)
        printf("Target found: %d iterations.\n", c + 1);
    else
        printf("Not found");
}
void interpolationSearch(int arr[], int n, int target)
{
    int l = 0, u = n - 1, mid, c = 0, flag = 0;
    while (l <= u)
    {
        mid = l + (u - l) * (target - arr[l]) / (arr[u] - arr[l]);
        if (arr[mid] == target)
        {
            break;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
            c++;
        }
        else
        {
            u = mid - 1;
            c++;
        }
    }
    if (flag == 1)
        printf("Target found: %d iterations.\n", c + 1);
    else
        printf("Not found");
}
void main(){
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(a) / sizeof(int);
    linearSearch(a, size, 13);
    binarySearch(a, size,13);
    
}