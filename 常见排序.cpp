#include<bits/stdc++.h>
using namespace std;

void insertSort(vector<int>& a,  int length){  // 插入排序 
	for (int i = 1; i < length; i++){
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--){
			swap(a[j], a[j + 1]);
		}
	}
}

void quickSort(vector<int>& tmp, int left, int right){ //快排 
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

void hillSort(vector<int>& tmp, int n){ //希尔排序 
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

void Heap_build(vector<int> &a,int root,int length){ //建堆 
    int lchild = root*2+1;                 //根节点的左子结点下标
    if (lchild < length){               //左子结点下标不能超出数组的长度
        int flag = lchild;           //flag保存左右节点中最大值的下标
        int rchild = lchild+1;       //根节点的右子结点下标
        if (rchild < length){      //右子结点下标不能超出数组的长度(如果有的话)
            if (a[rchild] > a[flag]){        //找出左右子结点中的最大值
                flag = rchild;
            }
        }
        if (a[root] < a[flag]){
            //交换父结点和比父结点大的最大子节点
            swap(a[root],a[flag]);
            //从此次最大子节点的那个位置开始递归建堆
            Heap_build(a,flag,length);
        }
    }
}
 
void heapSort(vector<int> &a,int len){        //堆排序 
    for (int i = len/2; i >= 0; --i){     //从最后一个非叶子节点的父结点开始建堆
        Heap_build(a,i,len);
    }
 
    for (int j = len-1; j > 0; --j){    //j表示数组此时的长度，因为len长度已经建过了，从len-1开始
        swap(a[0],a[j]);        //交换首尾元素,将最大值交换到数组的最后位置保存
        Heap_build(a,0,j);          //去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
    }
}

void merge(vector<int> &arr,int low,int mid,int high){     //归并排序 
                                       //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=low,j=mid+1,k=0;                //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp=new(nothrow) int[high-low+1]; //temp数组暂存合并的有序序列
    if(!temp){               //内存分配失败
        cout<<"error";
        return;
    }
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j])   //较小的先存入temp中
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)          //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j<=high)          //同上
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)             //将排好序的存回arr中low到high这区间
		arr[i]=temp[k];
    delete []temp;       //删除指针，由于指向的是数组，必须用delete []
}
 

void mergeSort(vector<int> &arr,int low,int high){     //用递归应用二路归并函数实现排序——分治法
    if(low<high){ //low, high是左右端点的下标，闭区间。[low,high]
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void mergeSort2(vector<int> &arr,int n){       //非递归版本归并排序   //n是数组长度
	int size=1,low,mid,high;
	while(size<=n-1){
		low=0;
		while(low+size<=n-1){
			mid=low+size-1;
			high=mid+size;
			if(high>n-1)           //第二个序列个数不足size
				high=n-1;
			merge(arr,low,mid,high);     //调用归并子函数
			low=high+1;          //下一次归并时第一关序列的下界
		}
		size*=2;                   //范围扩大一倍
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
    double totaltime=(double)(finish-start)/CLOCKS_PER_SEC;  //计算排序时间 
    for(int i = 0; i < si; i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Total time to sort is "<<totaltime<<"s"<<endl;
	return 0;
}
