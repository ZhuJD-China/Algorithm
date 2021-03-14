/*
Input
Input begins with an integer t ≤ 10,000, the number of test cases.
Each test case consists of three integers a, b, n where 0 ≤ a, b < 2^64
(a and b will not both be zero) and 1 ≤ n ≤ 1000.
Output
For each test case, output a single line containing the remainder of f(a^b) upon division by n.
Sample Input
3
1 1 2
2 3 1000
18446744073709551615 18446744073709551615 1000
Sample Output
1
21
250
*/
// UVa11582 Colossal Fibonacci Numbers!
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 1000 + 5;
typedef unsigned long long ULL;//unsigned long long（long long的二倍）

int f[maxn][maxn*6], period[maxn];

int pow_mod(ULL a, ULL b, int n) //分治法，幂取模 a^b mod n
{
    if(!b) return 1;
    int k = pow_mod(a, b/2, n);
    k = k * k % n;
    if(b % 2) k = k * a % n;
    return k;
}

int solve(ULL a, ULL b, int n)
{
    if(a == 0 || n == 1) return 0; // attention!
    int p = pow_mod(a % period[n], b, period[n]);
    return f[n][p];
}

int main()
{
    for(int n = 2; n <= 1000; n++)
    {
        f[n][0] = 0;
        f[n][1] = 1;
        for(int i = 2; ; i++)
        {
            f[n][i] = (f[n][i-1] + f[n][i-2]) % n;
            if(f[n][i-1] == 0 && f[n][i] == 1)
            {
                period[n] = i - 1; // 周期
                break;
            }
        }
    }

//    for(int i=2;i<20;i++){
//        for(int j=0;j<20;j++){
//            cout<<f[i][j]<<" ";
//        }cout<<endl;
//    }


    ULL a, b;
    int n, T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b >> n;
        cout << solve(a, b, n) << "\n";
    }
    return 0;
}


