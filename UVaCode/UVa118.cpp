#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX = 105;
char str[MAX], ch[MAX];
char getCh(int dir)
{
	if(dir == 0)
		return 'N';
	else if(dir == 1)
		return 'E';
	else if(dir == 2)
		return 'S';
	else if(dir == 3)
		return 'W';
}
int getDir(char ch)
{
	if(ch == 'N')
		return 0;
	else if(ch == 'E')
		return 1;
	else if(ch == 'S')
		return 2;
	else if(ch == 'W')
		return 3;
}
bool vis[MAX][MAX];
void solve(char str[], int n, int m, int x, int y, int dir)
{
	for(int i = 0; str[i]; i++)
	{
		if(str[i] == 'F')
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx < 0 || nx > n || ny < 0 || ny > m)
			{
				if(vis[x][y])
					continue;
				vis[x][y] = true;
				printf("%d %d %c LOST\n", x, y, getCh(dir));
				return;
			}
			x = nx;
			y = ny;
		}
		else if(str[i] == 'L')
			dir = (dir + 3) % 4;
		else if(str[i] == 'R')
			dir = (dir + 1) % 4;
	}
	printf("%d %d %c\n", x, y, getCh(dir));
}
int main()
{
	int n, m, x, y;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(vis, false, sizeof(vis));
		while(scanf("%d%d%s%s", &x, &y, ch, str) != EOF)
			solve(str, n, m, x, y, getDir(ch[0]));
	}
	return 0;
}
