//输入应该为 名字 分数
//结尾时应输入 end 任意数
//排序使用冒泡。时间复杂度为O（n^2)
//郑宇 2015-1-18
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	char name[10];
	int score;
	Position Next;
};

void swapNode(List L, Position P1, Position P2);
void Insert(char *name, int score, List L, Position P);
void sortList(List L);

int main()
{
	char name[10];
	int score;

	List L = (Position)malloc(sizeof(struct Node));

	if (L == NULL) {
		printf("out of space!");
		return;
	}

	while (scanf("%9s%d", name, &score)) {
			if(!strcmp(name, "end"))
				break;
			Insert(name, score, L, L);		
	} 

	sortList(L);
	
	int prescore = 0;
	int i;
	L = L->Next;
	for (i = 0; L != NULL; L = L->Next) {
		i = prescore == L->score ? i : i +1;
		printf("No.%d, Name : %s, Score: %d\n", i, L->name, L->score);
		prescore = L->score;		
	}
	
	return 0;
}

void Insert(char *name, int score, List L, Position P)
{
	Position temp;

	temp = (Position)malloc(sizeof(struct Node));

	if (temp == NULL) {
		printf("out of space!");
		return;
	}
	strcpy(temp->name, name);
	temp->score = score;
	temp->Next = P->Next;
	P->Next = temp;
}

void sortList(List L)
{
	while (L->Next != NULL) {
		Position P = L->Next;
		while (P->Next != NULL) {
			if (P->Next->score > L->Next->score)
				swapNode(L, L->Next, P->Next);
			else
				P = P->Next;
		}
		L = L->Next;
	}
	
}

void swapNode(List L, Position P1, Position P2)
{
	Position pre1, pre2, tmp;
	
	pre1 = pre2 = NULL;
	
	while (L != NULL) {
		if (L->Next == P1)
			pre1 = L;
		if (L->Next == P2)
			pre2 = L;
		if (pre1 != NULL && pre2 != NULL)
			break;
		else 
			L = L->Next;
	}

	if (pre1 == NULL || pre2 == NULL) {
		printf("Swap Error");
		return;
	}

//attention, its order should be like this
//just consider P1 and P2 are continuous
//or I don't know, it just work!!!!!!!!!!!!!!!

	pre1->Next = P2;
	pre2->Next = P1;
	tmp = P1->Next;
	P1->Next = P2->Next;
	P2->Next = tmp;
}	

