#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include"assert.h"
#include<stdio.h> 
using namespace std;
typedef struct Node {
    int data;              //单链表中的数据域 
    struct Node *next;          //单链表的指针域 
}Node,*LinkedList;
 
LinkedList LinkedListCreatT(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                  //初始化一个空链表
    Node *r;
    r = L;                          //r始终指向终端结点，开始时指向头结点 
    int num;                         //x为链表数据域中的数据
    string nums;                   
    getline(cin, nums);           //先将输入作为一个字符串保存
    istringstream istr(nums);
    while(istr >> num)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点 
        p->data = num;                     //结点数据域赋值 
        r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL 
        r = p; 
    }
    r->next = NULL;    
    return L;   
}

LinkedList LinkedListDelete(LinkedList L,int x){
    Node *p,*s=L->next;
	     while(s->next->next!=NULL && s->next->next->data!=x)
	           s=s->next;
	     assert(s->next->next);
	     p=s->next;
	     s->next=p->next;
	     delete p;
	     return L;
} 

int main() {   
    int x;
    LinkedList list,start;
    cout<<"请输入链表，空格隔开，以回车结束：";
    list = LinkedListCreatT();
    cout<<"请输入要删除的元素的值：";
    cin >> x;
    LinkedListDelete(list,x); 
    cout<<"删除后链表为：";
    for(start = list->next; start != NULL; start = start->next)
        cout << start->data << " ";
    cout << endl;
    return 0;
}
