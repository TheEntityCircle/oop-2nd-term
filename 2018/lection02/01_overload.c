#include <stdio.h>

void func(char c)
{
	printf("func(char) called\n");
}

void func(int c)
{
	printf("func(int) called\n");
}

int main()
{
	func(10);
	func('a');
	return 0;
}
