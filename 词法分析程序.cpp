/*设一语言的关键词、运算符、分界符的个数与单词如下： 
struct { int number; string str[10]; } keywords={3,"int","main","return"} ; //关键词
struct { int number; string str[10]; } operators ={5,"+","*","=","+=","*="}; //运算符
struct { int number; string str[10]; } boundaries ={6,"(",")","{","}",",",";"} ; //分界符
struct { int number; string str[100];} identifieres={0}; //标识符
struct { int number; string str[100];} Unsigned_integer={0}; //无符号整数
以上类号分别为1~5，序号从0开始；
标识符是字母开头的字母数字串；常量为无符号整数；
用C++设计一程序实现词法分析。

输入格式
输入一程序，结束符用”#”；

输出格式
输出单词数对：<类号，序号>。 输出标识符表，用空格分隔； 输出无符号整数表，用空格分隔；

样例输入
 将样例输入复制到剪贴板 
main()
{ int a=2,b=3;
  return 2*b+a;
}#
样例输出
<1,1><3,0><3,1><3,2><1,0><4,0><2,2><5,0><3,4><4,1><2,2><5,1><3,5><1,2><5,0><2,1>
<4,1><2,0><4,0><3,5><3,3>
identifieres:a b
Unsigned_integer:2 3*/
#include <iostream>
#include <cstring>
 using namespace std;
 
 struct { int number; string str[10]; } keywords={3,"int","main","return"} ;         //关键词 
 struct { int number; string str[10]; } operators ={5,"+","*","=","+=","*="};        //运算符 
 struct { int number; string str[10]; } boundaries ={6,"(",")","{","}",",",";"} ;    //分界符 
 struct { int number; string str[100];} identifieres={0};                            //标识符 
 struct { int number; string str[100];} Unsigned_integer={0};                        //无符号整数 

 char k=0;
 string st=""; 
 int main(){
     int i;    char ch;  bool nochar=1;     
     
     do{
         if(nochar)cin.get(ch);
         if(ch=='('){st+="<3,0>";nochar=1;} 
         else if(ch==')'){ st+="<3,1>";nochar=1; }    
         else if(ch=='{'){ st+="<3,2>";nochar=1; }  
         else if(ch=='}'){ st+="<3,3>";nochar=1; }    
         else if(ch==','){ st+="<3,4>";nochar=1; }    
         else if(ch==';'){ st+="<3,5>";nochar=1; }      
         else if(ch=='+'){
             cin.get(ch); 
             if(ch=='='){    
                 st+="<2,3>";nochar=1;  
             } 
             else{
                 st+="<2,0>";nochar=1;     
             } 
         }
         else if(ch=='*'){
             cin.get(ch); 
             if(ch=='='){
                 st+="<2,4>";nochar=1;
             } 
             else{
                 st+="<2,1>";nochar=1;     
             } 
         }
         else if(ch=='='){
             st+="<2,2>";nochar=1;      
         }
         else if('0'<=ch&&ch<='9'){
             string nstring=""; nochar=0;
             do{
                 nstring+=ch;
                 cin.get(ch); 
             } while('0'<=ch&&ch<='9');
             for(k=0;k<Unsigned_integer.number&&Unsigned_integer.str[k]!=nstring;k++ );
     
             if(k==Unsigned_integer.number ){
                 Unsigned_integer.str[k] = nstring;
                 st+="<5,";st+=char('0'+k); st+=">";
                 Unsigned_integer.number++;  
             }
             else{ 
                st+="<5,";st+=char('0'+k);st+=">";   
             }
         }
         else if('a'<=ch&&ch<='z'||'A'<=ch&&ch<='Z'){ 
             string nstring="";nochar=0;
             do{
                 nstring+=ch;
                 cin.get(ch);
             } while('a'<=ch&&ch<='z'||'A'<=ch&&ch<='Z') ;  //读入关键字或者标示符的东西              
             for(k=0;k<= keywords.number &&keywords.str[k]!=nstring;k++ );               
             if(k<keywords.number ){
                 //测得输入字符是关键字之一 
                 st+="<1,";   st+=char('0'+k);st+=">";   
             }                  
             else{
                 //测得输入字符不是关键字之一，而是标识符   
                 for(k=0;k<identifieres.number && identifieres.str[k]!=nstring;k++ );    //检查是否是已经记录过的标识符 
                 if(k==identifieres.number ){                //不是已经标识过的标识符 
                     identifieres.str[k]=nstring;
                     st+="<4,";st=st+char('0'+k);st+=">";   
                     identifieres.number++;  
                 }
                 else{
                     st+="<4,";st=st+char('0'+k);st+=">"; 
                 }
             }
        }
         else nochar=1;  
        
     } while(ch!='#');
     
     cout<<st<<endl;
     cout<<"identifieres:";
         for(i=0;i<identifieres.number;i++ ){cout<<identifieres.str[i]<<" ";}    cout<<endl;
     cout<<"Unsigned_integer:"; 
         for(i=0;i<Unsigned_integer.number;i++ ){cout<<Unsigned_integer.str[i]<<" ";}   cout<<endl;
     
     return 0;    
 }        