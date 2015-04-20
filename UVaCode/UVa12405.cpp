#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
char str[MAX];
int main()
{
    int T,len;
    scanf("%d",&T);
    for(int cases=0;cases<T;cases++)
    {
        scanf("%d%s",&len,str);
        int ans=0;
        for(int i=0;i<len;)
        {
            if(str[i]=='.')
            {
                ans++;
                i+=3;
            }
            else
                i++;
        }
        printf("Case %d: %d\n",cases+1,ans);
    }
    return 0;
}
