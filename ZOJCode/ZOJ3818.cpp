#include<bits/stdc++.h>
using namespace std;
const int MAX=55;
char str[MAX];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        string s="";
        for(int i=0;str[i];i++)
            if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
                s+=str[i];
        bool ok=false;
        for(int alen=1;alen<s.size()&&!ok;alen++)
        {
            for(int blen=1;alen+blen<s.size()&&!ok;blen++)
            {
                string a=s.substr(0,alen);
                string b=s.substr(alen,blen);
                if(a!=b&&a+b+a+b+a==s)
                    ok=true;
                if((alen+blen)*3<s.size())
                {
                    string c=s.substr((alen+blen)*2,s.size()-(alen+blen)*3);
                    if(a!=b&&a!=c&&b!=c&&a+b+a+b+c+a+b==s)
                        ok=true;
                }
            }
        }
        puts(ok?"Yes":"No");
    }
    return 0;
}
