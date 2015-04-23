#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const int MAX=55;
char G[MAX][MAX];
bool vis[MAX][MAX],ok;
void dfs(int n,int m,int x,int y,int ex,int ey,int dep)
{
    if(ok)
        return;
    if(x==ex&&y==ey&&dep>=4)
    {
        ok=true;
        return;
    }
    for(int k=0;k<4;k++)
    {
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&G[x][y]==G[nx][ny])
        {
            vis[nx][ny]=true;
            dfs(n,m,nx,ny,ex,ey,dep+1);
            vis[nx][ny]=false;
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%s",G[i]);
        ok=false;memset(vis,false,sizeof(vis));
        for(int i=0;i<n&&!ok;i++)
            for(int j=0;j<m&&!ok;j++)
                dfs(n,m,i,j,i,j,0);
        puts(ok?"Yes":"No");
    }
    return 0;
}
