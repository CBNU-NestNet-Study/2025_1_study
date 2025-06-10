#include <stdio.h>

int main(void)
{
	long long S;
	long long N = 0;
	long long count = 0;

	scanf("%lld", &S);
	while (S > count)
	{
		N++;
		count = count + N;

		if (S < count)
		{
			N--;
			break;
		}
	}

	printf("%lld", N);
	return 0;
}