#include<bits/stdc++.h>
using namespace std;
const int MAX = 30001;
int gem[MAX], dp[MAX][500];
int main()
{
	int n, d, p;
	while(scanf("%d%d", &n, &d) != EOF)
	{
		memset(gem, 0, sizeof(gem));
		while(n--)
		{
			scanf("%d", &p);
			gem[p]++;
		}
		memset(dp, -1, sizeof(dp));
		dp[d][250] = gem[d];
		int ans = 0;
		for(int i = d; i < MAX; i++)
		{
			for(int j = 0; j < 500; j++)
			{
				if(dp[i][j] == -1)
					continue;
				int t = j - 250 + d;
				if(t > 1 && i + t - 1 < MAX)
					dp[i + t - 1][j - 1] = max(dp[i + t - 1][j - 1], dp[i][j] + gem[i + t - 1]);
				if(i + t < MAX)
                    dp[i + t][j] = max(dp[i + t][j], dp[i][j] + gem[i + t]);
                if(i + t + 1< MAX)
                    dp[i + t + 1][j + 1] = max(dp[i + t + 1][j + 1], dp[i][j] + gem[i + t + 1]);
                ans = max(ans , dp[i][j]);
            }
		}
		printf("%d\n", ans);
	}
	return 0;
}
