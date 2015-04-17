#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
char a[MAX][25],b[MAX][25],aa[25],bb[25];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        while(n--)
        {
            scanf("%s%s",aa,bb);
            bool ok=true;
            for(int i=0;i<cnt;i++)
            {
                if(strcmp(b[i],aa)==0)
                {
                    strcpy(b[i],bb);
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                strcpy(a[cnt],aa);
                strcpy(b[cnt],bb);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
            printf("%s %s\n",a[i],b[i]);
    }
    return 0;
}
