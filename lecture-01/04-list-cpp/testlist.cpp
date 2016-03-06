#include <iostream>
using namespace std;
#include "list.h"

int main()
{
	list l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.goToHead();
	while(l.moreData())
	{
		int val;
		val=l.getCurrentData();
		cout << val << " ";
		l.advance();
	}
	cout << endl;
}
