#include<bits/stdc++.h>
using namespace std;
const int MAX=100005;
char str[MAX];
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str),p=-1;
        for(int i=0;i<len;i++)
        {
            if((str[i]-'0')%2==0)
            {
                p=i;
                if(str[i]-'0'<str[len-1]-'0')
                    break;
            }
        }
        if(p==-1)
        {
            puts("-1");
            continue;
        }
        swap(str[p],str[len-1]);
        puts(str);
    }
    return 0;
}
