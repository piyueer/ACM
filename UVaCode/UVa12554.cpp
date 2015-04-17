#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
const char str[][MAX]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
char name[MAX][MAX];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",name[i]);
    for(int i=0;i<((n-1)/16+1)*16;i++)
        printf("%s: %s\n",name[i%n],str[i%16]);
    return 0;
}
