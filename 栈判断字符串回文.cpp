#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define NULL 0          //初始化所有可能用到的参数
#define SIZE 100
#define OVER 10
typedef char ele;
typedef struct Stick {                //建立堆栈的数据结构
    ele *base;
    ele *top;
    ele *sel;
    int stacksize;
}Sqstack; 
                       
int Init(Sqstack &S){                      //建立一个堆栈
    S.base=(ele *)malloc(SIZE * sizeof(ele));
    if(!S.base) 
	     exit(0);
    S.top=S.base;
    S.sel=S.base;
    S.stacksize=SIZE;
    return 1;
} 
                                
int push(Sqstack &S,ele e){              //向堆栈里输入字符
    if (S.top-S.base>=S.stacksize){
          S.base=(ele *)realloc(S.base,(S.stacksize+OVER)*sizeof(ele));
          if(!S.base) 
		      exit(0);
          S.top=S.base+S.stacksize;
          S.stacksize=S.stacksize+OVER;
    }
    *S.top++=e;
    S.sel=S.top;
    return 1;
}  
                               
int comp(Sqstack &S,Sqstack &L){   //对两个堆栈中的字符串进行比较并判断是否为回文
    int n=1;
    if (L.top-L.base>=L.stacksize){
         L.base=(ele *)realloc(L.base,(L.stacksize+OVER)*sizeof(ele));
         if(!L.base) 
		     exit(0);
         L.top=L.base+S.stacksize;
         L.stacksize=L.stacksize+OVER;
    }
    S.sel=S.sel-1;
    while(S.sel>=S.base){
         *L.top=*S.sel;
         S.sel=S.sel-1;
         L.top =L.top+1;
    }
    S.top=S.top-2;
    L.top=L.top-1;
    while((S.top>=S.base)&&(L.top>=L.base-1)){
        if(*S.top!=*L.top)
            n=0;
        S.top--;
        L.top--;
    }
    if(n==1)
        cout<<"该字符串为回文\n";
    else
        cout<<"该字符串不是回文\n";
    return 1;
}

int main(){
    char num;
    Sqstack S,L;
    Init(S);
    Init(L);
    cout<<"Please input the string and hit enter:\n";                        
//    string nums;                   
//    getline(cin, nums);           //先将输入作为一个字符串保存
//    istringstream istr(nums);
//    while(istr >> num)
//          push(S,num);
    cin >> num;
    push(S, num);
    while(num != '#'){
    	cin >> num;
    	push(S,num);
    }
    cout<<endl;
    comp(S,L);
    //system("pause");
}
