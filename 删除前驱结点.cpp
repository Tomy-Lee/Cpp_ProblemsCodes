#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include"assert.h"
#include<stdio.h> 
using namespace std;
typedef struct Node {
    int data;              //�������е������� 
    struct Node *next;          //�������ָ���� 
}Node,*LinkedList;
 
LinkedList LinkedListCreatT(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //����ͷ���ռ�
    L->next = NULL;                  //��ʼ��һ��������
    Node *r;
    r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ��� 
    int num;                         //xΪ�����������е�����
    string nums;                   
    getline(cin, nums);           //�Ƚ�������Ϊһ���ַ�������
    istringstream istr(nums);
    while(istr >> num)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //�����µĽ�� 
        p->data = num;                     //���������ֵ 
        r->next = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL 
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
    cout<<"�����������ո�������Իس�������";
    list = LinkedListCreatT();
    cout<<"������Ҫɾ����Ԫ�ص�ֵ��";
    cin >> x;
    LinkedListDelete(list,x); 
    cout<<"ɾ��������Ϊ��";
    for(start = list->next; start != NULL; start = start->next)
        cout << start->data << " ";
    cout << endl;
    return 0;
}
