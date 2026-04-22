#include <stdio.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int* arr, int low, int high) {
	int p = arr[low], i = low, j = high;
	while (i < j) {
		while (i < high && arr[i] <= p) {
			i = i + 1;
		}
		while (j > low && arr[j] > p) {
			j = j - 1;
		}
		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quicksort(int* arr, int low, int high) {
	if (low < high) {
		int part = partition(arr, low, high);
		quicksort(arr, low, part - 1);
		quicksort(arr, part + 1, high);
	}
}