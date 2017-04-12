#include <iostream>
using namespace std;

void shell_sort( int p[], int n )
{
	int inc = 0;
	while( inc < n )
		inc = inc * 3 + 1;
	
	while( inc > 0 )
	{
		for( int i = inc; i < n; i++ )
		{
			int idx = i;
			int t = p[i];

			while( idx - inc >= 0 && t < p[idx - inc] )//注意步长不要越界
			{
				p[idx] = p[idx - inc];
				idx -= inc;
			}
			p[idx] = t;
		}
		inc = inc / 3;
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
        int *p = new int[n];
        for( int i = 0; i < n; i++ )
            cin >> p[i];
        
        shell_sort( p, n );

        for( int i = 0; i < n; i++ )
            cout << p[i] << endl;
    }

    system( "pause" );
    return 0;
}                                 