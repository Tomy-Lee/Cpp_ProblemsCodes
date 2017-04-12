#include <iostream>
using namespace std;

void quick_sort( int low, int high, int p[] )
{
	if( low >= high ) return;

	int b = low, t = high + 1;
	int pivot = p[b];

	while( 1 )
	{
		do
		{
			b++;
		}while( pivot > p[b] );
		do
		{
			t--;
		}while( pivot < p[t] );

		if( b >= t ) break;
		int tmp = p[b];
		p[b] = p[t];
		p[t] = tmp;
	}
	p[low] = p[t];
	p[t] = pivot;

	quick_sort( low, t - 1, p );
	quick_sort( t + 1, high, p );
}



int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		int n;
		cin >> n;
		int *p = new int[n];
		for( int i = 0; i < n; i++ )
			cin >> p[i];
		
		quick_sort( 0, n - 1, p );

		for( int i = 0; i < n; i++ )
			cout << p[i] << endl;
	}

	system( "pause" );
	return 0;
}