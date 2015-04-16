#include<bits/stdc++.h>
using namespace std;
const int MAX=55;
int h[MAX];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&h[i]);
        int ans=0;
        for(int i=1;i<n-1;i++)
            if(h[i]>h[i-1]&&h[i]>h[i+1])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
