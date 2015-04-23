#include<bits/stdc++.h>
using namespace std;
const int MAX=305;
int num[MAX];
queue<int> q;
int main()
{
    int n,t,r;
    while(scanf("%d%d%d",&n,&t,&r)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        if(t<r)
        {
            puts("-1");
            continue;
        }
        int ans=0;
        while(!q.empty())
            q.pop();
        for(int i=num[0]-r;i<=num[0]-1;i++)
        {
            q.push(i+t);
            ans++;
        }
        for(int i=1;i<n;i++)
        {
            while(!q.empty()&&q.front()<num[i])
                q.pop();
            int sz=q.size();
            if(sz>=r)
                continue;
            sz=r-sz;
            for(int j=num[i]-sz;j<=num[i]-1;j++)
            {
                q.push(j+t);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
