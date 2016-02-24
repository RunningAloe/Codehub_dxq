#include<iostream>
#include<string>
using namespace std;
void reverse(string &A,int start,int end)
{
	char tmp;
	while(start<end)
	{
		tmp=A[start];
		A[start]=A[end];
		A[end]=tmp;
		start++;
		end--;
	}
}
string movestring(string A,int n,int p)
{
	if(A == "" || n<0 ||p<0)
	{
		cout<<"error input"<<endl;
		return A;
	}
	reverse(A,0,p);
	reverse(A,p+1,n-1);
	reverse(A,0,n-1);
	return A;
}

int main()
{
	string A="PQWIVLQQ";
	A=movestring(A,8,5);
	cout<<A<<endl;
}
