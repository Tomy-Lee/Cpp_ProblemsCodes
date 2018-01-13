#include<iostream>
# include<cstring>
#include<algorithm> 
using namespace std;

int w[300],c[300],f[300010]; 
int V, n; 
int main(){
	cout<<"请输入背包容量和物品种类数："<<endl;
    cin>>V>>n;
    cout<<"请输入每种物品的重量和价值："<<endl;
    for(int i=1;i<=n;i++){cin>>w[i]>>c[i];} 
    for(int i=1;i<=n;i++) 
        for(int j=w[i];j<=V;j++)f[j]=max(f[j],f[j-w[i]]+c[i]); 
    cout<<"背包可装的最大价值："<<f[V]<<endl; 
    return 0; 
}
