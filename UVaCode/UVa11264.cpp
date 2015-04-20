#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
int c[MAX];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        c[n]=0x7fffffff;
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+c[i]<c[i+1])
            {
                sum+=c[i];
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
