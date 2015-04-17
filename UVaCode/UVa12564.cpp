#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
bool a1[MAX][MAX],w1[MAX][MAX],a2[MAX][MAX],w2[MAX][MAX];
int main()
{
    int T,n,m,x1,y1,x2,y2;
    scanf("%d",&T);
    for(int cases=0;cases<T;cases++)
    {
        scanf("%d%d",&n,&m);
        memset(a1,false,sizeof(a1));
        memset(w1,false,sizeof(w1));
        while(n--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1;i<x2;i++)
                for(int j=y1;j<y2;j++)
                    a1[i][j]=true;
        }
        while(m--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1;i<x2;i++)
                for(int j=y1;j<y2;j++)
                    w1[i][j]=true;
        }
        scanf("%d%d",&n,&m);
        memset(a2,false,sizeof(a2));
        memset(w2,false,sizeof(w2));
        while(n--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1;i<x2;i++)
                for(int j=y1;j<y2;j++)
                    a2[i][j]=true;
        }
        while(m--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i=x1;i<x2;i++)
                for(int j=y1;j<y2;j++)
                    w2[i][j]=true;
        }
        bool ok1=false,ok2=false;
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                if(a1[i][j]&&w2[i][j])
                    ok1=true;
                if(a2[i][j]&&w1[i][j])
                    ok2=true;
            }
        }
        printf("Case %d: ",cases+1);
        if(ok1&&ok2)
            puts("Both");
        else if(ok1)
            puts("Second");
        else if(ok2)
            puts("First");
        else
            puts("Neither");
    }
    return 0;
}
