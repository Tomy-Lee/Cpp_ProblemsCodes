#include <iostream>
#include <cstdlib>
using namespace std;

enum Error_code{not_present, success};
Error_code binarySearch(int p[10], const int& x, int bottom, int top, int& position)
{
	if(bottom <= top)
	{
		int mid = (bottom + top) / 2;
		if(x == p[mid])
		{
			position = mid;
				return success;
		}
		else if(x < p[mid])
			return binarySearch(p, x, bottom, mid - 1, position);
		else 
			return binarySearch(p, x, mid + 1, top, position);
	}
	else
		return not_present;
}
int main()
{
	int a[10];
	for(int i = 0; i < 10; i++)
		a[i] = i + 1;
	int bottom = 0, top = 9, position;
	int x;
	while(cin >> x)
	{
		if(binarySearch(a, x, bottom, top, position) == success)
			cout << position << endl;
		else cout << "not_present" << endl;
	}
	system("pause");
	return 0;
}