#include <iostream>
using namespace std;
#include "list.h"

list::list()
{
	head = NULL;
	current = NULL;
}

list::~list()
{
	while(head)
	{ 
		node* t=head->next;
		delete head;
		head=t;
	};
}

void list::insert(int a)
{
	node* t=new node;
	t->next=head;
	head = t;
	head->val = a;
}

void list::goToHead()
{
	current=head;
}

int list::getCurrentData()
{
	return current->val;
}

void list::advance()
{
	current=current->next;
}

bool list::moreData()
{
	if(current)
		return true;
	else
		return false;
}
