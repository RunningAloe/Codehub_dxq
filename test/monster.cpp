#include <iostream>
#include <vector>
using namespace std;
int gongyue(int a,int b){
     int min=a<b?a:b;
     int result=1;
     for(int i=2;i<=min;i++){
		if(a%i==0 && b%i==0){
            result=i;
            }
        }
	 cout<<a<<","<<b<<"gongyue:"<<result<<endl;
     return result;
}

int final_cap(int num,int init_cap,vector<int> monst){
    if (num==0)
		return init_cap;
    int result=init_cap;
    for(int i=0;i<num;i++)
        result=result+gongyue(monst[i],result);
    return result;
}
int main(){
     int num,init_cap;

      cout<<"please input number of monster and init_cap:"<<endl;
       cin>>num>>init_cap;
        vector <int> monst(num,0);
         for (int i=0;i<num;i++)
               cin>>monst[i];
          cout<<final_cap(num,init_cap,monst);
}
