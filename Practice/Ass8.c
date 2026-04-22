#include <stdio.h>

void merge(int* arr, int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	int brr[high - low + 1];
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			brr[k++] = arr[i++];
		} else {
			brr[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		brr[k++] = arr[i++];
	}
	while (j <= high) {
		brr[k++] = arr[j++];
	}

	for (int i = 0; i < k; i++)
	{
		arr[low + i] = brr[i];
	}
}

void mergesort(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int mid = (low + high) / 2;
	mergesort(arr, low, mid);
	mergesort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
