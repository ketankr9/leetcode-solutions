#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>

struct Queue{
	int front, rear, capa;
	int* arr;
};
bool addnew(){

	return true;
}

struct Queue initq(int s){
	struct Queue q;
	q.capa = s;
	q.front = 0;
	q.rear = 0;
	q.arr = (int*)malloc(sizeof(int)*s);
	return q;
}
bool addq(struct Queue* q, int val){
	if(q->rear == q->capa)
		return false;
	q->arr[q->front+q->rear] = val;
	q->rear++;
	return true;
}
int front(struct Queue* q){
	if(q->rear == 0){
		printf("Queue is empty");
		return -1;
	}
	return q->arr[q->front];
}
bool pop(struct Queue *q){
	if(q->rear == 0)
		return false;
	q->rear--;
	q->front++;
	return true;
}
int main(){
	struct Queue q = initq(3); // new Queue();
	printf("%d\n", addq(&q, 7));
	printf("%d\n", addq(&q, 6));
	printf("%d\n", addq(&q, 5));
	printf("%d\n", addq(&q, 4));
	printf("%d ", front(&q));
	printf("%d\n", pop(&q));
	printf("%d ", front(&q));
        printf("%d\n", pop(&q));
	printf("%d ", front(&q));
        printf("%d\n", pop(&q));
	printf("%d ", front(&q));
        printf("%d\n", pop(&q));
	printf("%d\n", addq(&q, 3));
        printf("%d\n", addq(&q, 2));
        printf("%d\n", addq(&q, 5));
        printf("%d\n", addq(&q, 8));
        printf("%d ", front(&q));
        printf("%d\n", pop(&q));
        printf("%d ", front(&q));
        printf("%d\n", pop(&q));
        printf("%d ", front(&q));
        printf("%d\n", pop(&q));
        printf("%d ", front(&q));
        printf("%d\n", pop(&q));
	return 0;
}
