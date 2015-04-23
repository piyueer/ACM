#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAX=105;
LL w[MAX][MAX],a[MAX],b[MAX];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%I64d",&w[i][j]);
        for(int j=0;j<m;j++)
            b[j]=w[0][j];
        for(int i=0;i<n;i++)
            a[i]=i?w[i][0]-b[0]:0;
        LL k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                LL g=abs(a[i]+b[j]-w[i][j]);
                k=__gcd(k,g);
            }
        }
        if(!k)
            k=MOD;
        bool ok=true;
        for(int i=0;i<n&&ok;i++)
            for(int j=0;j<m&&ok;j++)
                if(w[i][j]>=k)
                    ok=false;
        if(ok)
        {
            puts("YES");
            printf("%I64d\n",k);
            for(int i=0;i<n;i++)
                printf("%I64d%c",(a[i]+k)%k,i+1==n?'\n':' ');
            for(int j=0;j<m;j++)
                printf("%I64d%c",(b[j]+k)%k,j+1==m?'\n':' ');
        }
        else
            puts("NO");
    }
    return 0;
}
