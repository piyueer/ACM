#include<bits/stdc++.h>
using namespace std;
const int MAX=55;
string str[MAX];
bool cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            cin>>str[i];
        sort(str,str+n,cmp);
        for(int i=0;i<n;i++)
            cout<<str[i];
        cout<<endl;
    }
    return 0;
}
