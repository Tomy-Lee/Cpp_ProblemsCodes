#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<stdlib.h>  
#include<queue>  
#include<stack>  
#include<set>  
#include<algorithm>  
using namespace std;  
priority_queue<int,vector<int>,greater<int> >q;  
int sum,need;  
int num[40];  
void huffman()  
{  
    int a,b,c;  
    while(q.size()!=1)  
    {  
        a=q.top();  
        q.pop();  
        b=q.top();  
        q.pop();  
        c=a+b;  
        need+=c;  
        q.push(c);  
    }  
    printf("%d %d %.1lf\n",sum,need,(double)sum/(double)need);  
}  
int main()  
{  
    int i,j,l;  
    char str[1010];  
    while(gets(str))  
    {  
        if(strcmp(str,"END")==0)  
        break;  
        l=strlen(str);  
        sum=l*8;  
        memset(num,0,sizeof(num));  
        while(!q.empty())  
        {  
            q.pop();//Çå¿Õ¶ÓÁÐ   
        }  
        for(i=0;i<l;i++)  
        num[str[i]-'A']++;  
        for(i=0;i<=30;i++)  
        {  
            if(num[i])  
            q.push(num[i]);  
        }  
        if(q.size()==1)  
        {  
            printf("%d %d %.1lf\n",sum,l,(double)sum/(double)l);  
            continue;  
        }  
        need=0;  
        huffman();  
    }  
    return 0;  
}   
