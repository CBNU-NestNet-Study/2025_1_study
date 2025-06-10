#include<stdio.h>
#include<stdlib.h>

typedef struct _grade {
	int a;    // 서류 심사 성적
	int b;    // 면접 성적
} grade;

int compare(const void* x, const void* y) {
	grade A = *(grade*)x;
	grade B = *(grade*)y;

	if (A.a > B.a)
		return 1;
	else if (A.a < B.a)
		return -1;
	else return 0;
}

int main() {
	int T, N, cnt = 0;
	scanf("%d", &T);
	int i, j, k;

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		cnt = 0;   // cnt: 불합격자의 수
		grade* score = (grade*)malloc(sizeof(grade) * N);

		for (j = 0; j < N; j++)
			scanf("%d %d", &score[j].a, &score[j].b);

		qsort(score, N, sizeof(grade), compare);

		int save_b = score[0].b;

		for (j = 1; j < N; j++) {
			for (k = j - 1; k >= 0; k--) {
				if (score[j].b > save_b) {
					cnt++;
					break;
				}
				else {
					save_b = score[j].b;
					break;
				}
			}
		}
		printf("%d\n", N - cnt);
		free(score);
	}
	return 0;
}