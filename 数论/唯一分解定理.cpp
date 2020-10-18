/*
唯一分解定理又称为算数基本定理，基本内容是：
每个大于1的自然数，要么本身就是质数，要么可以写为2个或以上的质数的积，而且这些质因子按大小排列之后，写法仅有一种方式。
用另一种方法表示就是：
对于任何一个大于1的正整数,都存在一个标准的分解式:  N=p1^a1 * p2^a2*···*pn^an;（其中一系列an为指数，pn为质数）
此定理表明：任何一个大于 1 的正整数都可以表示为素数的积。

有这样几个式子：
设F(n)代表n的正因子的数量，则F(n)=(a1+1)*(a2+1)*(a3+1)*······*(an+1)；
设G(n)代表n的正因子的和，则G(n)=(1+p1^2+p1^3+...+p1^a1)*(1+p2^2+p2^3+...p2^a2)*....*
*/

/*
获得一个数正因子数量的代码：
primel [ ]是素数表

ll getfac(ll x)
{
    ll ans=1;
    for(int i=1;i<=cnt&&primel[i]<=x;i++)
    {
        ll sum=0;//当前质因数的幂指数
        while(x%primel[i]==0)//当是这个数的因子时
        {
            sum++;
            x/=primel[i];
        }
        ans*=(sum+1);//应用定理的结论
    }
    if(x>1)//当搜索不到的时候，如果这个数最后大于一，那么这个最后结果肯定是素数，并且指数是1
    ans*=2;
    return ans;
}

*/


/*
Sample Input
2
10 2
12 2
Sample Output
Case 1: 1
Case 2: 2
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+20;
int primel[maxn]; //素数表
bool isp[maxn];
int cnt;
void makel()//欧拉筛打印素数表
{
    cnt=0;
    memset(isp,true,sizeof(isp));
    for(int i=2; i<maxn; i++)
    {
        if(isp[i])
            primel[++cnt]=i;
        for(int j=1; j<=cnt; j++)
        {
            if(i*primel[j]>maxn)
                break;
            isp[i*primel[j]]=false;
            if(i%primel[j]==0)
                break;
        }
    }
}
ll getfac(ll x)//唯一分解定理
{
    ll ans=1;
    for(int i=1; i<=cnt&&primel[i]*primel[i]<=x; i++)
    {
        ll sum=0;
        while(x%primel[i]==0)
        {
            sum++;
            x/=primel[i];
        }
        ans*=(sum+1);
    }
    if(x>1)
        ans*=2;
    return ans;
}
int main()
{
    int t;
    int cas=0;
    ll a,b;
    cin>>t;
    makel();

//    for(int i=1;i<10;i++)
//        cout<<primel[i]<<" ";
//    cout<<endl;

    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a<b*b)//不可能分解为比b大的数相乘
        {
            printf("Case %d: 0\n",++cas);
            continue;
        }
        ll count=getfac(a)/2;//不能重复
        for(int i=1; i<b; i++) //去除小于b的因子
        {
            if(a%i==0)
                count--;
        }
        printf("Case %d: %lld\n",++cas,count);
    }
    return 0;
}



