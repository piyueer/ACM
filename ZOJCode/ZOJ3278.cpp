#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=100000;
LL a[MAX],b[MAX];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    LL n,m,k;
    while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%lld",&b[i]);
        sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
        LL ans,l=a[n]*b[m],r=a[1]*b[1];
        while(l<=r)
        {
            LL mid=(l+r)/2,sum=0;
            for(int i=1;i<=n;i++)
            {
                LL ll=1,rr=m,temp=0;
                while(ll<=rr)
                {
                    LL mmid=(ll+rr)/2;
                    if(a[i]*b[mmid]>=mid)
                    {
                        temp=mmid;
                        ll=mmid+1;
                    }
                    else
                        rr=mmid-1;
                }
                sum+=temp;
            }
            if(sum>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
