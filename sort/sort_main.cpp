#include "sort.h"

int main()
{
	mysort sort1;
	int array[12]={45,22,76,1,65,3,61,33,24,90,43,88};
	mysort sort2 = mysort(array,7);
	mysort sort3 = mysort(array,12);
//	sort1.show();
//	sort1.quick();
//	sort1.show();
//	sort2.show();
//	sort2.quick(0,6);
//	sort2.show();
	sort3.show();
	sort3.mergesort(0,11);
	sort3.show();
}
