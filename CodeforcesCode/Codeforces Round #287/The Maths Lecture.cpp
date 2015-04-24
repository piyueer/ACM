#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1005;
const int MAXK = 105;
LL dp[MAXN][MAXK][2], base[MAXN];
int main()
{
	int n, k, mod;
	while(scanf("%d%d%d", &n, &k, &mod) != EOF)
	{
		base[0] = 1 % mod;
		for(int i = 1; i <= n; i++)
			base[i] = base[i - 1] * 10LL % k;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < k; j++)
			{
				for(int x = 0; x < 10; x++)
				{
					if(i == n - 1 && x == 0)
						continue;
					LL temp = (x * base[i] + j) % k;
					if(temp == 0 && x != 0)
					{
						dp[i + 1][temp][1] += dp[i][j][0];
						dp[i + 1][temp][1] %= mod;
					}
					else
					{
						dp[i + 1][temp][0] += dp[i][j][0];
						dp[i + 1][temp][0] %= mod;
					}
					dp[i + 1][temp][1] += dp[i][j][1];
					dp[i + 1][temp][1] %= mod;
				}
			}
		}
		LL ans = 0;
		for(int i = 0; i < k ; i++)
		{
			ans += dp[n][i][1];
			ans %= mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
