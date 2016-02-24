#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class mysort
{
	private:
		int m_num;
		int * data;
		void merge(int l1,int r1,int l2,int r2);
		void swap(int a,int b);
	public:
		mysort();
		mysort(int *array,const int num);
		~mysort();
		void quick(int start = 0,int end = 9);
		void mergesort(int start = 0,int end = 9);
		void show();
};
