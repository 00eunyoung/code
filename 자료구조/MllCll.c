#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int id;
	double grade;
} Student;

void strcpyPtr(char *src, char *dst) {


	for (; *dst++ = *src++;)
		;
}

int main(){
	Student *A,*B;

	A=(Student *)malloc(sizeof(Student));
	B=(Student *)calloc(1,sizeof(Student));

	A->grade=4.3;
	A->id=20190123;
	strcpyPtr("Kim",A->name);

	B->grade=3.8;
	B->id=20190789;
	strcpyPtr("Lee",B->name);

	printf("Student A: %s, %d, %lf\n",A->name,A->id,A->grade);
	printf("Student B: %s, %d, %lf\n",B->name,B->id,B->grade);


}
