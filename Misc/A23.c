#include <stdio.h>
#include <stdlib.h>
typedef struct Student
{
    char name[30];
    int roll;
    float marks;
}std;
void main(){
    std *ptr;
    int n=2;
    int i;
    ptr=(std*)malloc(n*sizeof(std));
    printf("Enter the name, roll and marks of each student\n");
    for(i=0;i<n;i++){
        scanf("%s%d%f",(ptr+i)->name,&(ptr+i)->roll,&(ptr+i)->marks);
    }
    printf("The entered values are:\n");
    for(i=0;i<n;i++){
        printf("%s %d %f\n",(ptr+i)->name,(ptr+i)->roll,(ptr+i)->marks);
    }

}
