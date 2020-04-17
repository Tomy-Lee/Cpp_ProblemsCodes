#include<bits/stdc++.h>
using namespace std;
typedef char DataType;
//先序序列
vector<DataType> pre;
//中序序列
vector<DataType> in;
//后序序列
vector<DataType> post;

struct TreeNode
{
    DataType val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){};
    TreeNode(int v,TreeNode *_left=NULL,TreeNode *_right=NULL):val(v),left(_left),right(_right){};
};

/*-------------------------------------------------------------------------------------------------*/

TreeNode *build_pre_in(int preindex,int instart,int inend)     //根据前序和中序构造二叉树
{
    TreeNode *root=NULL;
    int i;
    int mid=-1;
    for(i=instart;i<=inend;i++)
    {
        if(pre[preindex]==in[i])
        {
            mid=i;
            break;
        }
    }
    if(mid!=-1)
    {
        root=new TreeNode;
        root->val=pre[preindex];
        root->left=build_pre_in(preindex+1,instart,mid-1);
        root->right=build_pre_in(preindex+mid-instart+1,mid+1,inend);
    }
    return root;
}

TreeNode *build_in_post(int postindex,int instart,int inend)        //根据后序和中序构造二叉树
{
    TreeNode *root=NULL;
    int i;
    int mid=-1;
    for(i=instart;i<=inend;i++)
    {
        if(post[postindex]==in[i])
        {
            mid=i;
            break;
        }
    }
    if(mid!=-1)
    {
        root=new TreeNode;
        root->val=post[postindex];
        root->right=build_in_post(postindex-1,mid+1,inend);
        root->left=build_in_post(postindex-(inend-mid)-1,instart,mid-1);
    }
    return root;
}
/*-------------------------------------------------------------------------------------------------*/

void preTravel(TreeNode *root)      //先序递归遍历
{
    if(root==NULL) return ;
    cout<<root->val;
    cout<<" ";
    preTravel(root->left);
    preTravel(root->right);
}

void inTravel(TreeNode *root)      //中序递归遍历
{
    if(root) {
        inTravel(root->left);
        cout<<root->val;
        cout<<" ";
        inTravel(root->right);
    }
    return ;
}

void postTravel(TreeNode *root)      //后序递归遍历
{
    if(root==NULL) return ;
    postTravel(root->left);
    postTravel(root->right);
    cout<<root->val;
    cout<<" ";
}
/*-------------------------------------------------------------------------------------------------*/


void levelTravel(TreeNode *root){       //层次遍历
    queue<TreeNode*> tmp;
    if(root == NULL) return ;
    tmp.push(root);
    while(!tmp.empty()){
        TreeNode* now = tmp.front();
        cout<<now->val;
        cout<<" ";
        if(now->left) tmp.push(now->left);
        if(now->right) tmp.push(now->right);
        tmp.pop();
    }
    return ;
}

/*-------------------------------------------------------------------------------------------------*/
void preTravel_NoRecursive(TreeNode *root)      //先序非递归遍历
{
    stack<TreeNode*>tmp;
    if(root==NULL) return ;
    tmp.push(root);
    while(!tmp.empty()){
        TreeNode *node = tmp.top();
        tmp.pop();
        cout<<node->val;
        cout<<" ";
        if(node->right) tmp.push(node->right);
        if(node->left) tmp.push(node->left);
    }
    return ;
}

void inTravel_NoRecursive(TreeNode *root)      //中序非递归遍历
{
    stack<TreeNode*>tmp;
    if(root==NULL) return ;
    TreeNode *cur=root;
    while(!tmp.empty() || cur != NULL){
        while(cur){
            tmp.push(cur);
            cur=cur->left;
        }
        TreeNode *node = tmp.top();
        tmp.pop();
        cout<<node->val;
        cout<<" ";
        cur=node->right;
    }
    return ;
}

void postTravel_NoRecursive(TreeNode *root)      //后序非递归遍历
{
    stack<TreeNode*>tmp;
    stack<TreeNode*>res;
    if(root==NULL) return ;
    tmp.push(root);
    while(!tmp.empty()){
        TreeNode *node = tmp.top();
        tmp.pop();
        res.push(node);
        if(node->left) tmp.push(node->left);
        if(node->right) tmp.push(node->right);
    }
    while(!res.empty()){
        TreeNode *tmpnode = res.top();
        res.pop();
        cout<<tmpnode->val;
        cout<<" ";
    }
    return ;
}

/*-------------------------------------------------------------------------------------------------*/


int main()
{
    int n;
    cin>>n;
    DataType t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        pre.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>t;
        in.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>t;
        post.push_back(t);
    }
    TreeNode *root=build_pre_in(0,0,n-1);
    //TreeNode *root=build_in_post(n-1,0,n-1);
    cout<<"前序遍历：";
    preTravel(root);
    cout<<endl;
    cout<<"中序遍历：";
    inTravel(root);
    cout<<endl;
    cout<<"后序遍历：";
    postTravel(root);
    cout<<endl;
    cout<<"层次遍历：";
    levelTravel(root);
    cout<<endl;
    cout<<"前序遍历非递归：";
    preTravel_NoRecursive(root);
    cout<<endl;
    cout<<"中序遍历非递归：";
    inTravel_NoRecursive(root);
    cout<<endl;
    cout<<"后序遍历非递归：";
    postTravel_NoRecursive(root);
    cout<<endl;
    return 0;
}
/* Test1
8
12473568
47215386
74258631 */

/* Test2
13
ABDHEIJCFKGLM
HDBIEJAFKCLGM
HDIJEBKFLMGCA */