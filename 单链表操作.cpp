#include<bits/stdc++.h>
using namespace std;
typedef int DataType;
struct ListNode
{
    DataType data;
    ListNode *next;
    ListNode (){};
    ListNode(int v,ListNode *_node=NULL):data(v),next(_node){};
};
ListNode* arraytolist (vector<int> a);
void printlist(ListNode* fir);
void insert(ListNode* p, int poi,int in);
void deletenode(ListNode* p, int poi);
void selectionsort(ListNode* p);
ListNode* reverse(ListNode* p);
ListNode* reverse_NoRecursive(ListNode* a);
ListNode* reverseK(ListNode* p,int k);
ListNode* reverseM(ListNode* p,int left,int right);
ListNode* reverseKGroup(ListNode* head, int k);

int main(){
    vector<int> a({0,1,2,3,4,5,6,7,8,9});
    ListNode* b=arraytolist(a);
    printlist(b);
    cout<<"插入后链表元素：";
    insert(b,2,10);
    printlist(b);
    deletenode(b,2);
    cout<<"删除后链表元素：";
    printlist(b);
    //ListNode* res1 = reverse(b);
    ListNode* res1 = reverse_NoRecursive(b);
    cout<<"反转后链表元素：";
    printlist(res1);
    ListNode* res2 = reverseK(res1,3);
    cout<<"反转K个后链表元素：";
    printlist(res2);
    ListNode* res3 = reverseM(res2,3,7);
    cout<<"反转区间后链表元素：";
    printlist(res3);
    ListNode* res4 = reverseKGroup(res3,3);
    cout<<"K个一组反转后链表元素：";
    printlist(res4);
    return 0;
}
ListNode* arraytolist (vector<int> a){      //构造单链表
    if(a.empty()) return NULL;
    else {
        ListNode *tmp = new ListNode(a[0]);
        ListNode *head = tmp;
        for(int i = 1; i < a.size(); i++){
            ListNode *p = new ListNode(a[i]);
            tmp->next=p;
            tmp=p;
        } 
        return head;
    }
}
void printlist(ListNode *tmp){      //输出链表
    if(tmp) cout<<tmp->data;
    while(tmp->next != NULL){
        cout<<"->";
        tmp=tmp->next;
        cout<<tmp->data;
    }
    cout<<endl;
}
void insert(ListNode* p, int poi,int in){       //插入节点
    if(poi < 0) return ;
    while(poi > 0){
        if(p->next != NULL) p=p->next;
        else break;
        poi--;
    }
    ListNode *tmp = new ListNode(in);
    tmp->next=p->next;
    p->next=tmp;
}
void deletenode(ListNode* p, int poi){      //删除节点
    if(poi < 0) return ;
    while(poi > 1){
        if(p->next != NULL) p=p->next;
        else break;
        poi--;
    }
    if(p->next != NULL){
        ListNode *tmp = p->next;
        p->next=tmp->next;
        delete tmp;
    }
}
ListNode* reverse(ListNode* p){     //反转整个单链表，返回反转后的头结点
    if(p->next == NULL) return p;
    ListNode* tmp = reverse(p->next);
    p->next->next = p;
    p->next=NULL;
    return tmp;
}

ListNode* reverse_NoRecursive(ListNode* a) {      //非递归反转整个单链表，返回反转后的头结点
    ListNode *pre, *cur, *nxt;
    pre = NULL; cur = a; nxt = a;
    while (cur != NULL) {
        nxt = cur->next;
        // 逐个结点反转
        cur->next = pre;
        // 更新指针位置
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}

ListNode* successor=NULL; //后驱节点
ListNode* reverseK(ListNode* p,int k){      //反转前K个节点
    if(k==1){       //base case
        successor=p->next;
        return p;
    }
    ListNode* last = reverseK(p->next,k-1);
    p->next->next = p;
    p->next=successor;
    return last;
}

ListNode* reverseM(ListNode* p,int left,int right){      //反转链表一部分[left,right]
    if(left==1){     
        return reverseK(p,right);
    }
    p->next=reverseM(p->next,left-1,right-1);
    return p;
}

ListNode* reverseAB(ListNode* a, ListNode* b) {
    ListNode *pre, *cur, *nxt;
    pre = NULL; cur = a; nxt = a;
    // while 终止的条件改一下就行了
    while (cur != b) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {        //每K个一组反转链表
    if (head == NULL) return NULL;
    // 区间 [a, b) 包含 k 个待反转元素
    ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; i++) {
        // 不足 k 个，不需要反转，base case
        if (b == NULL) return head;
        b = b->next;
    }
    // 反转前 k 个元素
    ListNode* newHead = reverseAB(a, b);
    // 递归反转后续链表并连接起来
    a->next = reverseKGroup(b, k);
    return newHead;
}