#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

double max_mul(vector<double> arr)
{
	int len=arr.size();
	if(len==0)
		return 0;
	double max[len],min[len];
	max[0]=min[0]=arr[0];
	double result=max[0];
	for(int i=1;i<len;i++)
	{
		max[i]=max[i-1]*arr[i]>min[i-1]*arr[i]?max[i-1]*arr[i]:min[i-1]*arr[i];
		max[i]=max[i]>arr[i]?max[i]:arr[i];
		min[i]=max[i-1]*arr[i]<min[i-1]*arr[i]?max[i-1]*arr[i]:min[i-1]*arr[i];
		min[i]=min[i]<arr[i]?min[i]:arr[i];
	}
	for(int i=0;i<len;i++)
	{
		result=result>max[i]?result:max[i];
		cout<<"max["<<i<<"]="<<max[i]<<endl;
	}
	return result;
}
int main()
{
	double arr[5]={-1,1.5,-6,0,4};
	vector<double> A(arr,arr+5);
	int r=max_mul(A);
	cout<<r<<endl;
	return 0;
}
