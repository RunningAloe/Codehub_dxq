#include<iostream>
#include<vector>
#include<hash_map>
#include<stack>
using namespace std;
struct node
{
	int value;
	node *left;
	node *right;
}
vector<int> maxTree(vector<int> A,int n)
{
	if(n==0)
		return A;
	node *arr=new node[n];
	for(int i=0;i<n;i++)
	{
		arr[i].value=A[i];
		arr[i].left=NULL;
		arr[i].right=NULL;
	}
	stack<node> s;
	hash_map<node,node> lbig;
	hash_map<node,node> rbig;
	for(int i=0;i<n;i++)
	{
		node cur=arr[i];
		while(!s.empty()&&s.top().value<cur.value)
			setbigMap(s,rbig);
		s.push(cur);
	}
	while(!s.empty())
		setbigMap(s,rbig);
	for(int i=n-1;i>-1;i--)
	{
		node cur=arr[i];
		while(!s.empty()&&s.top().value<cur.value)
			setbigMap(s,lbig);
		s.push(cur);
	}
	while(!s.empty())
		setbigMap(s,lbig);
	for(int i=0;i<n;i++)
	{
		node cur=arr[i];
		node bigleft=lbig
	}
}
