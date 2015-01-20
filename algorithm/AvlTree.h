#ifndef _AvlTree_H_
#define _AvlTree_H_

#include <stdio.h>
#include "error.h"
#include <malloc.h>
#define ElementType int
#define Max(a, b) ((a) > (b) ? (a) : (b))

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrive(Position P);
void printTree(AvlTree T);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);


#endif

