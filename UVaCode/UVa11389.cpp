#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
int a[MAX],b[MAX];
int main()
{
    int n,d,r;
    while(scanf("%d%d%d",&n,&d,&r)!=EOF)
    {
        if(n==0&&d==0&&r==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);sort(b,b+n);
        int ans=0;
        for(int i=0;i<n;i++)
            if(a[i]+b[n-1-i]>d)
                ans+=(a[i]+b[n-1-i]-d)*r;
        printf("%d\n",ans);
    }
    return 0;
}
