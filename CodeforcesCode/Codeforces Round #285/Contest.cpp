#include<bits/stdc++.h>
using namespace std;
int getPoint(int p,int t)
{
    return max(3*p/10,p-p/250*t);
}
int main()
{
    int p1,p2,t1,t2;
    while(scanf("%d%d%d%d",&p1,&p2,&t1,&t2)!=EOF)
    {
        int point1=getPoint(p1,t1);
        int point2=getPoint(p2,t2);
        if(point1==point2)
            puts("Tie");
        else if(point1<point2)
            puts("Vasya");
        else if(point1>point2)
            puts("Misha");
    }
    return 0;
}
