#include <iostream>
using namespace std;

void permutation(int len, int *num, int current)
{
	if(current == len)
	{
		for(int i = 0; i < len; i++)
			cout << num[i] << " ";
		cout << endl;
	}
	else 
		for(int i = 1; i <= len; i++)
		{
			bool flag = true;
			for(int j = 0; j < current; j++)
				if(num[j] == i) flag = false;
			if(flag)
			{
				num[current] = i;
				permutation(len, num, current + 1);
			}
		}
}

int main()
{
	int n;
	while(cin >> n && n)
	{
		int *p = new int[n];
		for(int i = 0; i < n; i++)
			p[i] = i + 1;
		permutation(n, p, 0);
	}
	return 0;
}