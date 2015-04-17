#include<bits/stdc++.h>
using namespace std;
const int MAX=15;
vector<int> G[MAX];
struct Node
{
    int u;
    int status;
    int step;
    int pre;
    int a,b;
    Node(){}
    Node(int _u,int _status,int _step,int _pre,int _a,int _b)
    {
        u=_u;
        status=_status;
        step=_step;
        pre=_pre;
        a=_a;
        b=_b;
    }
}q[MAX*(1<<MAX)];
bool vis[MAX][1<<MAX];
void print(int x)
{
    if(q[x].pre==-1)
        return;
    print(q[x].pre);
    printf("%d %d\n",q[x].a+1,q[x].b+1);
}
bool bfs(int n,int st,int ed,int status)
{
    int head=0,tail=0;
    memset(vis,false,sizeof(vis));
    vis[st][status]=true;q[tail++]=Node(st,status,0,-1,-1,-1);
    while(head<tail)
    {
        Node now=q[head++];
        if(now.u==ed)
        {
            printf("%d\n",now.step);
            print(head-1);
            return true;
        }
        // move robot
        for(int i=0;i<G[now.u].size();i++)
        {
            int v=G[now.u][i];
            if(now.status&(1<<v))
                continue;
            int nu=v;
            int nstatus=now.status;
            int nstep=now.step+1;
            int npre=head-1;
            int na=now.u;
            int nb=v;
            if(!vis[nu][nstatus])
            {
                vis[nu][nstatus]=true;
                q[tail++]=Node(nu,nstatus,nstep,npre,na,nb);
            }
        }
        // move obstacles
        for(int u=0;u<n;u++)
        {
            if(!(now.status&(1<<u)))
                continue;
            for(int i=0;i<G[u].size();i++)
            {
                int v=G[u][i];
                if(v==now.u)
                    continue;
                if(now.status&(1<<v))
                    continue;
                int nu=now.u;
                int nstatus=now.status;nstatus^=(1<<u);nstatus|=(1<<v);
                int nstep=now.step+1;
                int npre=head-1;
                int na=u;
                int nb=v;
                if(!vis[nu][nstatus])
                {
                    vis[nu][nstatus]=true;
                    q[tail++]=Node(nu,nstatus,nstep,npre,na,nb);
                }
            }
        }
    }
    return false;
}
int main()
{
    int T,n,m,st,ed,x,u,v;
    scanf("%d",&T);
    for(int cases=0;cases<T;cases++)
    {
        scanf("%d%d%d%d",&n,&m,&st,&ed);
        int status=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            status|=1<<(x-1);
        }
        for(int i=0;i<n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            G[u-1].push_back(v-1);
            G[v-1].push_back(u-1);
        }
        printf("Case %d: ",cases+1);
        if(!bfs(n,st-1,ed-1,status))
            puts("-1");
        putchar('\n');
    }
    return 0;
}
