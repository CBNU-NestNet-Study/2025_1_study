#include <stdio.h>
#include <stdlib.h>
int n, k;
int arr[500001];
int tmp[500001] = { 0 };
int count = 0;
int ans = -1;

void merge(int *arr, int first, int mid, int last);
void merge_sort(int *a, int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}
void merge(int* a, int first, int mid, int last) {
	int i = first, j = mid + 1, t = first;

	while (i <= mid && j <= last) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}

	while (i <= mid) {
		tmp[t++] = arr[i++];
	}

	while (j <= last) {
		tmp[t++] = arr[j++];
	}

	for (int p = first; p <= last; p++) {
		arr[p] = tmp[p];
		count++;
		if (count == k) {
			ans = arr[p];
			break;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	int first = 0;
	int last = n-1;
	for (int i = 0; i < n;i++) {
		scanf("%d", &arr[i]);
	}
	merge_sort(arr, first, last);
	printf("%d", ans);
		
}