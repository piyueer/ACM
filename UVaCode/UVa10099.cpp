#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int G[MAX][MAX];
int main()
{
	int cases = 0, n, m, u, v, cost, num;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		memset(G, 0, sizeof(G));
		while(m--)
		{
			scanf("%d%d%d", &u, &v, &cost);
			G[u][v] = cost;
			G[v][u] = cost;
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++)
					G[i][j] = max(G[i][j], min(G[i][k], G[k][j]));
		scanf("%d%d%d", &u, &v, &num);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n", ++cases, (num - 1) / (G[u][v] - 1) + 1);
	}
	return 0;
}
