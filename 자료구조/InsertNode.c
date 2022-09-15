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

int main() {
	Node *pre;

	insert(NULL, "��â��", 1000);
	print_list();

	insert(NULL, "���缮", 2000);
	print_list();

	pre = search_list_by_name("��â��");
	insert(pre, "�����", 3000);
	print_list();

	pre = search_list_by_id(1000);
	insert(pre, "�赿��", 4000);
	print_list();

	insert(NULL, "�̱���", 5000);
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
