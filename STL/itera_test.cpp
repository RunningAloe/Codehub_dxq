#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	const vector<int> numbers(10);
	numbers[0]= 20;
	numbers[9]=40;
	const vector<int>::iterator result1=numbers.begin();
	vector<int>::iterator result2=numbers.end()-1;
	cout<<"result1:"<<*result1<<endl<<"result2:"<<*result2<<endl;
	try
	{
		result2=result1;
		cout<<"result1:"<<*result1<<endl<<"result2:"<<*result2<<endl;
	}
	catch(exception& e)
	{
		cout<<"error in \"result2=result1\""<<e.what()<<endl;
	}
	//*result1=1000;
	//cout<<"result1:"<<*result1<<endl<<"result2:"<<*result2<<endl;

//	try
//	{
//		result1=result2;
//		cout<<"result1:"<<*result1<<endl<<"result2:"<<*result2<<endl;
//	}
//	catch(exception& e)
//	{
//		cout<<"error in \"result1=result2\""<<e.what()<<endl;
//	}
	return 0;
}
