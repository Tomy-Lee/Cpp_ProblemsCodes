#include<iostream>
# include<cstring>
#include<algorithm> 
using namespace std;

int w[300],c[300],f[300010]; 
int V, n; 
int main(){
	cout<<"�����뱳����������Ʒ��������"<<endl;
    cin>>V>>n;
    cout<<"������ÿ����Ʒ�������ͼ�ֵ��"<<endl;
    for(int i=1;i<=n;i++){cin>>w[i]>>c[i];} 
    for(int i=1;i<=n;i++) 
        for(int j=w[i];j<=V;j++)f[j]=max(f[j],f[j-w[i]]+c[i]); 
    cout<<"������װ������ֵ��"<<f[V]<<endl; 
    return 0; 
}
