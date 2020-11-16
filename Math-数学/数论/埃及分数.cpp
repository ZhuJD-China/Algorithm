//埃及分数
/*
将一个分数a/b, 分解成若干个单位分数1/x的和。要求找到加数个数最少且最小的单位分数最大的方案
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1000;
LL ans[maxn],v[maxn];
int maxd,kcase;
int gcd(LL a,LL b) //最大公约数，用于约分
{
    LL temp;
    while(b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
LL get_first(LL a, LL b) //满足1/c<=a/b的最小c
{
    return b/a + 1;
}
bool better(int d) //更新最优值：如果当前解v比目前最优解ans更优，更新ans
{
    for(int i=d; i>=0; i--)
        if(v[i] != ans[i])
            return ans[i] == -1 || v[i] < ans[i];
    return false;
}
//当前深度为d，分母不能小于from，分数之和恰好为aa/bb
bool dfs(int d,int from,LL aa,LL bb)
{
    if(d == maxd) //深度达到当前枚举个数
    {
        if(bb % aa) return false;//aa/bb必须是埃及分数
        v[d] = bb/aa;//保存分母
        if(better(d)) memcpy(ans,v,sizeof(LL)*(d+1));//更新最优解
        return true;//返回成功
    }
    bool ok = false;//用于返回本次递归的结果
    from = max((LL)from,get_first(aa,bb));//枚举的起点
    for(int i=from; ; i++)
    {
        if(bb * (maxd+1-d) <= i*aa) break;//剪枝：如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过aa/bb，则无解！ (maxd+1-d)/i <= aa/bb
        v[d] = i;//保存分母
        //计算aa/bb - 1/i，设结果为a2/b2
        LL b2 = bb*i;
        LL a2 = aa*i - bb;
        LL g = gcd(a2,b2);//用于约分
        if(dfs(d+1,i+1,a2/g,b2/g)) ok = true;//找到解返回成功
    }
    return ok;
}

void solve(int a,int b)
{
    int ok = 0;
    for(maxd = 1; ; maxd++) //枚举深度，即等式相加的个数
    {
        memset(ans,-1,sizeof(ans));
        if(dfs(0,get_first(a,b),a,b)) //递归找到时返回成功
        {
            ok = 1;
            break;//标记并退出枚举
        }
    }
    printf("Case %d: %d/%d=",++kcase,a,b);
    if(ok)
    {
        for(int i=0; i<maxd; i++) printf("1/%lld+",ans[i]);
        printf("1/%lld\n",ans[maxd]);
    }
    else printf("%d/%d\n",a,b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
        solve(a,b);
    return 0;
}

