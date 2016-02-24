#include<iostream>
#include<stdlib.h>
#include"linked.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	LNode *head = initial(ar);
	show_list(head);

  	if(del_Node(head,1))
  		cout<<"Delete a node!"<<endl;
  	else
  		cout<<"Delete error!"<<endl;
  	show_list(head);

 	int Toadd=20;
 	if(add_Node(head,Toadd))
 		cout<<"Add a node!"<<endl;
 	else
 		cout<<"Add error!"<<endl;
 	show_list(head);
	
//	LNode *revers = revesal(head);
//	show_list(head);
	
//	insert_sort(head,10);
//	cout<<"Sorted list is:"<<endl;
//	show_list(head);
	
	const int num = 10;
	int array[num];
	get_array(array,num);
	cout<<"You've entered:"<<endl;
	show_array(array,num);
//	bubble_sort(array,num);
//	select_sort(array,num);
//	heap_sort(array,num);
	shell_sort(array,num);

	cout<<"Sorted list is:"<<endl;
	show_array(array,num);
	
	return 0;
}
