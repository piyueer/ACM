#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
char str[MAX];
int solve(char str[])
{
    if(strlen(str)==5)
        return 3;
    int cnt=0;
    cnt+=str[0]=='o';
    cnt+=str[1]=='n';
    cnt+=str[2]=='e';
    return cnt>=2?1:2;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        printf("%d\n",solve(str));
    }
    return 0;
}
