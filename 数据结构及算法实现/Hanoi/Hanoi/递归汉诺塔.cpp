#include <iostream>
#include <cstdlib>
using namespace std;

void hanoi(int n, int start, int tmp, int finish)
{
	if(n > 0)
	{
		hanoi(n - 1, start, finish, tmp);
		cout << n << "from" << (char)start << "to" << (char)finish << endl;
		hanoi(n - 1, tmp, start, finish);
	}
}

int main()
{
	int n;
	int start = 65, tmp = 66, finish = 67;
	while(cin >> n)
	{
		hanoi(n, start, tmp, finish);
	}
	return 0;
}