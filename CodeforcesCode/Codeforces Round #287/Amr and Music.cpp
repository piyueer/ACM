#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
struct Node
{
	int num;
	int id;
} node[MAX];
bool cmp(Node a, Node b)
{
	return a.num < b.num;
}
vector<int> ans;
int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &node[i].num);
			node[i].id = i + 1;
		}
		sort(node, node + n, cmp);
		ans.clear();
		for(int i = 0; i < n; i++)
		{
			if(k >= node[i].num)
			{
				k -= node[i].num;
				ans.push_back(node[i].id);
			}
			else
				break;
		}
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
	}
	return 0;
}
