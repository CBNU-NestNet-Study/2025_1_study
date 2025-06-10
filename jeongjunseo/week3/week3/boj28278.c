/*
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int *arr;
	int top;

}stack;
void push(stack *st, int x) {
	st->arr[st->top] = x;
	st->top += 1;
	
}
int pop(stack* st) {
	if (st->top == 0)
		return -1;
	else { st->top--; return st->arr[st->top]; }
	
}
int size(stack* st) {
	return st->top;
}
int isEmpty(stack* st) {
	if (st-> top== 0)
		return 1;
	else return 0;
}
int print_top(stack* st) {
	if (st->top == 0)
		return -1;
	else {
		return st->arr[st->top-1];
	}
}
int main()
{
	stack* st;
	st = (stack*)malloc(sizeof(stack));
	st->top = 0;	//top을 0으로 초기화
	int command_size;
	scanf("%d", &command_size);
	int** command = (int**)malloc(sizeof(int*) * command_size);
	for (int i = 0;i < command_size;i++)
		command[i] = (int*)malloc(sizeof(int) * 2);
	st->arr = (int*)malloc(sizeof(int)*command_size);

	//명령어 할당받기
	for (int i = 0;i < command_size;i++) {
		scanf("%d", &command[i][0]);
		if (command[i][0] == 1)
			scanf("%d", &command[i][1]);
	}
	for (int i = 0;i < command_size;i++)
	{
		if (command[i][0] == 1) { push(st, command[i][1]); }
		else if (command[i][0] == 2) { printf("%d\n", pop(st)); }
		else if (command[i][0] == 3) { printf("%d\n", size(st)); }
		else if (command[i][0] == 4) { printf("%d\n", isEmpty(st)); }
		else if (command[i][0] == 5) { printf("%d\n", print_top(st)); }
	}
	

	for (int i = 0;i < command_size;i++) {
		free(command[i]);
	}
	free(command);
	free(st->arr);
	free(st);
}
*/