#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
char str[MAX];
int main()
{
    double x1,y1,x2,y2;
    while(gets(str)!=NULL)
    {
        double ans=0.0;
        while(gets(str)!=NULL)
        {
            if(strcmp(str,"java")==0)
                break;
            sscanf(str,"%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            ans+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        }
        ans=60.0*2.0*ans/20.0/1000.0;
        int h=(int)(ans+0.5)/60;
        int m=(int)(ans+0.5)%60;
        printf("%d:%.2d\n",h,m);
    }
    return 0;
}
