#include<iostream>
#include<vector>
using namespace std;

 vector<int> printM(vector<vector<int> > matrix) {
	 cout<<"come in!"<<endl;
	int ycolumn=matrix[0].size()-1;
	cout<<"ycolumn="<<ycolumn;
    int yrow=matrix.size()-1;
	cout<<"yrow="<<yrow;
    int xcolumn=0,xrow=0;
    vector<int> result;
    while(xcolumn<=ycolumn && xrow<=yrow){
	   for(int i=xcolumn;i<=ycolumn;i++){
	       result.push_back(matrix[xrow][i]);
	   }
	   for(int i=xrow+1;i<=yrow;i++){
	       result.push_back(matrix[i][ycolumn]);
	   }
	   for(int i=ycolumn-1;i>=xcolumn;i--){
	       result.push_back(matrix[yrow][i]);
	   }
	   for(int i=yrow-1;i>=xrow+1;i--){
	       result.push_back(matrix[i][xcolumn]);
	   }
	   xcolumn++;
	   xrow++;
	   ycolumn--;
	   yrow--;
	   }
	   return result;
 }

int main()
{
	vector<vector<int> > test;
	int tmp[5][1]={{1},{2},{3},{4},{5}};
	for(int i=0;i<5;i++)
	{
		vector<int> test_tmp(*(tmp+i),*(tmp+i)+1);
		test.push_back(test_tmp);
	}
	cout<<"initial correct!"<<endl;
	vector<int> result=printM(test);
	for(int i=0;i<result.size();i++)
		cout<<result[i];
}
