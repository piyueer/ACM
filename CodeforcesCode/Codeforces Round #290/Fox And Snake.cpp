#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(j == 0)
					putchar(i % 4 == 1 ? '.' : '#');
				else if(j == m - 1)
					putchar(i % 4 == 3 ? '.' : '#');
				else
					putchar(i % 2 == 1 ? '.' : '#');
			}
			putchar('\n');
		}
	}
	return 0;
}
