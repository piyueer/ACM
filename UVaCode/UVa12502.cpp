#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,x,y,z;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&x,&y,&z);
        if((2*x-y)%(x+y)==0)
            printf("%d\n",(2*x-y)/(x+y)*z);
        else if(z%(x+y)==0)
            printf("%d\n",z/(x+y)*(2*x-y));
        else
            printf("%d\n",(int)((2.0*x-y)/(x+y)*z+0.5));
    }
    return 0;
}
