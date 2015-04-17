#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1005;
LL k,ans[MAX],temp[MAX],vis[MAX],maxdep;
LL getBeg(LL fenzi,LL fenmu)
{
    return (LL)ceil(1.0*fenmu/fenzi);
}
bool better(LL ans[],LL temp[])
{
    for(int i=maxdep-1;i>=0;i--)
    {
        if(ans[i]==-1LL)
            return true;
        else if(ans[i]>temp[i])
            return true;
        else if(ans[i]<temp[i])
            return false;
    }
    return false;
}
bool isok(LL x)
{
    for(int i=0;i<k;i++)
        if(vis[i]==x)
            return false;
    return true;
}
bool ok;
void dfs(int dep,LL beg,LL fenzi,LL fenmu)
{
    if(dep==maxdep-1)
    {
        if(fenzi==1&&isok(fenmu))
        {
            temp[dep]=fenmu;
            if(better(ans,temp))
                memcpy(ans,temp,sizeof(ans));
            ok=true;
        }
        return;
    }
    for(LL k=max(beg,getBeg(fenzi,fenmu));fenmu*(maxdep-dep)>fenzi*k;k++)
    {
        if(!isok(k))
            continue;
        LL nfenzi=fenzi*k-fenmu;
        LL nfenmu=fenmu*k;
        LL g=__gcd(nfenzi,nfenmu);
        nfenzi/=g;nfenmu/=g;temp[dep]=k;
        dfs(dep+1,k+1,nfenzi,nfenmu);
    }
}
int main()
{
    int T,fenzi,fenmu,x;
    scanf("%d",&T);
    for(int cases=0;cases<T;cases++)
    {
        scanf("%d%d%lld",&fenzi,&fenmu,&k);
        memset(vis,false,sizeof(vis));
        for(int i=0;i<k;i++)
            scanf("%lld",&vis[i]);
        ok=false;memset(ans,-1,sizeof(ans));
        for(maxdep=2;;maxdep++)
        {
            dfs(0,getBeg(fenzi,fenmu),1LL*fenzi,1LL*fenmu);
            if(ok)
                break;
        }
        printf("Case %d: %d/%d",cases+1,fenzi,fenmu);
        for(int i=0;i<maxdep;i++)
            printf("%c1/%lld",i?'+':'=',ans[i]);
        putchar('\n');
    }
    return 0;
}
