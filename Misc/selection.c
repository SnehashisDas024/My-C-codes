#include<stdio.h>
#define SIZE 10
void sort(int num[],int i,int n)
{
    int min,j,t;
	if(i>=n-1)
    return;
    min=i;
    for(j=i+1;j<n;j++){
        if(num[j]<num[i]){
        min=j;
        }
    }
    if (min!=i){
        t=num[i];
        num[i]=num[min];
        num[min]=t;
    }
    sort(num,++i,n);
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