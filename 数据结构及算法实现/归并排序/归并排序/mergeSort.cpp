#include <iostream>
using namespace std;

void merge( int a[], int l, int mid, int r )
{
	int *tmp = new int[r - l + 1];
	int beg1, end1, beg2, end2;
	beg1 = l, end1 = mid, beg2 = mid + 1, end2 = r;
	
	int cur = 0;
	while( beg1 <= end1 && beg2 <= end2 )
	{
		if( a[beg1] > a[beg2] )
			tmp[cur++] = a[beg2++];
		else
			tmp[cur++] = a[beg1++];
	}
	while( beg1 <= end1 || beg2 <= end2 )
	{
		if( beg1 <= end1 )
			tmp[cur++] = a[beg1++];
		if( beg2 <= end2 )
			tmp[cur++] = a[beg2++];
	}

	for( int i = 0; i < r - l + 1; i++ )
		a[l + i] = tmp[i];//不可以用l++， 不然就会改变参数值导致严重错误！
	delete []tmp;
}


void merge_sort( int a[], int l, int r )
{
	int mid = 0;
	if( l < r )
	{
		mid = ( l + r ) / 2;
		merge_sort( a, l, mid );
		merge_sort( a, mid + 1, r );
		merge( a, l, mid, r );
	}
}

int main()
{
	int t;
	cin >> t;
	
	while( t-- )
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for( int i = 0; i < n; i++ )
			cin >> a[i];
		merge_sort( a, 0, n - 1 );

		for( int i = 0; i < n; i++ )
			cout << a[i] << endl;
		//cout << endl;
	}
	system("pause");
	return 0;
}