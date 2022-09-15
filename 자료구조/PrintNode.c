#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char name[20];
	int id;
	struct node *link;
} Node;

Node *head = NULL;

void print_list();

int main() {
	Node *new;
	new = (Node *)malloc(sizeof(Node));
	strcpy(new->name, "ÀüÃ¢¿Ï");
	new->id = 1000;
	new->link = NULL;
	head = new;

	new = (Node *)malloc(sizeof(Node));
	strcpy(new->name, "À±Àç¼®");
	new->id = 2000;
	new->link = NULL;
	head->link = new;

	new = (Node *)malloc(sizeof(Node));
	strcpy(new->name, "±è´ëÈñ");
	new->id = 3000;
	new->link = NULL;
	head->link->link = new;

	print_list();
}
void print_list() {
	Node *p;
	p=head;
	while(p != NULL){
		printf("(%s, %d) ", p->name, p->id);
		p=p->link;
	}
	printf("\n");
}
