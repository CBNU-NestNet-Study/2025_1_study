#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int *arr = (int*)malloc(sizeof(int) * (n+1));
	int* sum = (int*)malloc(sizeof(int) * (n+1));
	sum[0] = 0;
	arr[0] = 0;
	for (int k = 1;k <= n;k++) {
		scanf("%d", &arr[k]);
		sum[k] = arr[k]+sum[k-1];
	}
	
	for (int k = 0;k < m;k++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j]-sum[i-1]);
	}
	free(arr);
	return 0;
}