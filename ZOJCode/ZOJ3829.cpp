#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
char str[MAX];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",&str);
        int a=0,b=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='*')
                b++;
            else
                a++;
        }
        int ans=max(b+1-a,0),aa=ans,bb=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='*')
                bb++;
            else
                aa++;
            if(aa<bb+1)
            {
                aa++;
                bb--;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
