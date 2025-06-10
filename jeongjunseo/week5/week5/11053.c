#include <stdio.h>
int arr[1000];
int main() {
	int n, count=0, num=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0;i < n;i++) {
		if (arr[i] > num)
		{
			count++;
			num = arr[i];
		}
	}
	printf("%d", count);
}