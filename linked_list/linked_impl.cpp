//include all definitions of functions
#include <iostream>
#include "linked.h"
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

LNode *initial(const int ar[10])
{
	LNode *p1;

	int i=0;
	if(ar==NULL)
		return NULL;
	LNode *h = (LNode*)malloc(sizeof(LNode));
	h->data = ar[0];
	p1 = h;
	for(i=1;i<10;i++)
	{
		p1->next = (LNode*)malloc(sizeof(LNode));
		p1 = p1->next;
		p1->data = ar[i];
	}
	p1->next = NULL;
	cout<<"Initializing completed!"<<endl;
	return h; 
}

void show_list(LNode *h)
{
	if(h == NULL)
		cout<<"A empty list!"<<endl;
	else
	{
		cout<<"The lined_list is:"<<endl;
		LNode *p = h;
		while(p != NULL)
		{	
			cout<<p->data<<endl;
			p = p->next;
		}
	}
}
int del_Node(LNode * &h,int x)
{
	if(h == NULL)
	{
		std::cout<<"A empty list!"<<std::endl;
		return -1;
	}
	else if(h->data==x)
	{
		LNode *tmp=h;
		h=h->next;
		free(tmp);
		return 1;
	}
	LNode *p1 = h->next;
	LNode *p2 = h;
	while(p1 != NULL&&p1->data != x)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	if(p1 == NULL)
		return 0;
	else
	{
		p2->next = p1->next;
		free(p1);
		return 1;
	}
}

int add_Node(LNode * &h,int x)
{
	LNode *p = (LNode*)malloc(sizeof(LNode));
	p->data = x;
	p->next = NULL;
	if(h == NULL)
	{
		h = p; 
		return 1;
	}
	LNode *ptrl = h;
	while(ptrl->next != NULL)
	{
		ptrl = ptrl->next;
	}
	ptrl->next = p;
	return 1;
}

LNode *revesal(LNode * &h)
{
	LNode *p1,*p2,*p3;
	p1 = h;
	p2 = p1->next;
	if(p1==NULL||p2==NULL)
		return h;
	while(p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	h->next = NULL;
	h = p1;
	cout<<"Revesal completed!"<<endl;
	return h; 
}
void show_array(int * const array,const int Length)
{
	int i=0;
	for(i=0;i<Length;i++)
		cout<<array[i]<<endl;
}
void get_array(int *array,const int num)
{
	cout<<"Enter "<<num<<" numbers:"<<endl;
	int i=0;
	while(i<num)
	{	
		cin>>array[i];
		i++;
	}
}
void swap(int &i,int &j)
{
	int temp = i;
	i=j;
	j=temp;
}
//time:O(n^2)
void bubble_sort(int *array,int Length)
{
	int i=0,j=0,flag=1;
	for(i=0;(i<Length)&&(flag==1);i++)
	{
		flag=0;
		for(j=Length-1;j>i;j--)
		{
			if(array[j]<array[j-1])
				{
					swap(array[j],array[j-1]);
					flag=1;
				}
		}
	}
}
void insert_sort(LNode *array_h,int Length)
{
	int i=0,j=0;
	LNode *p1=array_h,*p3=array_h,*p2=array_h->next;
	for(i=2;i<Length+1;i++)
	{
		for(j=0;j<i;j++)
		{
			if((p2->data<p3->data)&&(p3!=array_h))
			{
				p1->next=p2->next;
				p2->next=p3->next;
				p3->next=p2;
				break;
			}
			if((p2->data<p3->data)&&(p3==array_h))
			{
				p1->next=p2->next;
				p2->next=p1;
				array_h=p2;
				break;
			}
			p3=p3->next;
		}
		p1=p1->next;
		p2=p1->next;
	}
}
//time:O(n^2)	max_move:n-1
void select_sort(int *array,int Length)
{
	int i=0,j=0,min=0;
	for(i=0;i<Length;i++)
	{
		min=i;
		for(j=i;j<Length+1;j++)
		{
			min=array[j]<array[min]?j:min;
		}
		if(min!=i)
			swap(array[min],array[i]);
	}
}
//void quick_sort(int *array,int Length);
//void have_circle(int *array,int Length);
void adjustHeap(int *array,int index,int Length)
{
	int curParent=array[index];
	int child = index*2+1;
	while(child < Length)//child exist
	{
		if((child+1<Length)&&(array[child]<array[child+1]))//get the bigger child
			child++;
		if(curParent<array[child])
		{
			array[index]=array[child];
			index=child;
			child=child*2+1;//left child of curChild
		}
		else
			break;//no need to adjust child tree cause the tree is a heap in the initialization,and only root node needs adjust later
	}
	array[index]=curParent;
}
void heap_sort(int *array,int Length)
{
	int i=Length/2-1;//from the last parent node
	for(;i>=0;i--)//important!
		adjustHeap(array,i,Length);
	for(i=Length-1;i>0;i--)
	{
		int max=array[0];
		array[0]=array[i];
		array[i]=max;
		adjustHeap(array,0,i);
	}
}
void shell_sort(int *array,int Length)
{
	int gap = Length/3;
	for (int i=gap;i>0;i--)
	{
		cout<<"gap:"<<i<<endl;
		for (int j=0;j<i;j++)
		{
			for(int k=j;k<Length;k=k+i)
			{
				int min = k;
				for(int m=k;m<Length;m=m+i)
					min = array[min]<array[m]?min:m;
				if(array[min]!=array[k])
					swap(array[min],array[k]);
					
			}
		}
	}
}
//content:initial:9
//show_list:30
//del_Node:45
//add_Node:76
//revesal:95
//show_array:114
//get_array:120
//swap:129
//bubble_sort:136
//insert_sort:152
//select_sort:181
