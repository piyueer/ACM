#include<bits/stdc++.h>
using namespace std;
const int MAXLEN=1000005;
const int MAX=30;
int father[MAX];
int getId(char ch)
{
    if(ch=='_')
        return 0;
    return ch-'A'+1;
}
char getCh(int id)
{
    if(id==0)
        return '_';
    return id-1+'A' ;
}
char str[MAXLEN],a[MAX],b[MAX];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        for(int i=0;i<MAX;i++)
            father[i]=i;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s%s",a,b);
            int id1=getId(a[0]);
            int id2=getId(b[0]);
            for(int i=0;i<MAX;i++)
                if(father[i]==id2)
                    father[i]=id1;
        }
        for(int i=0;str[i];i++)
            putchar(getCh(father[getId(str[i])]));
        putchar('\n');
    }
    return 0;
}
