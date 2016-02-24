#include <iostream>
#include <vector>

using namespace std;

void oddeven(vector<int> &array)
{
	int length=array.size();
	int index=0;
	for(int i=0;i<length;i++)
	{
		if(array[i]&1==1)
			++index;
	}
	int odd=0;
	int even=index;
	cout<<"index:"<<index<<endl;
	for(;odd<index;odd++)
	{
		cout<<array[odd]<<endl;
		cout<<(array[odd]&1)<<endl;
		if((array[odd]&1)!=1)
		{
			while((array[even]&1)!=1 && even<length)
				++even;
			cout<<"array[odd]:"<<array[odd]<<endl;
			cout<<"array[even]:"<<array[even]<<endl;
			int tmp=array[odd];
			array[odd]=array[even];
			array[even++]=tmp;
		}
	}
}
int main()
{
	int a[7]={1,2,3,4,5,6,7};
	vector<int> array(a,a+7);
	for(int i=0;i<array.size();i++)
	{
		cout<<array[i]<<endl;
	}
	oddeven(array);
	for(int i=0;i<array.size();i++)
	{
		cout<<array[i]<<endl;
	}
	return 0;
}
