#ifndef _AvlTree_H_
#define _AvlTree_H_

#include <stdio.h>
#include <malloc.h>
#include "error.h"
#define AvlTreeElementType int
#define Max(a, b) ((a) > (b) ? (a) : (b))

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

#include "_Stack_H_by_list.h"

AvlTree MakeEmpty(AvlTree T);
Position Find(AvlTreeElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(AvlTreeElementType X, AvlTree T);
AvlTree Delete(AvlTreeElementType X, AvlTree T);
AvlTreeElementType Retrive(Position P);
void printTree(AvlTree T);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
//exec4.19
AvlTree insertNoRecursive(AvlTreeElementType X, AvlTree T);

struct AvlNode
{
	AvlTreeElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

#endif

