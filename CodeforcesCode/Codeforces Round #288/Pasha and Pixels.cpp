#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;
bool vis[MAX][MAX];
bool ok(int x, int y)
{
	return vis[x][y] && vis[x][y + 1] && vis[x + 1][y] && vis[x + 1][y + 1];
}
int main()
{
	int n, m, k, x, y;
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		memset(vis, false, sizeof(vis));
		int ans = 0;
		for(int i = 1; i <= k; i++)
		{
			scanf("%d%d", &x, &y);
			if(ans)
				continue;
			vis[x][y] = true;
			if(ok(x, y) || ok(x - 1, y) || ok(x, y - 1) || ok(x - 1, y - 1))
				ans = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
