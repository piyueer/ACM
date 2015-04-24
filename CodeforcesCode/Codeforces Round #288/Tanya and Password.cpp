#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAX = 62;
int in[MAX*MAX], out[MAX*MAX], G[MAX*MAX][MAX*MAX];
int getHash(char ch)
{
	if(ch >= 'a' && ch <= 'z')
		return ch - 'a';
	else if(ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 26;
	return ch - '0' + 52;
}
char getHash(int x)
{
	if(x >= 0 && x < 26)
		return x + 'a';
	else if(x >= 26 && x < 52)
		return x - 26 + 'A';
	return x - 52 + '0';
}
int ans[MAXN], len;
void dfs(int u)
{
	for(int v = 0; v < MAX * MAX; v++)
	{
		if(G[u][v])
		{
			G[u][v]--;
			dfs(v);
			ans[len++] = v;
		}
	}
}
char str[MAX];
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		memset(G, 0, sizeof(G));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for(int i = 0; i < n; i++)
		{
			scanf("%s", str);
			int a = getHash(str[0]);
			int b = getHash(str[1]);
			int c = getHash(str[2]);
			int u = a * MAX + b;
			int v = b * MAX + c;
			G[u][v]++;
			in[v]++;
			out[u]++;
		}
		int st = -1, ed = -1, ok = true;
		for(int i = 0; i < MAX * MAX; i++)
		{
			if(out[i] - in[i] == 1)
			{
				if(st >= 0)
				{
					ok = false;
					break;
				}
				st = i;
			}
			else if(in[i] - out[i] == 1)
			{
				if(ed >= 0)
				{
					ok = false;
					break;
				}
				ed = i;
			}
			else if(in[i] != out[i])
			{
				ok = false;
				break;
			}
		}
		for(int i = 0; i < MAX * MAX && st == -1; i++)
			if(in[i])
				st = i;
		for(int i = MAX * MAX - 1; i >= 0 && ed == -1; i--)
			if(in[i])
				ed = i;
		if(ok)
		{
			len = 0;
			dfs(st);
			ans[len++] = st;
			if(len == n + 1)
			{
				puts("YES");
				printf("%c", getHash(ans[len - 1] / MAX));
				for(int i = len - 1; i >= 0; i--)
					putchar(getHash(ans[i] % MAX));
				putchar('\n');
			}
			else
				puts("NO");
		}
		else
			puts("NO");
	}
	return 0;
}
