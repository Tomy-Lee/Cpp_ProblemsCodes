//一只母羊，第三年开始每年生一只小羊，第n年一共多少羊 
#include <iostream>
using namespace std;

int main() {
    int i, n;
    long a=1, b=1, c=1, temp;
    cin >>n;
    if(n==1||n==2) cout<<"1"<<endl;
    else{
         for(i=3; i<=n; i++){
             temp=a+c;
	         a=b; 
	       	 b=c; 
	    	 c=temp;
         }
    cout << c <<endl;
   }
}

