#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
int num[MAX][MAX];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    num[i][j]=1;
                else
                    num[i][j]=num[i-1][j]+num[i][j-1];
            }
        }
        printf("%d\n",num[n-1][n-1]);
    }
    return 0;
}
