#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

void reverse(char a[], char b[]) {
	int i;
	StackType s;
	init_stack(&s);
	for(i=0; a[i] != '\0'; i++)
		push(&s, a[i]);

	i=0;
	while(!is_empty(&s)){
		b[i++]=pop(&s);
	}
	b[i] = '\0';
}

int main() {
	char str[100];
	char rev[100];
	while (1) {
		printf("���ڿ��� �Է��ϼ���: ");
		fflush(stdout);
		scanf("%s", str);
		reverse(str, rev);
		printf("����: %s\t ����: %s\n", str, rev);
	}
}
