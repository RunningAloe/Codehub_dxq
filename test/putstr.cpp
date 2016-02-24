#include<vector>
#include<iostream>
using namespace std;

class solution
{
	private:
		vector<string> r;
		void putstr(string &str,int index);
	public:
		vector<string> Permutation(string str);
		void show();
};
void solution::putstr(string &str,int index)
{
	int len=str.length();
	char tmp;
	if(index==len-1)
	{
		r.push_back(str);
		return;
	}
	putstr(str,index+1);
	for(int i=index+1;i<len;i++)
	{
		if(str[i]!=str[index])
		{
			tmp=str[index];
			str[index]=str[i];
			str[i]=tmp;
			putstr(str,index+1);
			tmp=str[index];
			str[index]=str[i];
			str[i]=tmp;
		}
	}
}
vector<string> solution::Permutation(string str)
{
	if(str.length()==0)
		return r;
	putstr(str,0);
	return r;
}
void solution::show()
{
	vector<string>::iterator iter=r.begin();
	while(iter!=r.end())
	{
		cout<<*iter<<endl;
		iter++;
	}
}
int main()
{
	solution a;
	string s("aabac");
	a.Permutation(s);
	a.show();
}
