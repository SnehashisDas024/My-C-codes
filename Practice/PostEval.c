#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int val){
    stack[++top] = val;
}
int pop(){
    return stack[top--];
}
int calcOperator(char ch, int a, int b){
    if (ch == '+')
        return (a + b);
    else if (ch == '-')
        return (a - b);
    else if (ch == '*')
        return (a * b);
    else
        return (a / b);
}
int evaluation(char pex[]){
    int i, a, b, val;
    for (i = 0; pex[i] != '\0'; i++){
        if (pex[i] == '+' || pex[i] == '-' || pex[i] == '*' || pex[i] == '/')
        {
            b = pop();
            a = pop();
            val = calcOperator(pex[i], a, b);
            push(val);
        }
        else{
            a = (int)(pex[i] - '0');
            push(a);
        }
    }
    return stack[top];
}
void main(){
    char pex[MAX];
    printf("Enter the Postfix Expression: ");
    gets(pex);
    int result = evaluation(pex);
    printf("The result of the postfix expression is: %d",result);
}