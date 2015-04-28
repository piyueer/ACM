#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> G[MAX], vec[MAX];
stack<int> mystack;
int vis[MAX], pre[MAX], lowlink[MAX], sccno[MAX], sccsz[MAX], dfs_clock, scc_cnt, cnt, cycle;
void dfs(int u)
{
	pre[u] = lowlink[u] = ++dfs_clock;
	mystack.push(u);
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(!pre[v])
		{
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(!sccno[v])
			lowlink[u] = min(lowlink[u], pre[v]);
	}
	if(lowlink[u] == pre[u])
	{
		scc_cnt++;
		while(true)
		{
			int x = mystack.top();
			mystack.pop();
			sccno[x] = scc_cnt;
			sccsz[scc_cnt]++;
			if(x == u)
				break;
		}
	}
}
void find_scc(int n)
{
	dfs_clock = scc_cnt = 0;
	memset(sccsz, 0, sizeof(sccsz));
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	for(int i = 1; i <= n; i++)
		if(!pre[i])
			dfs(i);
}
void dfs2(int u)
{
	cnt++;
	if(sccsz[sccno[u]] > 1)
		cycle = 1;
	vis[u] = true;
	for(int i = 0; i < vec[u].size(); i++)
	{
		int v = vec[u][i];
		if(!vis[v])
			dfs2(v);
	}
}
int main()
{
	int n, m, u , v;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			G[i].clear();
			vec[i].clear();
		}
		while(m--)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		find_scc(n);
		memset(vis, false, sizeof(vis));
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
			{
				cnt = cycle = 0;
				dfs2(i);
				ans += cnt - (1 - cycle);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
