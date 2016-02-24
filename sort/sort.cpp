#include "sort.h"

mysort::mysort()
{
	m_num = 10;
	data = new int[m_num];
	for(int i=m_num;i>0;i--)
		data[m_num-i] = i;
}

mysort::mysort(int * array,const int num)
{
	m_num = num;
	data = new int[m_num];
	for(int i=0;i<m_num;i++)
		data[i]=array[i];
}
mysort::~mysort()
{
	delete []data;
}
void mysort::quick(int start,int end)
{
	int flag = data[start];
	int small = start;
	int big = end;
	while(small < big)
	{
		while(data[big]>flag && small<big)
			big--;
		if(small<big)
			data[small++]=data[big];
		while(data[small]<=flag && small<big)
			small++;
		if(small<big)
			data[big--]=data[small];
	}
	data[small] = flag;//is same as'data[big]=flag
	if(start<small-1)
		quick(start,small-1);
	if(small+1<end)
		quick(small+1,end);
}


void mysort::swap(int a,int b)
{
	int tmp = data[a];
	data[a]=data[b];
	data[b]=tmp;
}
void mysort::merge(int l1,int r1,int l2,int r2)
{
	while(l1<=r1 && l2<=r2)
	{
		if(data[l2]<data[l1])
		{
			int tmp = data[l2];
			int i = l2;
			while(i>l1 && data[i-1]>tmp)
			{
				data[i]=data[i-1];
				i--;
			}
			data[i]=tmp;
			l1=i;
			r1++;
			l2++;
		}
		l1++;
	}
}

void mysort::mergesort(int l,int r)
{
	if (l==r)
		return;
	int m = (l+r)/2;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,m+1,r);
	show();
}
void mysort::show()
{
	cout<<"data now is:"<<endl;
	for (int i=0;i<m_num;i++)
	{
		cout<<data[i]<<endl;
	}
}
