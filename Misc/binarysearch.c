#include <stdio.h>
int binarys(int arr[],int l,int u,int k){
    int mid;
    if(l<=u){
        mid=l+(u-l)/2;
        if (arr[mid]==k)
        return mid;
        if(arr[mid]>k)
        return binarys(arr,l,mid-1,k);
        if (arr[mid]<k)
        return binarys(arr,mid+1,u,k);
    }
    return -1;
}
void main(){
    int a[5],i,n;
    printf("Enter the elements");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    printf("Enter the key");
    scanf("%d",&n);
    if(binarys(a,0,4,n)==-1)
    printf("Not found");
    else
    printf("Found at position %d",binarys(a,0,4,n));
}