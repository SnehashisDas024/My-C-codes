#include<stdio.h>
#define SIZE 10
void sort(int num[],int i,int n)
{
    int j,t;
	if(i>=n-1)
    return;
    for(j=0;j<n-i-1;j++){
        if(num[j+1]<num[j]){
        t=num[j];
        num[j]=num[j+1];
        num[j+1]=t;
    }
    sort(num,i+1,n);
}
}
void main() {
	int n,a[SIZE],x,y,pum,sorting;
	printf("Enter the number of element in the array: ");
	scanf("%d",&n);
	printf("Enter The Values: ");
	for(x=0;x<n;x++)
	scanf("%d",&a[x]);
	printf("Unsorted array:\t");
	for(x=0;x<n;x++)
	printf("%d\t",a[x]);
	sort(a,0,n);
	printf("Sorted array:\t");
	for(x=0;x<n;x++)
	printf("%d\t",a[x]);
}