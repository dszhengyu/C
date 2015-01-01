#ifndef _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType x, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void printList(List L);
void PrintLots(List L, List P);
void swapNode(List L, Position P1, Position P2);
List andList(List L1, List L2);
Position last(List L);
List orList(List L1, List L2);
List createList(void);
List addList(List L1, List L2);
void insertPoly(ElementType Coefficient, ElementType Exponent, List L);
#endif


