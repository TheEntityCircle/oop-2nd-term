#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class stack
{
// Class methods, they are declared as 'public' (so, 'visible' to the code outside of the class)
public:
	// Constructor: inits the stack of the given size, allocates memmory
	stack(int size);
	// Destructor: cleans up the stack, frees memory
	~stack();
	// Push new element to the stack
	void push(int a);
	// Pop the element from the stack
	int pop();
	// Clean the data, but leave the stack allocated
	void clear();

// Class fields, they are declared as 'private' (so, not 'visible' to the code outside of the class)
private:
	int top;	// index of first free slot on stack
	int size;	// stack size
	int* data;	// stack data (ALARM: it's not C++ style, we'll fix it later)
};

stack::stack(int stack_size)
{
	printf("stack::stack() called\n");
	this->top = 0;
	this->size = stack_size;
	this->data = (int*)malloc(sizeof(int)*stack_size);  // not nice, not c++ style
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
		return -1; // really bad design, we'll discuss later how to fix this
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
	// Solving the problem (it *was* simple to break the logic)
	stack s2(10);
	s2.push(1);
	s2.push(2);
	s2.push(3);
	printf("Data from s2: %d\n", s2.pop());
	s2.top = 1;	// compiler will not tolerate private field access from the code outside of the class
	printf("Data from s2: %d\n", s2.pop());
	*/

	return 0;
}
