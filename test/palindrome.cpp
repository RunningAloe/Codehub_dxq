#include<iostream>
#include<string>
#include<climits>
using namespace std;
string addmark(string &A,int n)
{
	string B(2*n+1,'#');
	for(int i=1;i<=n;i++)
		B[i*2-1]=A[i-1];
	return B;
}
int palindrome(string A,int n)
{
	string B=addmark(A,n);
	cout<<B<<endl;
	int pr=-1,index=-1,max=INT_MIN;
	int arr[B.size()];
	for(int i=0;i<B.size();i++)
	{
		if(pr>i+1)
			arr[i]=(pr-i)<arr[2*index-i]?(pr-i):arr[2*index-i];
		else
		{
			arr[i]=1;
			while(i-arr[i]>=0 && i+arr[i]<B.size())
			{
				if(B[i-arr[i]]==B[i+arr[i]])
					arr[i]++;
				else
					break;
			}
		}
		if(i+arr[i]>pr)
		{
			index=i;
			pr=i+arr[i];
		}
		max=max>arr[i]?max:arr[i];
		cout<<"arr["<<i<<"]="<<arr[i]<<endl;
		cout<<"pr:"<<pr<<endl;
		cout<<"index:"<<index<<endl;
	}
	return max-1;
}
int main()
{
	string A="dbcdbcbaadbbddcacdbacadccbccd";
	cout<<A<<endl<<palindrome(A,A.size())<<endl;
}
