#include<bits/stdc++.h>
using namespace std;
const int MAX = 500005;
char str[MAX];
int vowel(char ch)
{
	return ch == 'I' || ch == 'E' || ch == 'A' || ch == 'O' || ch == 'U' || ch == 'Y';
}
int sum[MAX] = {0};
int main()
{
	while(scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		for(int i = 1; i <= len; i++)
			sum[i] = sum[i - 1] + vowel(str[i - 1]);
		double ans = 0.0, temp = 0.0;
		for(int i = 1; i <= len; i++)
		{
			temp += 1.0 * sum[len + 1 - i] - sum[i - 1];
			ans += temp / i;
		}
		printf("%.7f\n", ans);
	}
	return 0;
}
