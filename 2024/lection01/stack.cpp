#include <iostream>

/* Стек в объектном стиле */

using namespace std;

class stack
{
// Публичные методы класса (доступны вызывающему коду)
public:
	// Конструктор: создаёт стек заданного размера
	stack(int size);
	// Деструктор: уничтожает существующий стек
	~stack();
	// Складывает новый элемент в стек
	void push(int a);
	// Достаёт верхний элемент из стека
	int pop();
	// Чистит данные в стеке, сохраняя сам стек
	void clear();

// Поля класса, объявлены как приватные (недоступны внешнему коду)
private:
	int top;	// индекс первого свободного элемента
	int size;	// размер стека
	int* data;	// указатель на область памяти (не очень красиво, позже обсудим)
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
	// Пример, как всё работает в хорошем случае
	stack s1(2);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << "Data from s1: " << s1.pop() << endl;
	cout << "Data from s1: " << s1.pop() << endl;
	s1.pop();

	/*
	// Решение проблемы: теперь так просто всё не сломать
	stack s2(10);
	s2.push(1);
	s2.push(2);
	s2.push(3);
	cout << "Data from s2: " << s2.pop() << endl;
	s2.top = 1;	// это просто не скомпилируется
	cout << "Data from s2: " << s2.pop() << endl;
	*/

	return 0;
}
