#include <iostream>
using namespace std;

void per(int n, int *p, int current)
{
	int i, j;
	if(current == n)
	{
		for(i = 0; i < n; i ++)
			cout << p[i] << " ";
		cout << endl;
	}
	else 
		for(i = 1; i <= n; i++)
		{
			bool flag = true;
			for(j = 0; j < current; j++)
				if(p[j] == i)
					flag = false;
			if(flag)
			{
				p[current] = i;
				per(n, p, current + 1);
			}
		}
}
int main()
{
	int n;
	while(cin >> n)
	{
		int a[5];
		for(int i = 0; i < n; i++)
			a[i] = i + 1;
		per(n, a, 0);
	}
	system("pause");
	return 0;
}