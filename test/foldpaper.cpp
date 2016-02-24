#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector <string> foldpaper(int n)
{
	vector <string> result((1<<n)-1);
	int num = 0;
	for(int i=0;i<n;i++)
	{
		result[num] = "down";
		for(int j=0;j<num;j++)
		{
			if(result[j]=="down")
				result[2*num-j]="up";
			else if(result[j]=="up")
				result[2*num-j]="down";
		}
		num = num*2+1;
	}
	return result;
}
int main()
{
	for(int j=0;j<6;j++)
	{
	vector<string> a=foldpaper(j);
	int len = a.size();
	cout<<endl<<"n="<<j<<endl;
	for(int i=0;i<len;i++)
		cout<<a[i]<<endl;
	}
	return 0;
}
