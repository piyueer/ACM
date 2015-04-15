#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
char str[MAX];
int cnt[MAX][26],dp[MAX][26];//dp[i][j]表示第i组以j结尾的最小方案数
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,str);
        int len=strlen(str);memset(cnt,0,sizeof(cnt));
        for(int i=0;i<len;i++)
            cnt[i/n+1][str[i]-'a']++;
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<26;i++)
            dp[0][i]=0;
        for(int i=1;i<=len/n;i++)
        {
            int temp=0;
            for(int j=0;j<26;j++)
                if(cnt[i][j])
                    temp++;
            for(int j=0;j<26;j++)
            {
                if(!cnt[i][j])
                    continue;
                for(int k=0;k<26;k++)
                {
                    if(j==k&&cnt[i][j]>=2||cnt[i][k])
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+temp-1);
                    else
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+temp);
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<26;i++)
            ans=min(ans,dp[len/n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
