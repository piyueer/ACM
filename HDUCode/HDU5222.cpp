#include<cstdio>
#include<vector>
#include<queue>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int MAX = 1000005;
int father[MAX], in[MAX];
int findfather(int n)
{
	if(father[n] == n)
		return n;
	return father[n] = findfather(father[n]);
}
vector<int> G[MAX], G2[MAX];
bool topoSort(int n)
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(in[i] == 0)
			q.push(i);
	int cnt = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		cnt++;
		for(int i = 0; i < G2[u].size(); i++)
		{
			int v = G2[u][i];
			if(--in[v] == 0)
				q.push(v);
		}
	}
	return cnt == n;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m1, m2;
		bool ok = false;
		scanf("%d %d %d", &n, &m1, &m2);
		for(int i = 1; i <= n; i++)
		{
			father[i] = i;
			G[i].clear();
			G2[i].clear();
		}
		fill(in + 1, in + n + 1, 0);
		for(int i = 0; i < m1; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			int f1 = findfather(u);
			int f2 = findfather(v);
			if(f1 == f2)
				ok = true;
			father[f1] = f2;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 0; i < m2; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			int f1 = findfather(u);
			int f2 = findfather(v);
			if(f1 == f2)
				ok = true;
			G2[f1].push_back(f2);
			in[f2]++;
		}
		if(ok)
		{
			puts("YES");
			continue;
		}
		puts(topoSort(n) ? "NO" : "YES");
	}
	return 0;
}
