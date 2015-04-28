#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector<int> G[MAX][MAX];
bool vis[MAX], ok;
void dfs(int u, int ed, int c)
{
	vis[u] = true;
	if(ok)
		return;
	if(u == ed)
	{
		ok = true;
		return;
	}
	for(int i = 0; i < G[u][c].size(); i++)
	{
		int v = G[u][c][i];
		if(!vis[v])
			dfs(v, ed, c);
	}
}
int main()
{
	int n, m, q, u, v, c;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				G[i][j].clear();
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			G[u][c].push_back(v);
			G[v][c].push_back(u);
		}
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &u, &v);
			int ans = 0;
			for(int c = 1; c <= m; c++)
			{
				memset(vis, false, sizeof(vis));
				ok = false;
				dfs(u, v, c);
				if(ok)
					ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
