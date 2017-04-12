#include <iostream>
#include <cstdlib>
using namespace std;

enum Error_code{not_present, success};
Error_code binarySearch(int p[10], const int& x, int bottom, int top, int& position)
{
	while(bottom <= top)
	{		
		int mid = (bottom + top) / 2;	
		if(x < p[mid])
			top = mid - 1;
		else if(x > p[mid])
			bottom = mid + 1;
		else if(x == p[mid])
		{
			position = mid;
			return success;
		}
	}
	return not_present;
}
int main()
{
	int a[10];
	for(int i = 0; i < 9; i++)
		a[i] = i + 1;
	int bottom = 0, top = 9, position;
	int x;
	while(cin >> x)
	{
		binarySearch(a, x, bottom, top, position);
		cout << position << endl;
	}
	system("pause");
	return 0;
}