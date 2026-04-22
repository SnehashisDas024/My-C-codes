#include <stdio.h>
#include <stdlib.h>

typedef struct Poly {
	int expo;
	int coeff;
	// struct Node* next;
}poly;

void main() {
	poly p1[10], p2[10], p3[10];
	int n1, n2;
	int i;
	printf("Enter the number of terms in polynomial 1: ");
	scanf("%d", &n1);
	printf("Enter the values in descending order: ");
	for (i = 0; i < n1; i++)
	{
		scanf("%d%d", &p1[i].coeff, &p1[i].expo);
	}
	for (i = 0; i < n1 - 1; ++i)
	{
		printf("%dx^%d + ", p1[i].coeff, p1[i].expo);
	}
	printf("%dx^%d\n", p1[i].coeff, p1[i].expo);

	printf("Enter the number of terms in polynomial 2: ");
	scanf("%d", &n2);
	printf("Enter the values in descending order: ");
	for (i = 0; i < n2; i++)
	{
		scanf("%d%d", &p2[i].coeff, &p2[i].expo);
	}
	for (i = 0; i < n2 - 1; ++i)
	{
		printf("%dx^%d + ", p2[i].coeff, p2[i].expo);
	}
	printf("%dx^%d\n", p2[i].coeff, p2[i].expo);

	int j = 0, k = 0;
	i = 0;

	while (i < n1 && j < n2) {
		if (p1[i].expo == p2[j].expo) {
			p3[k].expo = p1[i].expo;
			p3[k++].coeff = p1[i++].coeff + p2[j++].coeff;
		} else if (p1[i].expo < p2[j].expo) {
			p3[k].expo = p2[j].expo;
			p3[k++].coeff = p2[j++].coeff;
		} else {
			p3[k].expo = p1[i].expo;
			p3[k++].coeff = p1[i++].coeff;
		}
	}
	while (i < n1) {
		p3[k].expo = p1[i].expo;
		p3[k++].coeff = p1[i++].coeff;
	}
	while (j < n2) {
		p3[k].expo = p2[j].expo;
		p3[k++].coeff = p2[j++].coeff;
	}

	printf("The final polynomial after sum is: ");

	for (i = 0; i < k - 1; i++)
	{
		printf("%dx^%d + ", p3[i].coeff, p3[i].expo);
	}
	printf("%dx^%d\n", p3[i].coeff, p3[i].expo);
}