//include all statements of values and functions
struct LNode
{
	int data;
	LNode *next;
};
const int ar[10] = {1,2,3,4,1,2,3,4,1,2};

LNode *initial(const int ar[10]);
void show_list(LNode *h);
int del_Node(LNode * &h,int x);
int add_Node(LNode * &h,int x);
LNode *revesal(LNode * &h);

void swap(int &i,int &j);
void get_array(int *array,const int num);
void show_array(int * const array,const int Length);
void bubble_sort(int *array,const int Length);
void insert_sort(LNode *array_h,int Length);
void select_sort(int *array,int Length);
void quick_sort(int *array,int Length);
void have_circle(int *array,int Length);
void adjustHeap(int *array,int index,int Length);
void heap_sort(int *array,int Length);
void shell_sort(int *array,int Length);
