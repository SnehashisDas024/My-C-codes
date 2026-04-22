#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) {
	stack[++top] = val;
}

int pop() {
	return stack[top--];
}

int operatorCalc(char ch, int a, int b) {
	if (ch == '+')	return a + b;
	else if (ch == '-') return a - b;
	else if (ch == '*')	return a * b;
	else {
		if (b == 0) {
			printf("Division by 0 is not possible");
			exit(0);
			return -999;
		}
		return a / b;
	}
}

int evaluate(char* pex) {
	int a, b;
	for (int i = 0; pex[i] != '\0'; i++) {
		char ch = pex[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			b = pop();
			a = pop();
			push(operatorCalc(ch, a, b));
		} else {
			push((int)(pex[i] - '0'));
		}
	}
	return stack[top];
}

void main() {
	char pex[MAX];
	printf("Enter the postfix expression: ");
	gets(pex);
	printf("\nPostfix Evaluation: %d", evaluate(pex));
}