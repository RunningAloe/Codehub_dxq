#include<iostream>
#include<stack>
using namespace std;

int getLast(stack<int> &s)
{
	int value=s.top();
	s.pop();
	if(s.size()==0)
		return value;
	int result=getLast(s);
	s.push(value);
	return result;
}
void reverseStack(stack<int> &s)
{
	if(s.empty())
		return;
	int value=getLast(s);
	reverseStack(s);
	s.push(value);
	return;
}

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	reverseStack(s);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
