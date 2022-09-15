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

void insert(Node *pre, char *name, int id);

void delete(char *name, int id);

int main() {

	Node *pre;

	insert(NULL, "ÀüÃ¢¿Ï", 1000);
	print_list();

	insert(NULL, "À±Àç¼®", 2000);
	print_list();

	pre = search_list_by_name("ÀüÃ¢¿Ï");
	insert(pre, "±è´ëÈñ", 3000);
	print_list();

	pre = search_list_by_id(1000);
	insert(pre, "±èµ¿¹Î", 4000);
	print_list();

	insert(NULL, "ÀÌ±ÔÇà", 5000);
	print_list();

	printf("Delete start\n");
	delete("ÀÌ±ÔÇà", 5000);
	print_list();

	delete("À±Àç¼®", 2000);
	print_list();

	delete("±èµ¿¹Î", 4000);
	print_list();

	delete("±è´ëÈñ", 3000);
	print_list();

	delete("ÀüÃ¢¾È", 1000);
	print_list();

	delete("ÀüÃ¢¿Ï", 1000);
	print_list();

	delete("±è´ëÈñ", 3000);
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

void insert(Node *pre, char *name, int id) {
	Node *new;

	if(pre==NULL){
		Node *new=(Node *)malloc(sizeof(Node));
		new->id=id;
		strcpy(new->name, name);
		new->link=head;
		head=new;

	}
	else{
		Node *new=(Node *)malloc(sizeof(Node));
		new->id=id;
		strcpy(new->name, name);
		new->link=pre->link;
		pre->link=new;

	}
}

void delete(char *name, int id) {
	Node *pre;
	Node *del;
	if (head == NULL) {
		printf("List is empty!!!\n");
		return;
	}

	if (strcmp(head->name, name)==0 && head->id==id) {
		del=head;
		head= del->link;
		free(del);
	}

	else {
		pre=head;

		while(pre->link != NULL){
			if (strcmp(pre->link->name, name)==0 && pre->link->id==id){
				del= pre->link;
				pre->link= del->link;
				free(del);
				return;
			}
			else
			{
				pre= pre->link;



			}

	}
		printf("No items\n");

	}
}
