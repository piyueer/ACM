#include<cstdio>
#include<cstring>
const int MAX = 100005;
int cnt[MAX];
int main()
{
	int T, n, x;
	scanf("%d", &T);
	for(int cases = 0; cases < T; cases++)
	{
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		while(n--)
		{
			scanf("%d", &x);
			for(int i = 1; i * i <= x; i++)
			{
				if(x % i == 0)
				{
					cnt[i]++;
					if(i != x / i)
						cnt[x / i]++;
				}
			}
		}
		for(int ans = MAX - 1; ans >= 1; ans--)
		{
			if(cnt[ans] >= 2)
			{
				printf("Case #%d: %d\n", cases + 1, ans);
				break;
			}
		}
	}
	return 0;
}
