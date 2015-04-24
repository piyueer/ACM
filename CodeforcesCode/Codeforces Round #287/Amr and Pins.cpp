#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r, x1, y1, x2, y2;
	while(scanf("%d%d%d%d%d", &r, &x1, &y1, &x2, &y2) != EOF)
	{
		r *= 2;
		double dis = sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
		if((int)dis == dis && (int)dis % r == 0)
			printf("%d\n", (int)dis / r);
		else
			printf("%d\n", (int)(dis / r) + 1);
	}
	return 0;
}
