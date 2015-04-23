#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
int num[MAX];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int minnum=0x7fffffff;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            minnum=min(minnum,num[i]);
        }
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(num[i]-minnum>k)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            puts("YES");
            for(int i=0;i<n;i++)
            {
                putchar('1');
                for(int j=1;j<minnum;j++)
                    printf(" 1");
                for(int j=0;j<num[i]-minnum;j++)
                    printf(" %d",j+1);
                putchar('\n');
            }
        }
        else
            puts("NO");
    }
    return 0;
}
