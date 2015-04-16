#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
char str[MAX];
int dir[MAX];
int main()
{
    int T,n,x;
    scanf("%d",&T);
    while(T--)
    {
        int pos=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0]=='S')
            {
                scanf("%s%d",str,&x);
                dir[i]=dir[x];
            }
            else if(str[0]=='L')
                dir[i]=-1;
            else if(str[0]=='R')
                dir[i]=1;
            pos+=dir[i];
        }
        printf("%d\n",pos);
    }
    return 0;
}
