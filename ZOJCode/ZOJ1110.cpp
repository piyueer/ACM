#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,p,y,j;
    while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF)
    {
        bool ok=false;
        for(int turtle=0;!ok;turtle++)
        {
            for(int dog=turtle+y;dog<=turtle+y+1&&!ok;dog++)
            {
                for(int cat=turtle+p;cat<=turtle+p+1&&!ok;cat++)
                {
                    if((dog==cat+s||dog==cat+s+1)&&dog+cat+turtle==12+j)
                    {
                        ok=true;
                        printf("%d %d %d\n",dog,cat,turtle);
                    }
                }
            }
        }
    }
    return 0;
}
