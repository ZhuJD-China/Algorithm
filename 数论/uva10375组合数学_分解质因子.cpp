/*
数学题：（组合数学，分解质因子）

筛法求素数，唯一分解定理，用函数实现，从而求其各种阶乘
题意就是C(m,n)/C(s,t)，凡是组合数就提醒我们要注意数据范围
一般处理组合数学问题的策略就是能约分的先约分，能化简的先化简，能除的先除，不要全部乘起来再除掉

1.转化公式
C(m,n) = [ m*(m-1)*(m-2)...(m-n+1) ] / [ n! ]

2.两者相除
C(p,q)/C(r,s) = [  p*(p-1)...(p-q+1) * s! ] / [ r*(r-1)....(r-s+1)*q! ]

(   p!*s!*(r-s)!  ) /(  q!*(p-q)!*r!  )

但是不能全部乘起来再除（爆），也不能一边乘一边除（精度）

把每个数字分解质因子，分子中分解出来的质因子，个数增加，分母分解出来的质因子，个数减少
最后查看所有的质因子，个数为正的要乘，个数为负的要除，要一边乘一边除否则又会爆
*/

// UVa10375 Choose and divide
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 10000;
vector<int> primes;
int e[maxn];

// 乘以或除以n. d=0表示乘，d=-1表示除
void add_integer(int n, int d)
{
    for(int i = 0; i < primes.size(); i++)
    {
        while(n % primes[i] == 0) //可以被素数除通就算一个
        {
            n /= primes[i]; //被素数整除一个对应指数e[i]+=d
            e[i] += d;
        }
        if(n == 1) break; // 提前终止循环，节约时间
    }
}

//表示把结果乘以(n!)^d
void add_factorial(int n, int d)
{
    for(int i = 1; i <= n; i++)
        add_integer(i, d);
}

bool is_prime(int n)
{
    int m = floor(sqrt(n) + 0.5);
    for(int a = 2; a <= m; a++)
        if(n % a == 0) return false;
    return true;
}

int main()
{
    for(int i = 2; i <= 10000; i++)
        if(is_prime(i)) primes.push_back(i);
    int p, q, r, s;
    while(cin >> p >> q >> r >> s)
    {
        memset(e, 0, sizeof(e));
        add_factorial(p, 1);
        add_factorial(q, -1);
        add_factorial(p-q, -1);
        add_factorial(r, -1);
        add_factorial(s, 1);
        add_factorial(r-s, 1);
        double ans = 1;
        for(int i = 0; i < primes.size(); i++)
            ans *= pow(primes[i], e[i]);
        printf("%.5lf\n", ans);
    }
    return 0;
}
