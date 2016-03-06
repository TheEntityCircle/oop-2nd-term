#include <stdio.h>
#include "stack.h"

int main()
{
	stack s1;
	stack s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(5);
	s2.push(6);
	if(true){
		stack s3;
	}
	printf("%d %d\n",s1.pop(),s2.pop());
	printf("%d\n",s1.top);
	return 0;
}
