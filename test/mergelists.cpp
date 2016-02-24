#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode (int x):
		val(x),next(NULL){}
};

ListNode * insert(ListNode* ps, ListNode* psend,ListNode* pb, ListNode* pbend)
{
	ps->next=pb;
	cout<<"come to insert!"<<endl;
	cout<<"pbend->val="<<pbend->val<<endl;
	ListNode *nextpb=pbend->next;
	pbend->next=psend;
	cout<<"nextpb->val="<<nextpb->val<<endl;
	return nextpb;
}
ListNode* mergelists(ListNode* pHead1, ListNode* pHead2)
{
	cout<<"come in!"<<endl;
    if(pHead1==NULL)
        return pHead2;
	else if(pHead2==NULL)
	    return pHead1;
    ListNode *pb1=pHead2;
    ListNode *ps1=pHead1;
    ListNode *newhead=pHead1;
    if(pHead1->val>pHead2->val){
		pb1=pHead1;
		ps1=pHead2;
		newhead=pHead2;
	}
	ListNode *pb2=pb1;
	ListNode *ps2=NULL;
	while(pb1->next!=NULL && ps1->next!=NULL)
	{
		while(ps1->next!=NULL && ps1->next->val<=pb1->val)
		{
			ps1=ps1->next;
		}
		ps2=ps1->next;
		while(pb2->next!=NULL && pb2->next->val<=ps2->val)
		{
			cout<<"pb2->val="<<pb2->val<<endl;
			pb2=pb2->next;
		}
		cout<<"ps1->val="<<ps1->val<<endl;
		cout<<"ps2->val="<<ps2->val<<endl;
		cout<<"pb1->val="<<pb1->val<<endl;
		cout<<"pb2->val="<<pb2->val<<endl;
		pb1=insert(ps1,ps2,pb1,pb2);
		ps1=ps2;
	}
	return newhead;
}
int main()
{
	ListNode *head1=new ListNode(1);
	ListNode *p1=head1;
	ListNode *head2=new ListNode(2);
	ListNode *p2=head2;
	for(int i=1;i<5;i++)
	{
		p1->next=new ListNode(1+2*i);
		p1=p1->next;
		p2->next=new ListNode(2+2*i);
		p2=p2->next;
	}
	p1=head1;
	p2=head2;
	for(int i=0;i<5;i++)
	{
		cout<<p1->val<<endl;
		p1=p1->next;
	}
	for(int i=0;i<5;i++)
	{
		cout<<p2->val<<endl;
		p2=p2->next;
	}
	ListNode *newhead=mergelists(head1,head2);
	ListNode *p=newhead;
	cout<<"after merge:"<<endl;
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
	return 0;
}
