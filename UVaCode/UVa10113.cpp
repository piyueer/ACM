#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
struct Edge
{
	int to;
	int fenzi;
	int fenmu;
	Edge() {}
	Edge(int to, int fenzi, int fenmu): to(to), fenzi(fenzi), fenmu(fenmu) {}
}
vector<Edge> G[MAX];
map<string, int> mymap;
map<int, string> mymap2;
int getId(char str[], int &cnt)
{
	if(mymap[str] == 0)
	{
		mymap[str] = ++cnt;
		mymap2[cnt] = str;
	}
	return mymap[str];
}
bool vis[MAX], ok;
void dfs(int u, int st, int ed, int fenzi, int fenmu)
{
	vis[u] = true;
	if(u == ed)
	{
		ok = true;
		printf("%d %s = %d %s\n", fenzi, mymap2[st].c_str(), fenmu, mymap2[ed].c_str());
		return;
	}
	for(int i = 0; i < G[u].size(); i++)
	{
		Edge e = G[u][i];
		if(vis[e.to])
			continue;
		int nfenzi = fenzi * e.fenzi;
		int nfenmu = fenmu * e.fenmu;
		int g = __gcd(nfenzi, nfenmu);
		dfs(e.to, st, ed, nfenzi / g, nfenmu / g);
	}
}
void solve(int st, int ed)
{
	ok = false;
	memset(vis, false, sizeof(vis));
	dfs(st, st, ed, 1, 1);
	if(!ok)
		printf("? %s = ? %s\n", mymap2[st].c_str(), mymap2[ed].c_str());
}
char str[MAX], x[MAX], y[MAX];
int main()
{
	int a, b, cnt = 0;
	while(scanf("%s", str) != EOF)
	{
		if(strcmp(str, ".") == 0)
			break;
		if(strcmp(str, "!") == 0)
		{
			gets(str);
			sscanf(str, "%d %s = %d %s", &a, x, &b, y);
			int u = getId(x, cnt), v = getId(y, cnt);
			G[u].push_back(Edge(v, a, b));
			G[v].push_back(Edge(u, b, a));
		}
		else if(strcmp(str, "?") == 0)
		{
			gets(str);
			sscanf(str, "%s = %s", x, y);
			solve(getId(x, cnt), getId(y, cnt));
		}
	}
	return 0;
}
