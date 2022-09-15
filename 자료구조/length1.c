#include <stdio.h>

void printChars(char *str) {
	if(*str=='\0')
		return;
	else {
		printf("%c", *str);
		printChars(str+1);
	}
}

int main() {
	printChars("Hello, IoT World");
}
