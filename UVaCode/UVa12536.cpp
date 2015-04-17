#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
const int MAXM=15005;
int num[MAXN],dp[MAXM];
int main()
{
    int T,n,t;
    scanf("%d",&T);
    for(int cases=0;cases<T;cases++)
    {
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        memset(dp,-1,sizeof(dp));dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=t-1;j>=num[i];j--)
                if(dp[j-num[i]]>=0)
                    dp[j]=max(dp[j],dp[j-num[i]]+1);
        int ans=t-1;
        for(int i=t-1;i>=0;i--)
            if(dp[ans]<dp[i])
                ans=i;
        printf("Case %d: %d %d\n",cases+1,dp[ans]+1,ans+678);
    }
    return 0;
}
