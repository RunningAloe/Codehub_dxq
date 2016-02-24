#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> clockwisePrint(vector<vector<int> > mat,int n,int m)
{
	int i=0,j=0,k=0;
	int a=i,b=j;
	vector<int> result(m*n,0);
	if(n==0||m==0)
		std::cout<<"error input"<<std::endl;
	m--;
	n--;
	while(i<=n && j<=m)
	{
		if(a==n)
		{
			while(b<=m)
				result[k++]=mat[a][b++];
			b--;
		}
		else if(b==m)
		{
			while(a<=n)
				result[k++]=mat[a++][b];
			a--;
		}
		else
		{
			while(b<m)
				result[k++]=mat[a][b++];
			while(a<n)
				result[k++]=mat[a++][b];
			while(b>j)
				result[k++]=mat[a][b--];
			while(a>i)
				result[k++]=mat[a--][b];
		}
		--n;
		--m;
		++i;
		++j;
		a=i;
		b=j;
	}
	return result;
}
vector<vector<int> >Rotate(vector<vector<int> > mat,int n)
{
	if (n==1)
		return mat;//旋转后是本身
	int m=0;//标记子矩阵起始坐标
	int tmp;
	n--;
	while(m<n)
	{
		int len = n-m;
		cout<<"n,m:"<<n<<m<<endl;
		for(int i=0;i<len;i++)
		{
			tmp = mat[m][m+i];
			mat[m][m+i]=mat[n-i][m];
			mat[n-i][m]=mat[n][n-i];
			mat[n][n-i]=mat[m+i][n];
			mat[m+i][n]=tmp;
			cout<<"tmp:"<<tmp<<endl;
		}
//		for(int i=0;i<len;i++)
//			tmp[i]=mat[m+i][n];//暂时存放右边框数据
//		for(int i=0;i<len;i++)
//			mat[n-i][n]=mat[m][n-i];//上边框完成旋转
//		for(int i=1;i<len;i++)
//			mat[m][n-i]=mat[m+i][m];//左边框完成旋转
//		for(int i=1;i<len;i++)
//			mat[m+i][m]=mat[n][n-i];//下边框完成旋转
//		for(int i=0;i<len;i++)
//			mat[n][n-i]=tmp[i];//右边框完成旋转
		n--;
		m++;
	}
	return mat;
}
int main()
{
//test clockprint
	vector<vector<int> > input(4,vector<int>(6,10));
	for (int i=0;i<6;i++)
		input[2][i]=i;
	vector<int> result = clockwisePrint(input,4,6);
	for(int k=0;k<24;k++)
		std::cout<<result[k]<<std::endl;
//test rotate
	vector<vector<int> > input_r(3,vector<int>(3));
	int k=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			input_r[i][j]=k++;
	cout<<"before rotate:"<<endl;
	for(int t=0;t<3;t++)
		for(int j=0;j<3;j++)
			cout<<input_r[t][j]<<endl;
	input_r = Rotate(input_r,3);
	cout<<"after rotate:"<<endl;
	for(int t=0;t<3;t++)
		for(int j=0;j<3;j++)
			cout<<input_r[t][j]<<endl;
	return 0;
}

