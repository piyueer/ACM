#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
char str[MAX];
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        if(strcmp(str,"0")==0)
            break;
        int ans=0;
        for(int i=0;str[i];i++)
            ans=(ans+str[i]-'0')%9;
        printf("%d\n",ans?ans:9);
    }
    return 0;
}
