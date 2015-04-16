#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,m,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);n--;
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum1+=x;
        }
        int sum2=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            sum2+=x;
        }
        int l=0;
        while(true)
        {
            double a1=1.0*(sum1+l)/(n+1);
            double a2=1.0*sum1/n;
            double b1=1.0*sum2/m;
            double b2=1.0*(sum2+l)/(m+1);
            if(a1<a2&&b1<b2)
                break;
            l++;
        }
        int r=100;
        while(true)
        {
            double a1=1.0*(sum1+r)/(n+1);
            double a2=1.0*sum1/n;
            double b1=1.0*sum2/m;
            double b2=1.0*(sum2+r)/(m+1);
            if(a1<a2&&b1<b2)
                break;
            r--;
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}
