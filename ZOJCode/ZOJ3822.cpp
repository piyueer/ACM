#include<bits/stdc++.h>
using namespace std;
const int MAX=55;
double dp[MAX*MAX][MAX][MAX];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));dp[0][0][0]=1.0;
        for(int i=0;i<n*m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=m;k++)
                {
                    if(j==n&&k==m)
                        continue;
                    double p1=1.0*(n-j)*(m-k)/(n*m-i);
                    double p2=1.0*(n-j)*k/(n*m-i);
                    double p3=1.0*j*(m-k)/(n*m-i);
                    double p4=1.0*(j*k-i)/(n*m-i);
                    dp[i+1][j+1][k+1]+=dp[i][j][k]*p1;
                    dp[i+1][j+1][k]+=dp[i][j][k]*p2;
                    dp[i+1][j][k+1]+=dp[i][j][k]*p3;
                    dp[i+1][j][k]+=dp[i][j][k]*p4;
                }
            }
        }
        double ans=0.0;
        for(int i=0;i<=n*m;i++)
            ans+=dp[i][n][m]*i;
        printf("%.12f\n",ans);
    }
    return 0;
}
