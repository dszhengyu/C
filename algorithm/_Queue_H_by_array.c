#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_Queue_H_by_array.h"
#define MinQueueSize (5)

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int value, Queue Q)
{
	if (++value == Q->Capacity)
		value = 0;
	return value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		printf("out of space!");
	else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

Queue CreateQueue(int MaxElements)
{
	Queue Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL) {
		printf("Out of Space");
		return NULL;
	}

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if (Q->Array == NULL) {
		printf("Out of Space");
		return NULL;
	}

	Q->Capacity = MaxElements;
	Q->Front = 1;
	Q->Rear = 0;
	Q->Size = 0;

	return Q;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL) {
		free(Q->Array);
		free(Q);
	}
}


ElementType Front(Queue Q)
{	
	if (!IsEmpty(Q))
		return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
	if (!IsEmpty(Q)) {
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	if (!IsEmpty(Q)) {
		Q->Size--;
		ElementType tmp = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
		return tmp;
	}
	else
		return -1;
}

void printQueue(Queue Q)
{
	int p = Q->Front;

	while (p != Q->Rear) {
		printf("%d\t", Q->Array[p]);
		p = Succ(p, Q);
	}
	printf("%d\t", Q->Array[Q->Rear]);
}
