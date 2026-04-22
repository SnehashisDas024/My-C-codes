#include <stdio.h>
#include <string.h>
#define SIZE 100
char stack[SIZE];
char result[SIZE];
int top = -1;
void push(char val)
{
    stack[++top] = val;
}
char pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}
// int peek(){
//  return stack[top];
// }
void main()
{
    char str[SIZE];
    int lent, i, idx = 0;
    char chv;
    printf("Enter the string expression: ");
    gets(str);
    lent = strlen(str);
    str[lent] = ')';
    str[lent + 1] = '\0';
    // puts(str);
    push('(');
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            result[idx++] = str[i];
        }
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while ((chv = pop()) != '(')
            {
                if (chv == '(')
                    break;
                result[idx++] = chv;
            }
        }
        else
        {
            while (precedence(stack[top]) >= precedence(str[i]))
            {
                chv = pop();
                result[idx++] = chv;
            }
            push(str[i]);
        }
    }
    // for (i = 0; i < idx; i++){
    //  printf("%c",result[i]);
    // }
    printf("Postfix expression: ");
    puts(result);
}