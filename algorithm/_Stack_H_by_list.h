#ifndef _Stack_H_by_list
#define _Stack_H_by_list

#include <stdio.h>
#include <malloc.h>
#include "AvlTree.h"
#define ElementType Position

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void makeStackEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

#endif
