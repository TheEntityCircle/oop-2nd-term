#include <iostream>
using namespace std;

void func(char c)
{
	cout<<"fun(char) called"<<endl;
}

void func(int c)
{
	cout <<"fun(int) called"<<endl;
}

int main()
{
	func(10);
	func('a');
	return 0;
}
