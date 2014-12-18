#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct 
{
	float coef;
	int exp;
} ElemType;

typedef struct poly
{
	ElemType data;
	struct poly *next;
}Poly;

Poly *create_Poly_LinkList(void);
void output_Poly_LinkList(Poly *L);
Poly *add_poly(Poly *La, Poly *Lb);

int main()
{
}

//create a special head node, whose coef and exp are 0
Poly *create_Poly_LinkList(void)
{
	Poly *newpoly = (Poly *)malloc(sizeof(Poly));
	newpoly->data.coef = 0;
	newpoly->data.exp = 0;
	newpoly->next = NULL;
	return newpoly;
}

//print the list
void output_Poly_LinkList(Poly *L)
{
	while((L = L->next) !=  NULL)
		printf("%f^%d%s", L->data.coef, L->data.exp, ((L->next != NULL) ? " + " : ""));
}

//create a new list to store the result of adding of the two list
Poly *add_poly(Poly *La, Poly *Lb)
{
	Poly *L = create_Poly_LinkList();
	Poly *ptr = L;
	while ((La = La->next) != NULL) {
		int expa = La->data.exp;
		float coefa = La->data.coef;
		while ((Lb = Lb->next) != NULL) {
			int expb = La->data.exp;
			float coefb = Lb->data.coef;
			if (expb == expa) {
				float coefsum = coefa + coefb;
				if (coefsum != 0) {
					Poly *temp = (Poly *)malloc(sizeof(Poly));
					temp->data.exp = expa;
					temp->data.coef = coefsum;
					temp->next = NULL;
					ptr->next = temp;
					ptr = temp;
					break;
				}
			}
		}
		if (ptr->data.exp == expa){//deal with the condition that Lb don't contain the node with same exp with La, beacuse La is longer than Lb
			Poly *temp = (Poly *)malloc(sizeof(Poly));
			temp->data.exp = expa;
			temp->data.coef = coefa;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
		}
	}

	return L;
}