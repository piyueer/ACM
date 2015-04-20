#include<bits/stdc++.h>
using namespace std;
const int MAX=1000005;
vector<int> vec[MAX];
int main()
{
    int n,m,k,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<MAX;i++)
            vec[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v);
            vec[v].push_back(i);
        }
        while(m--)
        {
            scanf("%d%d",&k,&v);
            if(vec[v].size()<k)
                puts("0");
            else
                printf("%d\n",vec[v][k-1]);
        }
    }
    return 0;
}
