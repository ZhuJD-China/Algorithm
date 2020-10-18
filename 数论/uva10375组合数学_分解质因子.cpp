/*
��ѧ�⣺�������ѧ���ֽ������ӣ�

ɸ����������Ψһ�ֽⶨ���ú���ʵ�֣��Ӷ�������ֽ׳�
�������C(m,n)/C(s,t)���������������������Ҫע�����ݷ�Χ
һ�㴦�������ѧ����Ĳ��Ծ�����Լ�ֵ���Լ�֣��ܻ�����Ȼ����ܳ����ȳ�����Ҫȫ���������ٳ���

1.ת����ʽ
C(m,n) = [ m*(m-1)*(m-2)...(m-n+1) ] / [ n! ]

2.�������
C(p,q)/C(r,s) = [  p*(p-1)...(p-q+1) * s! ] / [ r*(r-1)....(r-s+1)*q! ]

(   p!*s!*(r-s)!  ) /(  q!*(p-q)!*r!  )

���ǲ���ȫ���������ٳ���������Ҳ����һ�߳�һ�߳������ȣ�

��ÿ�����ַֽ������ӣ������зֽ�����������ӣ��������ӣ���ĸ�ֽ�����������ӣ���������
���鿴���е������ӣ�����Ϊ����Ҫ�ˣ�����Ϊ����Ҫ����Ҫһ�߳�һ�߳������ֻᱬ
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

// ���Ի����n. d=0��ʾ�ˣ�d=-1��ʾ��
void add_integer(int n, int d)
{
    for(int i = 0; i < primes.size(); i++)
    {
        while(n % primes[i] == 0) //���Ա�������ͨ����һ��
        {
            n /= primes[i]; //����������һ����Ӧָ��e[i]+=d
            e[i] += d;
        }
        if(n == 1) break; // ��ǰ��ֹѭ������Լʱ��
    }
}

//��ʾ�ѽ������(n!)^d
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
