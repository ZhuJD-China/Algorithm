#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char n[105];
    int m;
    scanf("%s%d",n,&m);
    int len = strlen(n);
    int ans = 0;
    for (int i = 0; i < len; i++)
        ans = (int)((((long long)ans * 10) % m + (n[i] - '0') % m) % m);
    printf("%d\n",ans);

    return 0;
}
