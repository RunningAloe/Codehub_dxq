#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x):
		val(x),left(NULL),right(NULL){}
};

int nodeNum(TreeNode *head)
{
	if(head==NULL)
		return 0;
	int h=0;
	TreeNode *p=head;
	while(p!=NULL)
	{
		p=p->left;
		h++;
	}
	return subnodeNum(head,h);
}
int subnodeNum(TreeNode *head,int h)
{
	if(h==1)
		return 1;
	TreeNode *p=head->right;
	int sum;
	for(int i=0;i<h-2;i++)
	{
		p=p->left;
	}
	if (subtree==NULL)
		sum=subnodeNum(head->left,h-1)+1<<(h-2));
	else
		sum=subnodeNum(head->right,h-1)+(1<<(h-1));
	return sum;
}
int main()
{
}
