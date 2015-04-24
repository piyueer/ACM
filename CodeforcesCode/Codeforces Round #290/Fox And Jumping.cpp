#include<bits/stdc++.h>
using namespace std;
const int MAX = 305;
int num[MAX], cost[MAX];
map<int, int> mymap[2];
void solve(int cur, int x, int cost)
{
	if(mymap[cur][x] == 0)
		mymap[cur][x] = cost;
	else if(mymap[cur][x] > cost)
		mymap[cur][x] = cost;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &cost[i]);
		int cur = 0;
		mymap[0].clear();
		mymap[1].clear();
		for(int i = 0; i < n; i++)
		{
			cur ^= 1;
			mymap[cur].clear();
			solve(cur, num[i], cost[i]);
			for(map<int, int>::iterator iter = mymap[cur ^ 1].begin(); iter != mymap[cur ^ 1].end(); iter++)
			{
				int x = (*iter).first;
				int y = (*iter).second;
				solve(cur, x, y);
				solve(cur, __gcd(x, num[i]), y + cost[i]);
			}
		}
		printf("%d\n", mymap[cur][1] ? mymap[cur][1] : -1);
	}
	return 0;
}
