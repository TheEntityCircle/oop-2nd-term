#include <stdlib.h>
#include <stdio.h>


struct stack_handle
{
	int top; // index of first free slot on stack
	int size;
	int* data;
};


void init(struct stack_handle* s, int stack_size);
void finalize(struct stack_handle* s);
void push(struct stack_handle* s, int a);
int pop(struct stack_handle* s);
void clear(struct stack_handle* s);


void init(struct stack_handle* s, int stack_size)
{
	s->top = 0;
	s->size = stack_size;
	s->data = (int*)malloc(sizeof(int)*stack_size);
}

void finalize(struct stack_handle* s)
{
	free(s->data);
}

void clear(struct stack_handle* s)
{
	s->top = 0;
}

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

int pop(struct stack_handle* s)
{
	if(s->top == 0)
	{
		printf("ERROR: Stack empty, can not pop\n");
		return -1; // really bad design choice
	}
	s->top--;
	return s->data[s->top];
}


int main()
{
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
	struct stack_handle s2;
	init(&s2, 10);
	push(&s2, 1);
	push(&s2, 2);
	push(&s2, 3);
	printf("Data from s2: %d\n", pop(&s2));
	s2.top = 1;
	printf("Data from s2: %d -- oops\n", pop(&s2));
	finalize(&s2);
    */

	return 0;
}
