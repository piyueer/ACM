#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
char str[MAX][MAX];
bool G[MAX][MAX], vis[MAX];
void print(int x)
{
	vis[x] = true;
	for(int y = 0; y < 26; y++)
		if(G[y][x] && !vis[y])
			print(y);
	putchar(x + 'a');
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%s", str[i]);
		bool ok = true;
		memset(G, false, sizeof(G));
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				int k = 0;
				while(str[i][k] && str[j][k])
				{
					if(str[i][k] != str[j][k])
					{
						G[str[i][k] - 'a'][str[j][k] - 'a'] = true;
						break;
					}
					k++;
				}
				if(str[i][k] && !str[j][k])
					ok = false;
			}
		}
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				for(int k = 0; k < 26; k++)
					if(G[i][k] && G[k][j])
						G[i][j] = true;
		for(int i = 0; i < 26 && ok; i++)
			for(int j = 0; j < 26 && ok; j++)
				if(G[i][j] && G[j][i])
					ok = false;
		if(ok)
		{
			memset(vis, false, sizeof(vis));
			for(int i = 0; i < 26; i++)
				if(!vis[i])
					print(i);
			putchar('\n');
		}
		else
			puts("Impossible");
	}
	return 0;
}
