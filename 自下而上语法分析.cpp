/*时间限制：1秒    内存限制：256兆 题目描述
 输入开始符号，非终结符，终结符，产生式，LL(1)分析表
输出LL(1)分析表

输入格式
 输入开始符号；
非终结符个数，非终结符，空格符分隔；
终结符个数，终结符，空格符分隔；
产生式的个数，各产生式的序号，产生式的左边和右边符号，空格符分隔；
LL(1)分析表中的产生式个数，序号，行符号，列符号，产生式编号，空格符分隔；
输入一个算术式符号串，用#结束

输出格式
 输出推导过程，每一步一行，中间“ & ”前是已经识别的子串，后是栈中信息。

*/
#include <iostream>
#include<string>
using namespace std;

string S="";                                                                                          //开始符号 
struct { 
    int number;
    string sign[20]; 
    string res_LL[20][20]; 
} not_endsign={0};                       
struct { 
    int number;
    string sign[20]; 
} end_sign={0};                                                  
struct { 
    int number;
    int order[100]; 
    string left[100],right[100]; 
} production={0};                    
struct { 
    int number;
    int order[100]; 
    string rank[100],col[100];
    int production_num[100];  
} LL={0};   

void input();
void print(string a);

int main(){
    input();
    end_sign.sign[end_sign.number] = "#";
    end_sign.number++; 
    for(int i=0;i<LL.number;i++){ 
        int j;
        for(j=0; j<not_endsign.number&& not_endsign.sign[j]!=LL.rank[i]; j++ ); 
        int z;
        for(z=0; z<end_sign.number&&end_sign.sign[z]!=LL.col[i]; z++ );  
        not_endsign.res_LL[j][z] = production.right[LL.production_num[i]-1 ];
    }  
    cout<<"     ";
    for(int i=0;i<end_sign.number;i++) cout<<"    "<<end_sign.sign[i];
    cout<<endl;  
    for(int i=0;i<not_endsign.number;i++){
        print(not_endsign.sign[i]); 
        cout<<not_endsign.sign[i];
        for(int j=0;j<end_sign.number ;j++){
            print(not_endsign.res_LL[i][j] );
            cout<<not_endsign.res_LL[i][j];
        }
        cout<<endl;
    }  
    return 0;
} 

void print(string a){
    for(int i=0;i<5-a.length();i++)  cout<<" ";
    return ;
}
void input(){
    cin>>S;
    cin>>not_endsign.number;
    for(int i=0;i<not_endsign.number;i++)
        cin>>not_endsign.sign[i];
    cin>>end_sign.number;
    for(int i=0;i<end_sign.number;i++)
        cin>>end_sign.sign[i]; 
    cin>>production.number;
    for(int i=0;i<production.number;i++)
        cin>>production.order[i]>>production.left[i]>>production.right[i];
    
    cin>>LL.number;
    for(int i=0;i<LL.number;i++)
        cin>>LL.order[i]>>LL.rank[i]>>LL.col[i]>>LL.production_num[i];
    return ;
}    