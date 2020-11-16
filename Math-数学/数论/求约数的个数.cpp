/*
求约数的个数方法有很多
你可以使用 O(n) 的方法来遍历看是否为约数
更可以使用复杂度的算法从1~来判断个数
但是在这里我们给出的是一种实际运行速度稍快于的方法，大概节省2/3左右的时间
*/
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

const int maxn = 10000;
vector<int> primes;
int e[maxn];

bool is_prime(int n)
{
    int m = floor(sqrt(n) + 0.5);
    for(int a = 2; a <= m; a++)
        if(n % a == 0) return false;
    return true;
}

int main(void)
{
    for(int i = 2; i <= 10000; i++)
        if(is_prime(i)) primes.push_back(i);

    int n;
    cin>>n;


    for(int i = 0; i < primes.size(); i++)
    {
        while(n % primes[i] == 0) //可以被素数除通就算一个
        {
            n /= primes[i]; //被素数整除一个对应指数e[i]+=d
            e[i] += 1;      //同底数相乘相当于指数相加
        }
        if(n == 1) break; // 提前终止循环，节约时间
    }

    int res=1;
    for(int i=0; i<maxn; i++)
    {
        if(e[i])
        {
            res*=(e[i]+1);
        }
    }
    cout<<res<<endl;

    return 0;
}
