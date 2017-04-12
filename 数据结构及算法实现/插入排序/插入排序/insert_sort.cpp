#include <iostream>
using namespace std;

void insert_sort( int a[], int n )
{
	for( int i = 1; i < n; i++ )
	{
		int tmp = a[i];
		int index = i - 1;
		while( tmp < a[index] && index >= 0 )
		{
			a[index + 1] = a[index--];
		}
		a[index + 1] = tmp;
	}
}

int main()
{
	int n;
	while( cin >> n )
	{
		int a[10];
		for( int i = 0; i < 10; i++ )
			cin >> a[i];
		insert_sort( a, n );
		for( int i = 0; i < 10; i++ )
			cout << a[i] << " ";
		cout << endl;
	}
	system( "pause" );
	return 0;
}