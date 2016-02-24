#include<iostream>
#include<cmath>
using namespace std;
int isenough(int x,int y,int x0,int y0,int r2){
	cout<<"x,y,x0,y0,r2:"<<x<<","<<y<<","<<x0<<","<<y0<<","<<r2<<endl;
    int d=pow(x-x0,2)+pow(y-y0,2);
	cout<<"d:"<<d<<endl;
    if (d<=r2)
		return 1;
	else
		return 0;
}

int main(){
    const int num = 3;
    int R,x[num],y[num],x0,y0,result=0;
    cin>>R;
    int R2=R*R;
    for(int i=0;i<num;i++){
		cin>>x[i]>>y[i];
		cout<<"x[i],y[i]:"<<x[i]<<","<<y[i]<<endl;
		}
	cin>>x0>>y0;
    for(int i=0;i<num;i++){
        result=result+isenough(x[i],y[i],x0,y0,R2);
	    }
	cout<<result<<"x";
}
