#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector<int> G[MAX];
bool vis[MAX];
void dfs(int u)
{
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(!vis[v])
		{
			vis[v] = true;
			dfs(v);
		}
	}
}
int main()
{
	int n, u, v, m;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		for(int i = 1; i <= n; i++)
			G[i].clear();
		while(scanf("%d", &u) != EOF)
		{
			if(u == 0)
				break;
			while(scanf("%d", &v) != EOF)
			{
				if(v == 0)
					break;
				G[u].push_back(v);
			}
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &u);
			memset(vis, false, sizeof(vis));
			dfs(u);
			int ans = 0;
			for(int i = 1; i <= n; i++)
				if(!vis[i])
					ans++;
			printf("%d", ans);
			for(int i = 1; i <= n; i++)
				if(!vis[i])
					printf(" %d", i);
			putchar('\n');
		}
	}
	return 0;
}
