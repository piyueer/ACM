#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int LEFT = 0;
const int RIGHT = 1;
LL dfs(LL n, int level, int type)
{
	if(level == 0)
		return 0LL;
	LL mid = 1LL << (level - 1LL);
	if(type == LEFT)
	{
		if(n <= mid)
			return dfs(n, level - 1, RIGHT) + 1LL;
		else
			return dfs(n - mid, level - 1, LEFT) + (mid << 1);
	}
	else
	{
		if(n <= mid)
			return dfs(n, level - 1, RIGHT) + (mid << 1);
		else
			return dfs(n - mid, level - 1, LEFT) + 1LL;
	}
}
int main()
{
	LL h, n;
	while(scanf("%I64d%I64d", &h, &n) != EOF)
		printf("%I64d\n", dfs(n, h, LEFT));
	return 0;
}
