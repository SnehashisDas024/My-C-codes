#include<stdio.h>
#define SIZE 10
void main(){
    /*int a[3][2]={{10,20},{30,40},{50,60}};
    int *ptrv=*a;
    int *ptr2r[2]=a;
    int *ptr2a[3][2]=&a;
    printf("%u",ptrv);
    printf("%u",ptr2r);
    printf("%u",ptr2a);*/
    int a[8]={1,2,3,4,5,6,7,8};
    //printf("%d\n",a++);
    printf("%d\n",*a++);
    //printf("%d\n",&a++);
}