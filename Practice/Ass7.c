#include <stdio.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubblesort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selectionSort(int arr[], int n) {
	int minIdx;
	for (int i = 0; i < n - 1; i++) {
		minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		swap(&arr[i], &arr[minIdx]);
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j > 0 ; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			} else {
				break;
			}
		}
	}
}