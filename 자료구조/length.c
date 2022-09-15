#include <stdio.h>

int length(char *str) {
	if(*str=='\0')
		return 0;
	else
		return 1+length(str+1);
}

int main() {
	printf("%d\n", length("Hello, IoT World") );
}
