#include <stdio.h>
#define ElementType int
#include "_Queue_H.h"
#include <malloc.h>


int main(void)
{
	Queue Q = CreateListQueue();
	Enqueue(10, Q);
	Enqueue(13, Q);
	Enqueue(10, Q);
	Enqueue(10, Q);
	Enqueue(10, Q);
	Enqueue(80, Q);
	printQueue(Q);
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	printf("\n%d\t", FrontAndDequeue(Q));
	return 0;
}
