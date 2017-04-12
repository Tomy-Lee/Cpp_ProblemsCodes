/*
On BBS, there is a familiar term called MJ (short for MaJia), which means another BBS ID of one person besides his/her 
main ID.These days, a lot of ACMers pour water on the ACMICPC Board of argo. Mr. Guo is very angry about that and he 
wants to punish these guys. ACMers are all smart boys/girls, right? They usually use their MJs while pouring water, 
so Mr. Guo can not tell all the IDs apart.  Unfortunately, the IP can not be changed, i.e, the posts of main ID and MJ 
of the same person has the same IP address, meanwhile, the IP addresses of different person is different.  Assuming 
that each person has exactly one main ID and one MJ, by reading their posts on BBS, you then tell Mr. Guo whom each MJ 
belongs to. 

输入格式

The first line of each test cases is an even integer n (0<=n<=20), the number of posts on BBS.
Then n lines follow, each line consists of two strings:
BBS_ID IP_Address
BBS_ID means the ID who posts this post. BBS_ID is a string contains only lower case alphabetical characters and its length 
is not greater than 12. Each BBS ID appears only once in each test cases.
IP_Address is the IP address of that person. The IP address is formatted as “A.B.C.D”, where A, B, C, D are integers 
ranging from 0 to 255.
It is sure that there are exactly 2 different BBS IDs with the same IP address. The first ID appears in the input 
is the main ID while the other is the MJ of that person.
Your program should be terminated by n = 0.


输出格式

For each test case, output n/2 lines of the following format: “MJ_ID is the MaJia of main_ID”
They should be displayed in the lexicographical order of the main_ID.
Print a blank line after each test cases.
See the sample output for more details.


样例输入
8
inkfish 192.168.29.24
zhi 192.168.29.235
magicpig 192.168.50.170
pegasus 192.168.29.235
iamcs 202.116.77.131
finalBob 192.168.29.24
tomek 202.116.77.131
magicduck 192.168.50.170
4
mmmmmm 172.16.72.126
kkkkkk 192.168.49.161
llllll 192.168.49.161
nnnnnn 172.16.72.126
0
样例输出
tomek is the MaJia of iamcs
finalBob is the MaJia of inkfish
magicduck is the MaJia of magicpig
pegasus is the MaJia of zhi
 
llllll is the MaJia of kkkkkk
nnnnnn is the MaJia of mmmmmm*/
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct majia   //把找到的主要帐号和马甲帐号存放在结构体中
{
          string id1,id2;
};
bool cmp(const majia& mj1,const majia& mj2)
{
     return mj1.id1<mj2.id1;    //进行字符串比较
}
 
int main()
{
    int i,j,k,n;
    majia mj[11];
    string id[21],ip[21];
    while(cin>>n && n)
    {
        for(i=0;i<n;i++)
            cin>>id[i]>>ip[i];
        k=0;
        for(i=n-1;i>0;i--)
        {
            for(j=0;j<i;j++)
            {
               if(ip[j]==ip[i])
               {
                   k++; //发现马甲，就存放在结构体中
                   mj[k-1].id1=id[j];
                   mj[k-1].id2=id[i];
                   break;
               }
            }
        }
        sort(mj,mj+k,cmp);   //进行排序
        for(i=0;i<k;i++)
            cout<<mj[i].id2<<" is the MaJia of "<<mj[i].id1<<endl;
        cout<<endl;
    }
    return 0;
}        
