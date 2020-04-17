#include<iostream>
# include<cstring>
# define max(a,b) a>b?a:b
using namespace std;
int main(){
    int dp[101][1001],m,T,w[101],val[101],i,j;
    cout<<"请输入背包容量和物品数量："<<endl; 
    cin>>T>>m;
    cout<<"请按行输入每个物品的重量和价值："<<endl;
    for(i=1;i<=m;i++) cin>>w[i]>>val[i];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=m;i++)
     for(j=0;j<=T;j++){
    		if(j>=w[i])  dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);//放还是不放的选择
    		else dp[i][j]=dp[i-1][j];
     }
    cout << "背包可装的最大价值是：" << dp[m][T] << endl;
    system("pause");
    return 0;
} 
