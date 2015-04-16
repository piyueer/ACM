#include<bits/stdc++.h>
using namespace std;
const int MAX=100005;
vector<int> G[MAX];
int father[MAX];
int findfather(int n)
{
    return father[n]==n?n:father[n]=findfather(father[n]);
}
queue<int> q;
bool vis[MAX],vv[MAX],ok[MAX];
void bfs(int st)
{
    vis[st]=true;q.push(st);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(!vis[v])
            {
                if(ok[v])
                    vv[v]=true;
                else
                    q.push(v);
                vis[v]=true;
            }
        }
    }
}
int main()
{
    int T,n,m,k,l,x,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(ok,false,sizeof(ok));
        for(int i=0;i<k;i++)
        {
            scanf("%d",&x);
            ok[x]=true;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            father[i]=i;
        }
        int nn=n;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            int f1=findfather(u);
            int f2=findfather(v);
            if(f1!=f2)
            {
                father[f1]=f2;
                nn--;
            }
        }
        bool flag=nn==1;
        scanf("%d",&l);
        if(k!=l)
            flag=false;
        while(!q.empty())
            q.pop();
        memset(vis,false,sizeof(vis));
        memset(vv,false,sizeof(vis));
        for(int i=0;i<l;i++)
        {
            scanf("%d",&x);
            if(!flag)
                continue;
            if(i&&!vv[x])
            {
                flag=false;
                continue;
            }
            bfs(x);
        }
        puts(flag?"Yes":"No");
    }
    return 0;
}
