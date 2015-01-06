#include <stdio.h>
#define ElementType int
#include "_Stack_H_by_array.h"
#include <malloc.h>
#include <stdlib.h>
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize) {
		printf("Stack Size Too Small");
		return NULL;
	}

	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		printf("out of space!");
		return NULL;
	}

	S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL) {
		printf("out of space!");
		return NULL;
	}

	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;	
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		printf("out of space!");
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S)) {
		printf("stack empty!");
		return -1;
	}
	else
		return S->Array[S->TopOfStack];
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("stack empty");
	else
		--S->TopOfStack;
}

ElementType TopAndPop(Stack S)
{
	if (IsEmpty(S)) {
		return -1;
	}
	else {
		return S->Array[S->TopOfStack--];
	}
}

//3.18a
void languageExamine(char *s)
{
	Stack S = CreateStack(100);

	while (*s != '\0') {
		switch (*s) {
			case 'b':
				if (*(s + 1) == 'e' || *(s + 2) == 'g' || *(s + 3) == 'i' || *(s + 4) == 'n')
					Push('b', S);
				break;
			case '(':
				Push('(', S);
				break;
			case '[':
				Push('[', S);
				break;
			case '{':
				Push('{', S);
				break;
			case 'e':
				if (*(s + 1) == 'n' || *(s + 2) == 'd')
					if (TopAndPop(S) != 'b') {
						printf("warning: losing \"begin\" before \"end\"\n");
						return;
					}
				break;
			case ')':
				if (TopAndPop(S) != '(') {
					printf("warning: losing \"(\" before\")\"\n");
					return;
				}
				break;
			case ']':
				if (TopAndPop(S) != '[') {
					printf("warning: losing \"[\" before\"]\"\n");
					return;
				}
				break;
			case '}':
				if (TopAndPop(S) != '{') {
					printf("warning: losing \"{\" before\"}\"\n");
					return;
				}
				break;
			default:
				break;
		}
		s++;
	}
	if (!IsEmpty(S))
		printf("Wrong Syntax! Something missing but tired to check:)\n");
	else
		printf("Correct Sytax\n");
	
	DisposeStack(S);
}

//3.19 postfixCalculator()
ElementType postfixCalculator(char *s[])
{
	Stack S = CreateStack(100);

	while (*s != NULL) {
		if (!strcmp(*s, "+"))
			Push(TopAndPop(S) + TopAndPop(S), S);
		else if (**s == '*')
			Push(TopAndPop(S) * TopAndPop(S), S);
		else if (**s == '-')
			Push(-TopAndPop(S) + TopAndPop(S), S);
		else if (**s == '/') {
			ElementType tmp = TopAndPop(S);
			Push(TopAndPop(S) / tmp, S);
		}
		else
			Push(atoi(*s), S);
		s++;
	}

	ElementType x = TopAndPop(S);
	DisposeStack(S);
	return x;
}
