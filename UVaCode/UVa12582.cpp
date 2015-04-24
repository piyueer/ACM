#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int cnt[MAX];
stack<int> mystack;
char str[MAX];
int main()
{
	int T;
	scanf("%d", &T);
	for(int cases = 0; cases < T; cases++)
	{
		scanf("%s", str);
		memset(cnt, 0, sizeof(cnt));
		while(!mystack.empty())
			mystack.pop();
		mystack.push(str[0] - 'A');
		for(int i = 1; str[i]; i++)
		{
			if(mystack.top() != str[i] - 'A')
			{
				cnt[mystack.top()]++;
				cnt[str[i] - 'A']++;
				mystack.push(str[i] - 'A');
			}
			else
				mystack.pop();
		}
		printf("Case %d\n", cases + 1);
		for(int i = 0; i < 26; i++)
			if(cnt[i])
				printf("%c = %d\n", i + 'A', cnt[i]);
	}
	return 0;
}
