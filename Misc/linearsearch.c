#include <stdio.h>
int search(int arr[],int n,int i,int x){
    if(n<x){
        if(arr[i]==n){
            return i;
        }
        else{
            i++;
            return search(arr,n,i,x);
        }
    }
    else{
        return -1;
    }
}
void main(){
    int i,n,a,r;
    int arr[50];
    printf("Enter the number of terms");
    scanf("%d",&n);
    printf("Enter the terms");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What to find:");
    scanf("%d",&a);
    r=search(arr,a,0,n);
    if (r==-1)
    printf("Not found");
    else
    printf("found at index:%d",r);
}