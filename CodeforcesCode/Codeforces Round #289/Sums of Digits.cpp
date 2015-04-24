#include<bits/stdc++.h>
using namespace std;
const int MAX = 305;
int b[MAX], ans[MAX][MAX*MAX], len[MAX];
int ok(int sum, int l)
{
	return sum >= 0 && sum <= 9 * l;
}
int solve(int cnt, int sum, int begl)
{
	int l = begl;
	while(sum >= 10)
	{
		ans[cnt][l++] = 9;
		sum -= 9;
	}
	ans[cnt][l++] = sum;
	return l;
}
int solve2(int cnt, int sum)
{
	int l = len[cnt - 1];
	for(int i = 0; i < l; i++)
		ans[cnt][i] = ans[cnt - 1][i];
	for(int i = 0; i < l; i++)
	{
		if(ans[cnt][i] == 9)
			continue;
		int temp = min(sum, 9 - ans[cnt][i]);
		ans[cnt][i] += temp;
		sum -= temp;
		if(sum == 0)
			break;
	}
	return sum ? solve(cnt, sum, l) : l;
}
int solve3(int cnt, int sum)
{
	int l = len[cnt - 1];
	for(int i = 0; i < l; i++)
		ans[cnt][i] = ans[cnt - 1][i];
	int temp = b[cnt - 1] - ans[cnt][0];
	for(int i = 1; i < l; i++)
	{
		temp -= ans[cnt][i];
		for(int j = ans[cnt][i] + 1; j <= 9; j++)
		{
			if(ok(sum - (temp + j), i))
			{
				for(int k = i - 1; k >= 0; k--)
					ans[cnt][k] = 0;
				solve(cnt, sum - (temp + j), 0);
				ans[cnt][i] = j;
				return l;
			}
		}
	}
	for(int i = 1; i <= 9; i++)
	{
		if(ok(sum - i, l))
		{
			for(int k = l - 1; k >= 0; k--)
				ans[cnt][k] = 0;
			solve(cnt, sum - i, 0);
			ans[cnt][l++] = i;
			return l;
		}
	}
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
				len[i] = solve(i, b[i], 0);
			else if(b[i] > b[i - 1])
				len[i] = solve2(i, b[i] - b[i - 1]);
			else if(b[i] <= b[i - 1])
				len[i] = solve3(i, b[i]);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = len[i] - 1; j >= 0; j--)
				printf("%d", ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
