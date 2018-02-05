#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class stack
{
public:
	void push(int a);
	int pop();
	void clear();
	stack(int size);
	~stack();
private:
	int top;
	int size;
	int* data; // not c++ style
};

stack::stack(int stack_size)
{
	printf("stack::stack() called\n");
	this->top = 0;
	this->size = stack_size;
	this->data = (int*)malloc(sizeof(int)*stack_size); // not nice, not c++ style
}

stack::~stack()
{
	printf("stack::~stack() called\n");
	free(this->data);
}

void stack::clear()
{
	this->top = 0;
}

void stack::push(int a)
{
	if(this->top == this->size)
	{
		printf("ERROR: Stack overflow! Can not push %d\n", a);
		return;
	}
	this->data[this->top] = a;
	this->top++;
}

int stack::pop()
{
	if(this->top == 0)
	{
		printf("ERROR: Stack empty, can not pop\n");
		return -1; // really bad design choice
	}
	this->top--;
	return this->data[this->top];
}



int main()
{
	stack s1(2);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	printf("Data from s1: %d\n", s1.pop());
	printf("Data from s1: %d\n", s1.pop());
	s1.pop();

    /*
	stack s2(10);
	s2.push(1);
	s2.push(2);
	s2.push(3);
	printf("Data from s2: %d\n", s2.pop());
	s2.top = 1;
	printf("Data from s2: %d\n", s2.pop());
    */

	return 0;
}
