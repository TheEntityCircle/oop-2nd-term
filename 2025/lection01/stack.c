#include <stdlib.h>
#include <stdio.h>

/* Стек в процедурном стиле */

// Структура, описывающая стек
struct stack_handle
{
	int top;	// индекс первого свободного элемента
	int size;	// размер стека
	int* data;	// указатель на область памяти
};


// Функции для работы со стеком
void init(struct stack_handle* s, int stack_size);
void finalize(struct stack_handle* s);
void push(struct stack_handle* s, int a);
int pop(struct stack_handle* s);
void clear(struct stack_handle* s);


// Создаёт стек заданного размера
void init(struct stack_handle* s, int stack_size)
{
	s->top = 0;
	s->size = stack_size;
	s->data = (int*)malloc(sizeof(int)*stack_size);
}

// Уничтожает существующий стек
void finalize(struct stack_handle* s)
{
	free(s->data);
}

// Складывает новый элемент в стек
void push(struct stack_handle* s, int a)
{
	if(s->top == s->size)
	{
		printf("ERROR: Stack overflow! Can not push %d\n", a);
		return;
	}
	s->data[s->top] = a;
	s->top++;
}

// Достаёт верхний элемент из стека
int pop(struct stack_handle* s)
{
	if(s->top == 0)
	{
		printf("ERROR: Stack empty, can not pop\n");
		return -1; // плохая идея, потом к этому ещё вернёмся
	}
	s->top--;
	return s->data[s->top];
}

// Чистит данные в стеке, сохраняя сам стек
void clear(struct stack_handle* s)
{
	s->top = 0;
}


int main()
{
	// Пример, как всё работает в хорошем случае
	struct stack_handle s1;
	init(&s1, 2);
	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);
	printf("Data from s1: %d\n", pop(&s1));
	printf("Data from s1: %d\n", pop(&s1));
	pop(&s1);
	finalize(&s1);

	/*
	// Демо проблемы: вызывающий код легко может всё сломать
	struct stack_handle s2;
	init(&s2, 10);
	push(&s2, 1);
	push(&s2, 2);
	push(&s2, 3);
	printf("Data from s2: %d\n", pop(&s2));
	s2.top = 1;	// например, вот так может сломать
	printf("Data from s2: %d -- oops\n", pop(&s2));
	finalize(&s2);
	// Интереса ради можете придумать ещё пару способов всё сломать
	*/

	return 0;
}
