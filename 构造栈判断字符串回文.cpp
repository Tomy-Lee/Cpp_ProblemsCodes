#include<iostream>
using namespace std;
typedef struct l{
      char data[250];
      int top;
}stack;
void stackinit(stack &w) {
      w.top=-1;
}
void stackcreat(stack &w,char ch[]) {
     char *h;
     h=ch;
     cout<<"Õ»ÖÐ×Ö·û£º"<<endl;
     while(*h!='#') {
         w.top++;
         w.data[w.top]=*(h++);
         cout<<w.data[w.top]<<' ';
     }  
     cout<<endl;
}
void panduan(stack w,char ch[]){
     int j;
     char q;
     q=w.data[w.top];
    for(j=0;ch[j]!='#';j++){
        cout<<q<<ch[j]<<' ';
        if(q!=ch[j]){
            cout<<"no"<<endl;
            break;
    }
  else{
       w.top--; 
      q=w.data[w.top];
      if(w.top==-1) {
         cout<<endl<<"yes"<<endl;
         break;
      }
    }
  }
}
int main(){
    stack zhan;
    cout<<"ÇëÊäÈë×Ö·û´®ÒÔ#½áÊø£º"<<endl;
    char ch[250];
    cin>>ch; 
    stackinit(zhan);
    stackcreat(zhan,ch);
    cout<<ch<<endl;
    panduan(zhan,ch);
    return 0;
}
