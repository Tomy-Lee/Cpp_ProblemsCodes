#include<bits/stdc++.h>
using namespace std;

void insertSort(vector<int>& a,  int length){  // �������� 
	for (int i = 1; i < length; i++){
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--){
			swap(a[j], a[j + 1]);
		}
	}
}

void quickSort(vector<int>& tmp, int left, int right){ //���� 
	if(left >= right) return ;
	int i = left, j = right;
	int con = tmp[left];
	while(i < j){
		while(i < j && tmp[j] >= con) j--;
		while(i < j && tmp[i] <= con) i++;
		if(i < j) swap(tmp[i],tmp[j]);
	}
	tmp[left]=tmp[i];
	tmp[i]=con;
	quickSort(tmp,left,i-1);
	quickSort(tmp,i+1,right);
}

void hillSort(vector<int>& tmp, int n){ //ϣ������ 
	if(n <= 1) return ;
	int i, j;
	for(int gap = n / 2; gap > 0; gap /= 2){
		for(i = 0; i < n; i++){
			for(j = i - gap; j >= 0; j -= gap){
				if(tmp[i] > tmp[j]) break;
			}
			int now = tmp[i];
			for(int k = i; k > j; k -= gap){
				tmp[k] = tmp[k-gap];
			}
			tmp[j+gap]=now;
		}
		cout<<endl;
		cout<<"Now the gap is:"<<gap<<endl;
		cout<<"Now the vector is:";
		for(int a = 0; a < tmp.size(); a++)cout<<tmp[a]<<" ";
		cout<<endl;
	}
}

void Heap_build(vector<int> &a,int root,int length){ //���� 
    int lchild = root*2+1;                 //���ڵ�����ӽ���±�
    if (lchild < length){               //���ӽ���±겻�ܳ�������ĳ���
        int flag = lchild;           //flag�������ҽڵ������ֵ���±�
        int rchild = lchild+1;       //���ڵ�����ӽ���±�
        if (rchild < length){      //���ӽ���±겻�ܳ�������ĳ���(����еĻ�)
            if (a[rchild] > a[flag]){        //�ҳ������ӽ���е����ֵ
                flag = rchild;
            }
        }
        if (a[root] < a[flag]){
            //���������ͱȸ����������ӽڵ�
            swap(a[root],a[flag]);
            //�Ӵ˴�����ӽڵ���Ǹ�λ�ÿ�ʼ�ݹ齨��
            Heap_build(a,flag,length);
        }
    }
}
 
void heapSort(vector<int> &a,int len){        //������ 
    for (int i = len/2; i >= 0; --i){     //�����һ����Ҷ�ӽڵ�ĸ���㿪ʼ����
        Heap_build(a,i,len);
    }
 
    for (int j = len-1; j > 0; --j){    //j��ʾ�����ʱ�ĳ��ȣ���Ϊlen�����Ѿ������ˣ���len-1��ʼ
        swap(a[0],a[j]);        //������βԪ��,�����ֵ��������������λ�ñ���
        Heap_build(a,0,j);          //ȥ�����λ�õ�Ԫ�����½��ѣ��˴�j��ʾ����ĳ��ȣ����һ��λ���±��Ϊlen-2
    }
}

void merge(vector<int> &arr,int low,int mid,int high){     //�鲢���� 
                                       //lowΪ��1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
    int i=low,j=mid+1,k=0;                //mid+1Ϊ��2��������1��Ԫ�أ�jָ���1��Ԫ��
    int *temp=new(nothrow) int[high-low+1]; //temp�����ݴ�ϲ�����������
    if(!temp){               //�ڴ����ʧ��
        cout<<"error";
        return;
    }
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j])   //��С���ȴ���temp��
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)          //���Ƚ���֮�󣬵�һ������������ʣ�࣬��ֱ�Ӹ��Ƶ�t������
        temp[k++]=arr[i++];
    while(j<=high)          //ͬ��
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)             //���ź���Ĵ��arr��low��high������
		arr[i]=temp[k];
    delete []temp;       //ɾ��ָ�룬����ָ��������飬������delete []
}
 

void mergeSort(vector<int> &arr,int low,int high){     //�õݹ�Ӧ�ö�·�鲢����ʵ�����򡪡����η�
    if(low<high){ //low, high�����Ҷ˵���±꣬�����䡣[low,high]
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void mergeSort2(vector<int> &arr,int n){       //�ǵݹ�汾�鲢����   //n�����鳤��
	int size=1,low,mid,high;
	while(size<=n-1){
		low=0;
		while(low+size<=n-1){
			mid=low+size-1;
			high=mid+size;
			if(high>n-1)           //�ڶ������и�������size
				high=n-1;
			merge(arr,low,mid,high);     //���ù鲢�Ӻ���
			low=high+1;          //��һ�ι鲢ʱ��һ�����е��½�
		}
		size*=2;                   //��Χ����һ��
	}
}

int main(){
	clock_t start,finish;
    vector<int> ans;
    int x=15,a;
    int si = x;
    while(x > 0){
    	a=rand()%100+1;
    	ans.push_back(a);
    	x--;
    }
    cout<<"The initial vector is:";
    for(int i = 0; i < si; i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    start=clock();
    //insertSort(ans, si);
    //quickSort(ans,0,si-1);
    //hillSort(ans,si);
    //heapSort(ans,si);
    mergeSort(ans,0,si-1);
    //mergeSort2(ans,si);
    finish=clock();
    double totaltime=(double)(finish-start)/CLOCKS_PER_SEC;  //��������ʱ�� 
    for(int i = 0; i < si; i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Total time to sort is "<<totaltime<<"s"<<endl;
	return 0;
}
