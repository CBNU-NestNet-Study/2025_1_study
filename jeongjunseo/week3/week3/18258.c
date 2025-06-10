#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int* arr;
	int front;
	int rear;

}que;
int isEmpty(que* q) {
	return q->front +1== q->rear;
}
void push(que* q, int x) {
	q->arr[q->rear] = x;
	q->rear += 1;
}
int pop(que* q) {
	if (isEmpty(q))
		return -1;
	int val = q->arr[q-> front+1];
	q->front++;
	return val;
}
int size(que* q) {
	return q->rear-(q->front +1);
}
int front_val(que* q) {
	if (isEmpty(q))
		return -1;
	return q->arr[q->front+1];
}
int back(que* q) {
	if (isEmpty(q))
		return -1;
	return q->arr[q->rear - 1];
}
int main()
{
	int size_command;
	scanf("%d", &size_command);
	getchar();
	char** command;
	command = (char**)malloc(sizeof(char*) * size_command);
	int* num = (int*)malloc(sizeof(int) * size_command);
	for (int i = 0;i < size_command;i++) {
		command[i] = (char*)malloc(sizeof(char) * 100);
		scanf("%s", command[i]);
		if (strcmp(command[i],"push")==0)
			scanf("%d", &num[i]);
	}
	
	que* q;
	q= (que*)malloc(sizeof(que));
	q->front = -1;
	q->rear = 0;
	q->arr = (int*)malloc(sizeof(int) * size_command);

	for (int i=0;i < size_command;i++)
	{
		if (strcmp(command[i],"push")==0)
			push(q, num[i]);
		else if (strcmp(command[i], "pop")==0)
			printf("%d\n", pop(q));
		else if (strcmp(command[i], "size")==0)
			printf("%d\n", size(q));
		else if (strcmp(command[i], "empty")==0)
			printf("%d\n", isEmpty(q));
		else if (strcmp(command[i], "front")==0)
			printf("%d\n", front_val(q));
		else if (strcmp(command[i], "back")==0)
			printf("%d\n", back(q));

		
	}
	for (int i = 0;i < size_command;i++)
		free(command[i]);
	free(command);
	free(num);
	free(q->arr);
	free(q);
}