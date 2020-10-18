#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

//Eratosthenes筛法，“埃氏筛法”
const int maxn=101;
int prime[maxn],pNum=0;
bool p[maxn]= {false}; // i为素数，则p[i]为false

void Find_Prime()
{
    for(int i=2; i<maxn; i++)
    {
        if(p[i]==false)
            prime[pNum++] = i;
        for(int j=i+i; j<maxn; j+=i)
        {
            p[j]=true;
        }
    }
}

int main()
{
    Find_Prime();  //求解1~100以内的所有素数
    for(int i=0; i<pNum; i++)
    {
        printf("%d ",prime[i]);
    }
    return 0;
}

//复杂度太高，不建议使用
bool isPrime(int n)
{
    if(n<=1) return false; //特判
    int sqr = (int)sqrt(1.0*n); //根号
    for(int i=2; i<=sqr; i++)
    {
        if(n%i==0) return false; //n是i的倍数，则n不是素数
    }
    return false;  //n是素数
}
