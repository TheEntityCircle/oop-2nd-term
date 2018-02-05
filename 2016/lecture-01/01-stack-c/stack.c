#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void init(struct stack_handle* s)
{
	s->top=0;
}

void finalize(struct stack_handle* s)
{
}

void clear(struct stack_handle* s)
{
	s->top=0;
}

void push(struct stack_handle* s,int a)
{
        assert(s->top<STACKSIZE);
	s->data[s->top++]=a;
}

int pop(struct stack_handle* s)
{
	assert(s->top>0);
	return s->data[--s->top];
}

