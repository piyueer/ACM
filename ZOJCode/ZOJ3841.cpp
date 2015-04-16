#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAX=55;
int C[MAX][MAX],cnt[MAX],dig[MAX];
LL cal(int n)
{
    LL ans=1;
    for(int i=1;i<=13;i++)
    {
        if(!cnt[i])
            continue;
        ans=(ans*C[n][cnt[i]])%MOD;
        n-=cnt[i];
    }
    return ans;
}
LL dfs(int n,int sum,int cur)
{
    LL ans=0;
    if(cur==n)
        return 0LL;
    if(cur&&cur==sum)
        return 1LL;
    for(int i=1;i<=dig[cur];i++)
    {
        if(!cnt[i])
            continue;
        cnt[i]--;
        if(i==dig[cur])
            ans=(ans+dfs(n,sum,cur+1))%MOD;
        else
            ans=(ans+cal(sum-1-cur))%MOD;
        cnt[i]++;
    }
    return ans;
}
int main()
{
    C[0][0]=1;
    for(int i=1;i<MAX;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j]%MOD;
    }
    char str[MAX];
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str),n=0,sum=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<len;i++)
        {
            if(str[i]=='A')
                dig[n++]=1;
            else if(str[i]>='2'&&str[i]<='9')
                dig[n++]=str[i]-'0';
            else if(str[i]=='1'&&str[i+1]=='0')
            {
                dig[n++]=10;
                i++;
            }
            else if(str[i]=='J')
                dig[n++]=11;
            else if(str[i]=='Q')
                dig[n++]=12;
            else if(str[i]=='K')
                dig[n++]=13;
            cnt[dig[n-1]]++;
        }
        for(int i=1;i<=13;i++)
        {
            cnt[i]=4-cnt[i];
            sum+=cnt[i];
        }
        printf("%lld\n",dfs(n,sum,0));
    }
    return 0;
}
