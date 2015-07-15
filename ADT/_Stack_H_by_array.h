#ifndef _Stack_H_by_array
#define _Stack_H_by_array

#include <stdio.h>
#include <malloc.h>
#include "AvlTree.h"
#define ElementType int

struct Node
{
	ElementType Position;
	PtrToNode Next;
};

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
void languageExamine(char *s);
ElementType postfixCalculator(char *s[]);
char **transInToPost(char *s[]);
#endif
