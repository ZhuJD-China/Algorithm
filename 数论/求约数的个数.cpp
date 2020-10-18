/*
��Լ���ĸ��������кܶ�
�����ʹ�� O(n) �ķ������������Ƿ�ΪԼ��
������ʹ�ø��Ӷȵ��㷨��1~���жϸ���
�������������Ǹ�������һ��ʵ�������ٶ��Կ��ڵķ�������Ž�ʡ2/3���ҵ�ʱ��
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
        while(n % primes[i] == 0) //���Ա�������ͨ����һ��
        {
            n /= primes[i]; //����������һ����Ӧָ��e[i]+=d
            e[i] += 1;      //ͬ��������൱��ָ�����
        }
        if(n == 1) break; // ��ǰ��ֹѭ������Լʱ��
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
