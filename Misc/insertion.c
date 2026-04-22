#include<stdio.h>
#define SIZE 10
int sort(int num[],int i)
{
	if(i==0)
	return 1;
	
	int key=num[i]; int j;
	j=i-1;
		while(j>=0 && key<num[j])
		{
			num[j+1]=num[j];
			j--;
		}
		num[j+1]=key;
        sort(num,i-1);
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
	sort(a,n);
	printf("Sorted array:\t");
	for(x=0;x<n;x++)
	printf("%d\t",a[x]);
}