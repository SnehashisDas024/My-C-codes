#include <stdio.h>
#define M 500
int multiply(int x,int r[],int rs){
    int i,prod,carry=0;
    for(i=0;i<rs;i++){
        prod=r[i]*x+carry;
        r[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        r[rs]=carry%10;
        carry=carry/10;
        rs++;
    }
    return rs;
}
void factorial(int n){
    int r[M];
    r[0]=1;
    int x,rs=1;
    for (int x = 2; x <= n; x++)
    {
        rs=multiply(x,r,rs);
    }
    printf("Factorial of %d is:\n",n);
    for (int i = rs; i>=0; i--)
    {
        printf("%d",r[i]);
    }
    
    printf("\n");
}
void main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    factorial(n);
}