#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_prime(vector<int> &prime, int n)
{
    if (n < 2)
        return;
    // 初始化一个布尔数组，用于记录每个数是否是素数
    vector<bool> is_prime(n + 1, true);

    for (int i = 2; i <= n; ++i)
    {
        // 如果是素数则将该数字加入到素数序列中
        if (is_prime[i])
            prime.push_back(i);
        // 从第一个素数开始，将它的倍数设置为非素数
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j)
        {
            is_prime[i * prime[j]] = false;
            /**
             * 如果 i%prime[j] == 0, 则 i = prime[j] * a
             * i * prime[j+1] = prime[j] * a * prime[j+1]
             * prime[j]已经筛过i * prime[j+1]这个数了，不需要用prime[j+1]再筛选一次
             **/
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{

    int n = 100;
    vector<int> prime;
    get_prime(prime, n);
    for_each(prime.begin(), prime.end(), [](int &n)
    {
        cout << n << " ";
    });
    return 0;
}
