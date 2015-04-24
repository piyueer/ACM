#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX = 100005;
int d[MAX], c[MAX], from[MAX], to[MAX], type[MAX], choice[MAX], path[MAX];
struct Edge
{
	int to, type, id;
	Edge() {}
	Edge(int to, int type, int id): to(to), type(type), id(id) {}
};
vector<Edge> G[MAX];
void dijkstra(int n, int st, int ed)
{
	priority_queue<P, vector<P>, greater<P> > q;
	memset(d, 0x3f, sizeof(d));
	memset(c, 0, sizeof(c));
	memset(choice, false, sizeof(choice));
	d[st] = 0;
	q.push(P(d[st], st));
	while(!q.empty())
	{
		P p = q.top();
		q.pop();
		int u = p.second;
		if(d[u] < p.first)
			continue;
		for(int i = 0; i < G[u].size(); i++)
		{
			Edge e = G[u][i];
			if(d[e.to] > d[u] + 1)
			{
				d[e.to] = d[u] + 1;
				c[e.to] = c[u] + e.type;
				path[e.to] = e.id;
				q.push(P(d[e.to], e.to));
			}
			else if(d[e.to] == d[u] + 1 && c[e.to] < c[u] + e.type)
			{
				c[e.to] = c[u] + e.type;
				path[e.to] = e.id;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}
int main()
{
	int n, m, u, v;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; i++)
			G[i].clear();
		int sum = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &from[i], &to[i], &type[i]);
			G[from[i]].push_back(Edge(to[i], type[i] , i));
			G[to[i]].push_back(Edge(from[i], type[i] , i));
			sum += type[i];
		}
		dijkstra(n, 1, n);
		for(int u = n; u != 1; u = (u == from[path[u]] ? to[path[u]] : from[path[u]]))
			choice[path[u]] = true;
		printf("%d\n", d[n] + sum - 2 * c[n]);
		for(int i = 0 ; i < m; i++)
		{
			if(choice[i] && type[i] == 0)
				printf("%d %d 1\n", from[i], to[i]);
			if(choice[i] == 0 && type[i])
				printf("%d %d 0\n", from[i], to[i]);
		}
	}
	return 0;
}
