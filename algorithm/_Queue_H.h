#ifndef _Queue_H
#define _Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
struct QueueNode;
typedef struct QueueNode *Node;

int IsEmpy(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void printQueue(Queue Q);

Queue CreateListQueue();
#endif

