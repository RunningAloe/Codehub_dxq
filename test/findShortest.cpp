#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findShortest(vector<int> A,int n)
{
	bool flag_l=0,flag_r=0;
	int left=0,right=n-1;
	while(left<=right && (flag_l&flag_r)!=1)
	{
		if(flag_l==0 && A[left]>A[++left])
			flag_l=1;
		if(flag_r==0 && A[right]<A[--right])
			flag_r=1;
	}
	return (right-left+2);
}
int main()
{
	int arr[6]={1,2,5,4,3,6};
	vector<int> A(arr,arr+6);
	for (int i=0;i<6;i++)
		cout<<A[i]<<endl;
	int r=findShortest(A,6);
	cout<<r<<endl;
}
