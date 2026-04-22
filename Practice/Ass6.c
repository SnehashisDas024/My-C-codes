#include <stdio.h>
#define SIZE 10

int arr[SIZE];
void binarySearch(int val) {
	int l = 0, h = SIZE - 1, mid;
	while (l <= h) {
		mid = l + (h - l) / 2;
		if (arr[mid] == val) {
			printf("Value is found\n");
			return;
		} else if (arr[mid] < val) {
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}
	printf("Value is not found\n");
}

void interpolationSearch(int val) {
	int l = 0, h = SIZE - 1, mid;
	while (l <= h) {
		mid = l + (((val - arr[l]) * (h - l)) / (arr[h] - arr[l]));
		if (arr[mid] == val) {
			printf("Value is found\n");
			return;
		} else if (arr[mid] < val) {
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}
	printf("Value is not found\n");
}