#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1005;
struct Master
{
    int attack;
    int gold;
}master[MAX];
int main()
{
    int n,f,w,g;
    while(scanf("%d%d%d%d",&n,&f,&w,&g)!=EOF)
    {
        master[0].attack=0;
        master[0].gold=g;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&master[i].attack,&master[i].gold);
        bool ok=true;
        for(int defend=0,i=0;i<=n;i++)
        {
            if(defend>=master[i].attack)
                continue;
            int need=master[i].attack-defend;
            for(int j=i-1;j>=0;j--)
            {
                if(master[j].gold>=need)
                {
                    master[j].gold-=need;
                    need=0;
                    break;
                }
                else
                {
                    need-=master[j].gold;
                    master[j].gold=0;
                }
            }
            if(need)
            {
                ok=false;
                break;
            }
            defend=master[i].attack;
        }
        if(!ok)
        {
            puts("It's useless to collect wood.");
            continue;
        }
        LL ans=0,wa=w,wb=0,money=0;
        for(int i=0;i<=n;i++)
        {
            ans+=wa*wb;
            money+=master[i].gold;
            LL temp=money/f;
            if(wa+temp<=wb)
                wa+=temp;
            else if(wb+temp<=wa)
                wb+=temp;
            else
            {
                LL sum=wa+wb+temp;
                if(sum&1)
                {
                    wa=sum/2+1;
                    wb=sum/2;
                }
                else
                    wa=wb=sum/2;
            }
            money=money%f;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
