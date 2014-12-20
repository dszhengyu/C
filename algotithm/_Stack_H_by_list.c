#include <stdio.h>
#define ElementType int
#include "_Stack_H_by_list.h"
#include <malloc.h>

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;

	S = (Stack)malloc(sizeof(struct Node));

	if (S == NULL) {
		printf("out of space!");
		return NULL;
	}

	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
		printf("must create stack first!");
	else
		while (!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode tmp;

	tmp = (PtrToNode)malloc(sizeof(struct Node));
	
	if (tmp == NULL)
		printf("out of space");
	else {
		tmp->Element = X;
		tmp->Next = S->Next;
		S->Next = tmp;

	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	else {
		printf("stack empty");
		return -1;
	}
}

void Pop(Stack S)
{
	PtrToNode tmp;

	if (!IsEmpty(S)) {
		tmp = S->Next;
		S->Next = tmp->Next;
		free(tmp);
	}
	else
		printf("stack empty");
}