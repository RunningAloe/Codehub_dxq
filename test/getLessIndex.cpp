#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getLessIndex (vector<int> arr)
{
	int len=arr.size();
	cout<<"len:"<<len<<endl;
	if(len==0)
		return -1;
	else if(len==1)
		return arr[0];
	if(arr[0]<arr[1])
		return arr[0];
	if(arr[len-1]<arr[len-2])
		return arr[len-1];
	int start=0,end=len-1;
	int index=(start+end)/2;
	cout<<"index:"<<index<<endl;
	while(index>=start && index <=end)
	{
		if(arr[index]<arr[index+1] && arr[index]<arr[index-1])
			return arr[index];
		else if(arr[index]>arr[index+1] && arr[end]>=arr[end-1])
			start=index;
		else if(arr[index]>arr[index-1] && arr[start]>=arr[start+1])
			end=index;
		index=(start+end)/2;
		cout<<"index:"<<index<<endl;
	}
	return index;
}
int main()
{
	int arr[24]={3,5,1,5,9,4,6,5,3,0,8,4,5,8,7,1,4,5,2,3,0,5,0,4};
	vector<int> A(arr,arr+24);
	int r=getLessIndex(A);
	cout<<r<<endl;
}
