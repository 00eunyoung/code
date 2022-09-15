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

Node *search_list_by_name(char *name);
Node *search_list_by_id(int id);

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

	new = search_list_by_name("À±Àç¼®");
	if(new != NULL){
		printf("name: %s id: %d\n",
				new->name, new->id);}

	new = search_list_by_id(1000);
	if(new != NULL){
		printf("name: %s id: %d\n",
				new->name, new->id);}

	new = search_list_by_name("Á¶ÀÌ");
	if(new != NULL){
		printf("name: %s id: %d\n",
				new->name, new->id);}

	new = search_list_by_id(3000);
	if(new != NULL){
		printf("name: %s id: %d\n",
				new->name, new->id);}
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

Node *search_list_by_name(char *name) {
	Node *p;
	p=head;

	while(p != NULL) {
		if(strcmp(p->name,name)==0)
			return p;
		p=p->link;

	}
	return NULL;
}

Node *search_list_by_id(int id) {
	Node *p;
	p=head;
	while(p != NULL) {
			if(p->id==id)
				return p;
			p=p->link;

		}
		return NULL;
}
