#ifndef LAZYLIST
#define	LAZYLIST

typedef struct Head *List;
typedef struct Node *Node;

List createList();
void insertNodeToHead(List L, ElementType x);
void deleteNodeLazy(List L, Node n);
void printList(List L);

#endif


