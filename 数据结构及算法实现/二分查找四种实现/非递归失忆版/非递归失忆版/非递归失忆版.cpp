#include <iostream>
#include <cstdlib>
using namespace std;

enum Error_code{not_present, success};
Error_code binarySearch(int p[10], const int& x, int bottom, int top, int& position)
{
	while(bottom < top)
	{
		int mid = (bottom + top) / 2;
		if(p[mid] < x)
			bottom = mid + 1;
		else 
			top = mid;
	}
	if(top < bottom)
		return not_present;
	else 
	{
		position = bottom;
		return success;
	}
		
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
		if(binarySearch(a, x, bottom, top, position) == success)
			cout << position << endl;
		else
			cout << "not present" << endl;
	}
	system("pause");
	return 0;
}