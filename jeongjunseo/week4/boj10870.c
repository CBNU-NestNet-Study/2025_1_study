#include <stdint.h>
int pibonaci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return pibonaci(n - 1) + pibonaci(n - 2);
}
int main() {
	int n;
	int ans1=0;
	int ans2=1;
	scanf("%d", &n);
	printf("%d", pibonaci(n));
}