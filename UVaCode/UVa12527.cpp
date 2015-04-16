#include<bits/stdc++.h>
using namespace std;
const int MAX=5005;
int ans[MAX]={0};
int ok(int n)
{
    bool dig[10];
    memset(dig,false,sizeof(dig));
    while(n)
    {
        int x=n%10;
        if(dig[x])
            return 0;
        dig[x]=true;
        n/=10;
    }
    return 1;
}
int main()
{
    for(int i=1;i<MAX;i++)
        ans[i]=ans[i-1]+ok(i);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
        printf("%d\n",ans[m]-ans[n-1]);
    return 0;
}
