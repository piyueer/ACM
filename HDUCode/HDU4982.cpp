#include<cstdio>
bool isok(int n, int sum, int p)
{
	int pp = sum - n * (n - 1) / 2;
	if(pp <= n - 1)
		return false;
	if(p > pp)
		return true;
	else if(p == pp)
	{
		if(pp - 1 > n - 1 + 1)
			return true;
		else
			return false;
	}
	else if(p > n - 1)
		return true;
	else
	{
		if(pp - (n - p) > n)
			return true;
		else
			return false;
	}
}
int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		bool ok = false;
		for(int i = 1; i * i < n; i++)
		{
			if(isok(k - 1, i * i, n - i * i))
			{
				ok = true;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
