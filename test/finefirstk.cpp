#include<iostream>
#include<vector>
using namespace std;

void partition(vector<int> &source,int target,int start,int end)
{
	int standard=source[start];
	cout<<"start,end:"<<start<<","<<end<<endl;
	while(start<end)
	{
		while(source[end]>=standard && end>start)
			end--;
		if(start==end)
			break;
		source[start++]=source[end];
        while(source[start]<=standard && end>start)
			start++;
		if(start==end)
			break;
		source[end--]=source[start];
	}
	source[start]=standard;
	for(int i=0;i<8;i++)
		cout<<source[i]<<endl;
	if(start==target-1)
		return;
	else if(start<target-1)
		partition(source,target,start+1,source.size()-1);
	else
		partition(source,target,0,start-1);
}

vector<int> findfirstk (vector<int> input, int k)
{
	vector<int> result;
	if(input.size()==0 || k==0 || input.size()<k)
		return result;
	if(input.size()==k)
		return input;
	partition(input,k,0,input.size()-1);
	for(int i=0;i<k;i++)
		result.push_back(input[i]);
	cout<<"input:"<<endl;
	for(int i=0;i<8;i++)
		cout<<input[i]<<endl;
	return result;
}

int main()
{
	int a[]={4,5,1,6,2,7,3,8};
	vector<int> input(a,a+8);
	for(int i=0;i<8;i++)
		cout<<input[i]<<endl;
	vector<int> output=findfirstk(input,1);
	cout<<"output:"<<endl;
	for(int i=0;i<1;i++)
		cout<<output[i]<<endl;
}
