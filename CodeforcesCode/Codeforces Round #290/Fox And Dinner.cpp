#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAX = 205;
struct Edge
{
	int from, to, cap, flow;
	Edge() {}
	Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
};
vector<Edge> edges;
vector<int> G[MAX];
int d[MAX], cur[MAX], vis[MAX];
void addEdge(int from, int to, int cap)
{
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int m = edges.size();
	G[from].push_back(m - 2);
	G[to].push_back(m - 1);
}
bool bfs(int st, int ed)
{
	queue<int> q;
	memset(d, 0, sizeof(d));
	memset(vis, false, sizeof(vis));
	q.push(st);
	d[st] = 0;
	vis[st] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); i++)
		{
			Edge& e = edges[G[u][i]];
			if(!vis[e.to] && e.cap > e.flow)
			{
				vis[e.to] = true;
				d[e.to] = d[u] + 1;
				q.push(e.to);
			}
		}
	}
	return vis[ed];
}
int dfs(int u, int a, int ed)
{
	if(u == ed || a == 0)
		return a;
	int flow = 0, f;
	for(int& i = cur[u]; i < G[u].size(); i++)
	{
		Edge& e = edges[G[u][i]];
		if(d[u] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow), ed)) > 0)
		{
			e.flow += f;
			edges[G[u][i] ^ 1].flow -= f;
			flow += f;
			a -= f;
			if(a == 0)
				break;
		}
	}
	return flow;
}
int maxFlow(int st, int ed)
{
	int flow = 0;
	while(bfs(st, ed))
	{
		memset(cur, 0, sizeof(cur));
		flow += dfs(st, INF, ed);
	}
	return flow;
}
vector<vector<int> > ans;
vector<int> G2[MAX], vec;
bool vis2[MAX];
void dfs2(int u)
{
	vis2[u] = true;
	vec.push_back(u);
	for(int i = 0; i < G2[u].size(); i++)
	{
		int v = G2[u][i];
		if(!vis2[v])
			dfs2(v);
	}
}
bool isPrime(int n)
{
	if(n == 1)
		return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}
int num[MAX];
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int oddNum = 0, evenNum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			if(num[i] & 1)
				oddNum++;
			else
				evenNum++;
		}
		if(oddNum != evenNum)
		{
			puts("Impossible");
			continue;
		}
		int st = n;
		int ed = n + 1;
		edges.clear();
		for(int i = 0; i < n + 2; i++)
			G[i].clear();
		for(int i = 0; i < n; i++)
		{
			if(num[i] & 1)
				addEdge(st, i, 2);
			else
				addEdge(i, ed, 2);
			for(int j = i + 1; j < n; j++)
			{
				if(isPrime(num[i] + num[j]))
				{
					if(num[i] & 1)
						addEdge(i, j, 1);
					else
						addEdge(j, i, 1);
				}
			}
		}
		int flow = maxFlow(st, ed);
		if(flow == n)
		{
			for(int i = 0; i < n; i++)
				G2[i].clear();
			for(int i = 0; i < edges.size(); i++)
			{
				Edge e = edges[i];
				if(e.cap == 1 && e.flow == 1)
				{
					G2[e.from].push_back(e.to);
					G2[e.to].push_back(e.from);
				}
			}
			ans.clear();
			memset(vis2, false, sizeof(vis2));
			for(int i = 0; i < n; i++)
			{
				if(!vis2[i])
				{
					vec.clear();
					dfs2(i);
					ans.push_back(vec);
				}
			}
			printf("%d\n", ans.size());
			for(int i = 0; i < ans.size(); i++)
			{
				printf("%d", ans[i].size());
				for(int j = 0; j < ans[i].size(); j++)
					printf(" %d", ans[i][j] + 1);
				putchar('\n');
			}
		}
		else
			puts("Impossible");
	}
	return 0;
}
