#include<bits/stdc++.h>
using namespace std;
const int MAX=15;
int num[MAX];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        sort(num,num+n);
        while(true)
        {
            if(num[0]==num[n-1])
                break;
            sum=sum-num[0]-num[n-1]+(num[n-1]-num[0])*2;
            num[0]=num[n-1]=num[n-1]-num[0];
            sort(num,num+n);
        }
        printf("%d\n",num[0]);
    }
    return 0;
}
