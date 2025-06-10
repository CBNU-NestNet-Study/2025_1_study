/*
#include <stdio.h>
#include <stdlib.h>
int size_command;
typedef struct {
	int front, rear;
	int *data;
}dack;
int isFull(dack* dq) {
	return (dq->rear + 1) % size_command == dq->front;
}
int isEmpty(dack* dq) {
	return dq->front == dq->rear;
}
int size(dack* dq) {
	if (dq->front <= dq->rear) {
		return dq->rear - dq->front;
	}
	else { return size_command - dq->front + dq->rear; }
}
void push_front(dack* dq, int x) {
	if (isFull(dq)) {
		return;
	}
	dq->front = (dq->front - 1 + size_command) % size_command;
	dq->data[dq->front] = x;
}
void push_back(dack* dq, int x) {
	if (isFull(dq)) {
		return;
	}
	dq->data[dq->rear] = x;
	dq->rear = (dq->rear + 1) % size_command;
	
}
int pop_front(dack* dq) {
	if (isEmpty(dq)) {
		return -1;
	}
	int value = dq->data[dq->front];
	dq->front = (dq->front + 1) % size_command;
	return value;
}
int pop_back(dack* dq) {
	if (isEmpty(dq)) {
		return -1;
	}
	
	dq->rear = (dq->rear - 1 + size_command) % size_command;
	int value = dq->data[dq->rear];
	return value;
}
int peek_front(dack* dq) {
	if (isEmpty(dq)) {
		return -1;
	}
	return dq->data[dq->front];
}

int peek_back(dack* dq) {
	if (isEmpty(dq)) {
		return -1;
	}
	return dq->data[(dq->rear - 1 + size_command) % size_command];
}
int main() {
	scanf("%d", &size_command);
	int **command;
	command = (int**)malloc(sizeof(int*)*size_command);   //command=
	for (int i = 0;i < size_command;i++)
		command[i] = (int*)malloc(sizeof(int)*2);
	for (int i = 0;i < size_command;i++)
	{
		scanf("%d", &command[i][0]);
		if (command[i][0] == 1 || command[i][0]==2)
			scanf("%d", &command[i][1]);
	}
	// 구조체 타입을 바로 쓰는게 아니라 maydack처럼 구조체 타입의 객체를 생성 후 쓸 수 있음.
	dack *mydack = (dack*)malloc(sizeof(dack)); //dack에 아직 배열크기 안정해졌으므로  data[]크기는 포함 안됨.
	mydack->data = (int*)malloc(sizeof(int) * (size_command+1));
	mydack->front = 0;
	mydack->rear = 0;
	//for (int i = 0;i < command;i++)
		//printf("%d %d", command[i][0], command[i][1]);
	for (int i=0;i < size_command;i++)
	{
		if (command[i][0] == 1)
		{
			push_front(mydack, command[i][1]);
		}
		else if (command[i][0] == 2)
		{
			push_back(mydack, command[i][1]);
		}
		else if (command[i][0] == 3)
		{
			printf("%d\n", pop_front(mydack));
		}
		else if (command[i][0] == 4)
		{
			printf("%d\n", pop_back(mydack));
		}
		else if (command[i][0] == 5)
		{
			printf("%d\n", size(mydack));
		}
		else if (command[i][0] == 6)
		{
			printf("%d\n",isEmpty(mydack));
		}
		else if (command[i][0] == 7) {
			printf("%d\n", peek_front(mydack));
		}
		else if (command[i][0] == 8) {
			printf("%d\n", peek_back(mydack));
		}
	}
	for (int i = 0;i < size_command;i++) {
		free(command[i]);
	}
	free(command);
	free(mydack->data);
	free(mydack);
}
*/