#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
char name[20];
int id;
struct node *link;
} Node;

Node *head = NULL;

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
	head->link=new;

	new = (Node *)malloc(sizeof(Node));
	strcpy(new->name, "±è´ëÈñ");
	new->id = 3000;
	new->link = NULL;
	head->link->link=new;

	printf("ÀÌ¸§: %s ID: %d\n", head->name
	, head->id );
	printf("ÀÌ¸§: %s ID: %d\n", head->link->name
	, head->link->id);
	printf("ÀÌ¸§: %s ID: %d\n", head->link->link->name
	, head->link->link->id);
}
