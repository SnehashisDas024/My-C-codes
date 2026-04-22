#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #define SIZE 100
char stack[100];
char str[100];
int top = -1;

void push(char ch) {
	// if (top == 100) {
	// 	printf("Stack is full");
	// 	return;
	// }
	// else {
	// 	stack[++top] = ch;
	// }
	stack[++top] = ch;
}

char pop() {
	// if (top == -1) {
	// 	printf("Stack is empty");
	// 	return '\0';
	// }
	// else {
	// 	return stack[top--];
	// }
	return stack[top--];
}

int precedence(char ch) {
	if (ch == '+' || ch == '-') {
		return 1;
	} else if (ch == '*' || ch == '/') {
		return 2;
	} else {
		return 0;
	}
}

int main() {
	char s[100];
	int idx = 0;
	printf("Enter the infix expression: ");
	gets(s);
	int len = strlen(s);
	s[len] = ')';
	s[len + 1] = '\0';
	push('(');
	for (int i = 0; s[i] != '\0'; i++) {
		if (isspace(s[i])) {
			continue;
		} else if (s[i] == '(') {
			push('(');
		} else if (isalnum(s[i])) {
			str[idx++] = s[i];
		} else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			if (precedence(s[i]) > precedence(stack[top])) {
				push(s[i]);
			}
			else {
				while (top != -1 && stack[top] != '(' && precedence(s[i]) <= precedence(stack[top])) {
					str[idx++] = pop();
				}
				push(s[i]);
			}
		} else {
			while (stack[top] != '(') {
				str[idx++] = pop();
			}
			pop();
		}
	}
	str[idx] = '\0';
	puts(str);
	return 0;
}