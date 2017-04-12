#include <iostream>
using namespace std;
int p[10000];
void insert_heap( int x, int low, int high )
{
	int large = low * 2 + 1;
	while( large <= high )
	{
		if( large < high && p[large] < p[large + 1] ) large++;
		if( x >= p[large] ) break;
		else
		{
			p[low] = p[large];
			low = large;
			large = low * 2 + 1;
		}
	}
	p[low] = x;
}

void heap_sort( int low, int high )
{
	for( int i = high / 2 - 1; i >= 0; i-- )
		insert_heap( p[i], i, high - 1 );

	for( int i = high - 1; i > 0; i-- )
	{
		int x = p[i];
		p[i] = p[0];
		insert_heap( x, 0, i - 1 );
	}
}


int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		memset( p, 0, sizeof( p ) / sizeof( int ));

		int n;
		cin >> n;
		for( int i = 0; i < n; i++ )
			cin >> p[i];

		heap_sort( 0, n );
		for( int i = 0; i < n; i++ )
			cout << p[i] << endl;
	}
	system("pause");
	return 0;
}