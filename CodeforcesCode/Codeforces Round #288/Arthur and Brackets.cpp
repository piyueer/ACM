#include<bits/stdc++.h>
using namespace std;
const int MAX=605;
int l[MAX],r[MAX],len[MAX];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&l[i],&r[i]);
        stack<int> mystack;
        string str="";
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            len[i]=str.size();
            mystack.push(i);
            str+="(";
            while(!mystack.empty()&&len[mystack.top()]+l[mystack.top()]<=str.size())
            {
                if(len[mystack.top()]+r[mystack.top()]<str.size())
                {
                    ok=false;
                    break;
                }
                mystack.pop();
                str+=")";
            }
            if(!ok)
                break;
        }
        if(ok&&mystack.empty())
            printf("%s\n",str.c_str());
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
