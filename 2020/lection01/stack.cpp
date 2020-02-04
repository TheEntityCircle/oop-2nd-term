#include <iostream>

using namespace std;

class stack
{
// Class methods, they are declared as 'public' 
// (so, 'visible' to the code outside of the class)
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

// Class fields, they are declared as 'private' 
// (so, *not* 'visible' to the code outside of the class)
private:
	int top;	// index of first free slot on stack
	int size;	// stack size
	int* data;	// stack data (not C++ style, we'll fix it later)
};

stack::stack(int stack_size)
{
	cout << "stack::stack() called" << endl;
	this->top = 0;
	this->size = stack_size;
	this->data = new int[stack_size];
}

stack::~stack()
{
	cout << "stack::~stack() called" << endl;
	delete[] this->data;
}

void stack::clear()
{
	this->top = 0;
}

void stack::push(int a)
{
	if(this->top == this->size)
	{
		cout << "ERROR: Stack overflow! Can not push " << a << endl;
		return;
	}
	this->data[this->top] = a;
	this->top++;
}

int stack::pop()
{
	if(this->top == 0)
	{
		cout << "ERROR: Stack empty, can not pop" << endl;
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
	cout << "Data from s1: " << s1.pop() << endl;
	cout << "Data from s1: " << s1.pop() << endl;
	s1.pop();

	/*
	// Solving the problem (it *was* simple to break the logic)
	stack s2(10);
	s2.push(1);
	s2.push(2);
	s2.push(3);
	cout << "Data from s2: " << s2.pop() << endl;
	s2.top = 1;	// compiler will not tolerate private field access
	cout << "Data from s2: " << s2.pop() << endl;
	*/

	return 0;
}
