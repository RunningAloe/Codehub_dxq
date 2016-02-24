#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int getUpMedian(vector<int> arr1,int start1,int end1,vector<int> arr2,int start2,int end2)
{
//	int start1=0,start2=0;
//	int end1=arr1.size()-1,end2=arr2.size()-1;
	while(end1-start1>1)
	{
		int offset=(start1+end1)%2;//偶数中间位置索引需要加1
		int index1=(start1+end1)/2;
		int index2=(start2+end2)/2;
//		cout<<"start1,end1:"<<start1<<","<<end1<<endl;
//		cout<<"start2,end2:"<<start2<<","<<end2<<endl;
//		cout<<"index1:"<<index1<<endl;
//		cout<<"index2:"<<index2<<endl;
		if(arr1[index1]==arr2[index2])
			return arr1[index1];
		else if(arr1[index1]>arr2[index2])
		{
			end1=index1;
			start2=index2+offset;
		}
		else//(arr1[index1]<arr2[index2])
		{
			start1=index1+offset;
			end2=index2;
		}
	}
	if(arr1[start1]>arr2[end2])
		return arr2[end2];
	else if(arr2[start2]>arr1[end1])
		return arr1[end1];
	else
	{
		int min1=arr1[start1];
		if (arr1[start1]>arr1[end1])
			min1=arr1[end1];
		int min2=arr2[start2];
		if (arr2[start2]>arr2[end2])
			min2=arr2[end2];
		if(min1>min2)
			return min1;
		else
			return min2;
	}
}

int getKthnum(vector<int> arr1,vector<int> arr2,int kth)
{
	int len1=arr1.size();
	int len2=arr2.size();
	if(len1==0 || len2==0 || kth < 1 || kth > len1+len2)
		return -1;
	int end1,end2;
	int start1,start2;
	bool flag=0;//flag=0:arr1 is smaller;flag=1:arr2 is smaller
	int len_small=len1;//get the smaller
	int len_big=len2;
	if(len1>len2)
	{
		len_small=len2;
		len_big=len1;
		flag=1;
	}
	if(kth<=len_small)
	{
		cout<<"kth<=len_small,kth,len_small:"<<kth<<","<<len_small<<endl;
		end1=end2=kth-1;
		start1=start2=0;
	}
	else if(len_small<kth && kth<=len_big)
	{
		cout<<"kth,len_big,len_small:"<<kth<<","<<len_big<<","<<len_small<<endl;
		if(flag==1)
		{
			if(arr1[0]>arr2[len2-1])
				return arr1[kth-len1-1];
			else
			{
				start1=kth-len2;
				end1=kth-1;
				start2=0;
				end2=len2-1;
			}
		}
		else
		{
			if(arr2[0]>arr1[len1-1])
				return arr2[kth-len1-1];
			else
			{
				start2=kth-len1;
				end2=kth-1;
				start1=0;
				end1=len1-1;
			}
		}
	}
	else if(kth>len_big)
	{
		cout<<"kth>len_big,kth,len_big:"<<kth<<","<<len_big<<endl;
		int delta=len_small+len_big-kth;
		start1=len1-delta;
		start2=len2-delta;
		if(arr1[start1-1]>=arr2[len2-1])
			return arr1[start1-1];
		else if(arr2[start2-1]>=arr1[len1-1])
			return arr2[start2-1];
		end1=len1-1;
		end2=len2-1;
	}
	cout<<"start1,end1,start2,end2:"<<start1<<","<<end1<<","<<start2<<","<<end2<<endl;
	return getUpMedian(arr1,start1,end1,arr2,start2,end2);
}
int main()
{
	int init1[1]={9};
	int init2[11]={7,7,11,17,23,27,30,32,32,45,47};
	vector<int> arr1(init1,init1+1);
	vector<int> arr2(init2,init2+11);
//	int result=getUpMedian(arr1,arr2);
	int result=getKthnum(arr1,arr2,10);
	cout<<"result:"<<result<<endl;
}
