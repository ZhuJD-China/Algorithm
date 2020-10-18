#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_prime(vector<int> &prime, int n)
{
    if (n < 2)
        return;
    // ��ʼ��һ���������飬���ڼ�¼ÿ�����Ƿ�������
    vector<bool> is_prime(n + 1, true);

    for (int i = 2; i <= n; ++i)
    {
        // ����������򽫸����ּ��뵽����������
        if (is_prime[i])
            prime.push_back(i);
        // �ӵ�һ��������ʼ�������ı�������Ϊ������
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j)
        {
            is_prime[i * prime[j]] = false;
            /**
             * ��� i%prime[j] == 0, �� i = prime[j] * a
             * i * prime[j+1] = prime[j] * a * prime[j+1]
             * prime[j]�Ѿ�ɸ��i * prime[j+1]������ˣ�����Ҫ��prime[j+1]��ɸѡһ��
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
