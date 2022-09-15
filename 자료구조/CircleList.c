#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_list();

typedef struct node {
	int bomb;
	struct node *link;
} Node;

Node *CL = NULL;

int main() {

	Node *p, *new, *mid;
	new = (Node *)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	CL=new;

	new = (Node *)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	p = CL;
	CL->link=new;

	new = (Node *)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;


	p = p->link;
	p->link=new;
	new->link=CL;
	print_list();

	new = (Node *)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	p = p->link;
	p->link=new;
	new->link=CL;

	new = (Node *)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	p = p->link;
	new->link=CL;
	CL=new;
	p->link=new;
	print_list();


	mid = p;

	int bombCount = 0;
	do {
	bombCount += p->bomb;
	p=p->link;
	}
	while (p != mid);
		printf("Bomb Count is %d!!!\n\n", bombCount);

	Node *del;
	p = CL;
	while (p->link != CL)
		p=p->link;
	del = p->link;
	CL=del->link;
	p->link=del->link;
	free(del);
	print_list();

}

void print_list() {
	Node *p;
	p = CL;
	printf("( ");

	if (p!=NULL) {
		do {
			printf("%d ", p->bomb);
			p= p->link;
		} while (p!=CL);
	}

	printf(")\n\n");
}
