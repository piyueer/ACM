#include<bits/stdc++.h>
using namespace std;
const int MAX=100005;
int num[MAX];
int main()
{
    int cases=0,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int t=0,g=num[1];
        for(int i=2;i<=n;i++)
        {
            g=__gcd(g,num[i]);
            if(g==1)
            {
                t=i;
                break;
            }
        }
        if(t)
        {
            printf("Case %d: %d\n",++cases,t-1+n-1);
            for(int i=1;i<t;i++)
                printf("%d %d\n",i,i+1);
            for(int i=1;i<=n;i++)
            {
                if(i==t)
                    continue;
                printf("%d %d\n",min(i,t),max(i,t));
            }
        }
        else
            printf("Case %d: -1\n",++cases);
        putchar('\n');
    }
    return 0;
}
