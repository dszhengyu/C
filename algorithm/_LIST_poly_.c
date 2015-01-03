#include <stdio.h>
#include <malloc.h>
#define ElementType int
#include "_LIST_H.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	ElementType Coefficient;
	ElementType Exponent;
	PtrToNode Next;
};

List createList(void)
{
	List L = malloc(sizeof(struct Node));

	if (L != NULL) {
		L->Next = NULL;
	}

	return L;
}

void insertPoly(ElementType Coefficient, ElementType Exponent, List L)
{
	Position tmp = malloc(sizeof(struct Node));

	if (tmp == NULL) {
		printf("out of space");
		return;
	}

	tmp->Coefficient = Coefficient;
	tmp->Exponent = Exponent;
	tmp->Next = NULL;
	last(L)->Next = tmp;
}

Position last(List L)
{
	while (L->Next != NULL)
		L = L->Next;
	return L;
}

//exec 3.6
//the exponent of list goes from high to down
List addList(List L1, List L2)
{
	List L = createList();
	List L22; 
	
	if (L == NULL) {
		printf("out of space");
		return;
	}

	L1 = L1->Next;
	L2 = L2->Next;
	L22 = L2;
	while (L1 != NULL) {
		L2 = L22;
		while(L2 != NULL) {
			if (L1->Exponent == L2->Exponent) {
				insertPoly(L1->Coefficient + L2->Coefficient, L1->Exponent, L); 
				break;
			}
			else
				L2 = L2->Next;
		}

		if (L2 == NULL)
			insertPoly(L1->Coefficient, L1->Exponent, L);

		L1 = L1->Next;
	}

	return L;
}

void printList(List L)
{
	L = L->Next;
	while(L != NULL) {
		printf("coef = %d, exp = %d\t|", L->Coefficient, L->Exponent);
		L = L->Next;
	}
	putchar('\n');
	return;
}


void insertPoly2(ElementType Coefficient, ElementType Exponent, List L, Position P)
{
	Position tmp = malloc(sizeof(struct Node));

	if (P == NULL) {
		printf("Out of Space!");
		return;
	}

	tmp->Exponent = Exponent;
	tmp->Coefficient = Coefficient;
	tmp->Next = P->Next;
	P->Next = tmp;
}

//run O(M^2*N^2)
List mutiplePoly(List L1, List L2)
{
	List L = createList();
	List L22;
	if (L == NULL) {
		printf("Out of Space!");
		return;
	}

	L1 = L1->Next;
	L2 = L2->Next;
	L22 = L2;
	while (L1 != NULL) {
		L2 = L22;
		while (L2 != NULL) {
			ElementType coef = L1->Coefficient * L2->Coefficient;
			ElementType expo = L1->Exponent + L2->Exponent;
			Position P = L;

			while (P->Next != NULL) {
				if (P->Next->Exponent > expo) {
					insertPoly2(coef, expo, L, P);
					break;
				}
				else if (P->Next->Exponent == expo) {
					P->Next->Coefficient += coef;
					break;
				}
				else
					P = P->Next;
			}
			if (P->Next == NULL)
				insertPoly2(coef, expo, L, P);

			L2 = L2->Next;
		}
		L1 = L1->Next;
	}
	return L;
}

//exec 3.8
List expPoly(List L, int n)
{
	if (n <= 0) {
		List L = createList();
		insertPoly(1, 0, L);
		return L;
	}
	else {
		return mutiplePoly(L, expPoly(L, n - 1));
	}
}

//exec 3.9
Interger toInterger(char s[])
{
	long i = strlen(s) - 1;
	Interger a = createList();
	
	if(a == NULL) {
		printf("Out of Space!");
		return;
	}

	long exp = 0;
	while (i >= 0) {
		insertPoly(tolower(s[i--]) - 48, exp++, a);
	}
	return a;
}

Interger addInterger(Interger a, Interger b)
{
	Interger x = createList();
	if (x == NULL) {
		printf("Out of Space\n");
		return;
	}

	a = a->Next;
	b = b->Next;

	int c = 0;
	while (a != NULL && b!= NULL) {
		int sum = a->Coefficient +b->Coefficient;

		if (sum < 10) {
			insertPoly(sum + c, a->Exponent, x);
			c = 0;
		}
		else {
			sum -= 10;
			insertPoly(sum + c, a->Exponent, x);
			c = 1;
		}
		a = a->Next;
		b = b->Next;
	}
	while (a != NULL) {
		insertPoly(a->Coefficient, a->Exponent, x);
		a = a->Next;
	}
	while (b != NULL) {
		insertPoly(b->Coefficient, b->Exponent, x);
		b = b->Next;
	}
	return x;
}

Interger multipleInterger(Interger a, Interger b)
{
	Interger x, xbackup;
	x = xbackup = mutiplePoly(a, b);
	int c = 0;

	x = x->Next;
	while (x != NULL) {
		x->Coefficient += c;
		c = 0;
		while (x->Coefficient >= 10) {
			x->Coefficient -= 10;
			c++;
		}
		x = x->Next;
	}
	if (c) 
		insertPoly(c, last(xbackup)->Exponent + 1, xbackup);
	return xbackup;
}

Interger expInterger(Interger a, int n)
{
	if (n == 0) {
		return toInterger("1");
	}
	else {
		return multipleInterger(a, expInterger(a, n - 1));
	}
}

void printInterger(Interger a)
{
	if (a->Next == NULL)
		return;
	else {
		ElementType x = a->Next->Coefficient;
		printInterger(a->Next);
		printf("%d", x);
		return;
	}
}
