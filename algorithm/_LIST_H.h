#ifndef _LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef List Interger;
typedef List Group;
typedef Position Grouper;

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
void insertPoly2(ElementType Coefficient, ElementType Exponent, List L, Position P);
List mutiplePoly(List L1, List L2);
List expPoly(List L, int n);
//3.9 any length integer
Interger toInterger(char *s);
Interger addInterger(Interger a, Interger b);
Interger multipleInterger(Interger a, Interger b);
Interger expInterger(Interger a, int n);
void printInterger(Interger a);
//3.10 hot potato
Grouper createGrouper(void);
Group initGroup(int N);
void freeGrouper(Grouper g);
void runGroup(int N, int M);
//exec 3.12
void reverseList(List L);
//exec 3.15
void takeNodeToFirst(List L, Position P);
void insertIntoSelfAdj(ElementType x, List L);
Position findInSelfAdj(ElementType x, List L);
#endif
