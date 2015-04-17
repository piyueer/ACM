#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
char str[MAX];
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int cases=0;cases<T;cases++)
    {
        gets(str);
        int a=0,b=0;
        for(int i=0;str[i];i++)
        {
            if(a==0)
            {
                while(str[i]>='0'&&str[i]<='9')
                    a=a*10+str[i++]-'0';
            }
            else if(b==0)
            {
                while(str[i]>='0'&&str[i]<='9')
                    b=b*10+str[i++]-'0';
            }
        }
        int ans=a*50+b*5;
        if(ans%100==0)
            printf("Case %d: %d\n",cases+1,ans/100);
        else if(ans%10==0)
            printf("Case %d: %d.%d\n",cases+1,ans/100,ans%100/10);
        else
            printf("Case %d: %d.%d%d\n",cases+1,ans/100,ans%100/10,ans%10);
    }
    return 0;
}
