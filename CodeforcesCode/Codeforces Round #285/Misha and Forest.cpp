#include<bits/stdc++.h>
using namespace std;
const int MAX=(1<<16)+5;
int deg[MAX],s[MAX],ss[MAX];
struct Node
{
    int to;
    bool flag;
    Node(int _to,bool _flag)
    {
        to=_to;
        flag=_flag;
    }
};
vector<Node> G[MAX];
bool vis[MAX];
int bfs(int n)
{
    int ans=0;
    queue<int> q;
    for(int i=0;i<n;i++)
        G[i].clear();
    memset(ss,0,sizeof(ss));
    memset(vis,false,sizeof(vis));
    for(int u=0;u<n;u++)
    {
        if(G[u].size()==deg[u]||G[u].size()==deg[u]-1)
        {
            vis[u]=true;
            q.push(u);
        }
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(G[u].size()==deg[u])
            continue;
        int v=s[u]^ss[u];
        ss[u]^=v;ss[v]^=u;ans++;
        G[u].push_back(Node(v,true));
        G[v].push_back(Node(u,false));
        if(!vis[v]&&G[v].size()==deg[v]-1)
        {
            vis[v]=true;
            q.push(v);
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&deg[i],&s[i]);
        printf("%d\n",bfs(n));
        for(int u=0;u<n;u++)
            for(int i=0;i<G[u].size();i++)
                if(G[u][i].flag)
                    printf("%d %d\n",u,G[u][i].to);
    }
    return 0;
}
